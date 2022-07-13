/*
 * Copyright (C) 2022 FreeLancer Development Team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Amanda API */
#include <AmandaSDK.h>
#include <amanda-vm/Option/package.hxx>
#include <amanda-vm/Binutils/package.hxx>

/* C++ API */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <deque>
#include <streambuf>

/* Internal API */
#include <amanda-as/initialization.h>
#include <amanda-as/logging.h>

using namespace amanda;

int main(int argc, char** argv)
{
    /* Set locale */
    std::setlocale(LC_ALL, "");
    try
    {
        std::locale utf8_locale("en_US.UTF-8");
        std::locale::global(utf8_locale);
    }
    catch (std::exception& ex)
    { /* Its a no-op */ }

    /* The logger formatter. */
    logging::GNUFormatter formatter("amanda-as", true);
    binutils::setFormatterForPackage(formatter);

    /* Build the array of options */
    adt::Array<core::String> arguments = cli::makeArgumentsArray(argc, argv);

    /* Build the option object & perform the option parsing. */
    cli::Options options;
    core::StrongReference<cli::CommandLine> commandLine = amanda::as::parseCommandLineOptions(options, arguments);
    assert(!commandLine.isNull() && "Null pointer exception");

    // Status flag
    bool link = true;
    bool verbose = false;

    if (commandLine->hasOption('h'))
    {
        amanda::as::printFormattedHelpMessage(options);
    }
    else if (commandLine->hasOption("--version"))
    {
        amanda::as::printVersionInformation();
    }
    else
    {
        // Parse the options & set the status flags
        if (commandLine->hasOption('S'))
        {
            link = false;
        }
        if (commandLine->hasOption("verbose"))
        {
            verbose = true;
        }

        // Create the assembly context
        std::vector<core::String>& argumentList = commandLine->getArgumentList();
        if (argumentList.empty())
        {
            as::logger::fatal("no input files.");
        }
        else
        {

            /* Create the necessary amount of contexts.
             * This will allow, in example, to assemble a certain number of
             * assembly files (all with the same options though) in only one
             * assembler program invocation.
             */
            std::vector<binutils::as::AssemblerDriver*> drivers;
            for (std::vector<core::String>::const_iterator it = argumentList.begin(),
                 end = argumentList.end(); it != end; ++it)
            {
                core::StrongReference<io::File> file = new io::File(*it, io::File::READ | io::File::BINARY);
                if (!file->open() || !file->canRead())
                {
                    as::logger::fatal("unable to open file '%s' for reading.",
                                      (*it).toCharArray());
                }
                else
                {
                    if (verbose)
                    {
                        as::logger::info("opened file '%s' for reading.",
                                         (*it).toCharArray());
                    }

                    // Push a new driver object into the list
                    core::String input = binutils::buildAssemblerInputFromFile(file);
                    binutils::AssemblerInputStream instream = binutils::associateInputStream(file->getPath(), input);

                    drivers.push_back(new amanda::binutils::as::AssemblerDriver(instream));
                }
            }

            // Put the output files in a deque
            std::deque<io::File*> outputList;
            if (commandLine->hasOption('o'))
            {
                const adt::Array<core::String>& values = commandLine->getOptionValues('o');

                unsigned i;
                for (i = 0; i < values.length() && i < drivers.size(); ++i)
                {
                    const core::String& fileName = values[i];
                    outputList.push_back(new io::File(fileName, io::File::WRITE | io::File::CREATE | io::File::BINARY));
                    outputList.back()->grab();  // Grab a reference to the file

                    if (verbose)
                    {
                        as::logger::info("added '%s' to the output queue.",
                                         fileName.toCharArray());
                    }
                }
            }

            // Assemble all the files & link the modules where necessary.
            std::vector<binutils::Module*> modules;
            modules.reserve(drivers.size());
            for (unsigned moduleIndex = 0; moduleIndex < drivers.size(); ++moduleIndex)
            {
                modules.push_back(drivers.at(moduleIndex)->performAssemblerPass());
            }

            // Modules are assembled.
            // Now, if the link flag is set, we merge & produce the executable
            // or libraries defined by the output list.
            // If the link flag is not set, we produce output files.
            if (link == false)
            {
                if (verbose)
                {
                    as::logger::info("producing object files.");
                }
                if (modules.size() > outputList.size())
                {
                    as::logger::warning("passed %lu modules and specified %lu output files. Default naming is used.",
                                        modules.size(), outputList.size());

                    ///TODO: Add default file names & files
                }

                for (unsigned fileIndex = 0; fileIndex < modules.size(); ++fileIndex)
                {
                    // Create the reference to the file
                    core::StrongReference<io::File> output = outputList.at(fileIndex);
                    if (output->open() == false)
                    {
                        as::logger::error("unable to open '%s' for writing. %s.",
                                          output->getPath().toCharArray(),
                                          output->getLastErrorString().toCharArray());
                    }
                    else
                    {
                        // Create the output stream
                        io::FileOutputStream* ostream = new io::FileOutputStream(output.get());

                        // Serialize the output
                        core::StrongReference<binutils::Module> module = modules.at(fileIndex);
                        module->linkLocalSymbols();
                        module->addSerializationHandler(new binutils::Serializer(ostream));
                        module->marshall();
                    }
                }
            }
            else
            {
                if (outputList.size() > 1)
                {
                    as::logger::warning("More than 1 output file specified (ignoring the rest).");
                }

                core::StrongReference<io::File> output = outputList.front();
                if (output->open() == false)
                {
                    as::logger::fatal("unable to open '%s' for writing. %s.",
                                      output->getPath().toCharArray(),
                                      output->getLastErrorString().toCharArray());
                }
                else
                {
                    // Create the file output stream.
                    core::StrongReference<io::FileOutputStream> ostream = new io::FileOutputStream(output);

                    // Create the linker driver
                    core::StrongReference<binutils::Module> master = modules.front();
                    core::StrongReference<binutils::LinkerDriver> linker = new binutils::LinkerDriver(master);
                    linker->addOutputStream(ostream);

                    // Add all the object files
                    if (modules.size() > 1)
                    {
                        for (unsigned moduleIndex = 1; moduleIndex < modules.size(); ++moduleIndex)
                        {
                            linker->addObjectFile(modules.at(moduleIndex));
                        }
                    }

                    // Link & export
                    linker->link();
                    linker->dump();
                }
            }

            // Clean-up
            for (std::deque<io::File*>::const_iterator it = outputList.begin(),
                 end = outputList.end(); it != end; ++it)
            {
                (*it)->release();
            }
        }
    }
    return EXIT_SUCCESS;
}
