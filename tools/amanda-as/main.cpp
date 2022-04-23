/*
 * Copyright (C) 2022 Javier Marrero
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

/* Internal API */
#include <amanda-as/initialization.h>
#include <amanda-as/logging.h>

using namespace amanda;

int main(int argc, char** argv)
{
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

        // Create the assembly context
        std::list<core::String>& argumentList = commandLine->getArgumentList();
        if (argumentList.empty())
        {
            as::logger::fatal("no input files.");
        }
        else
        {
            bool verbose = false;
            if (commandLine->hasOption("verbose"))
            {
                verbose = true;
            }

            /* Create the necessary amount of contexts.
             * This will allow, in example, to assemble a certain number of
             * assembly files (all with the same options though) in only one
             * assembler program invocation.
             */
            std::vector<binutils::as::AssemblerDriver*> drivers;
            for (std::list<core::String>::const_iterator it = argumentList.begin(),
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

            // Supposedly, we have initialized the assembler drivers. We may
            // proceed to perform an assembler pass.
            unsigned i = 0;
            for (std::vector<binutils::as::AssemblerDriver*>::const_iterator
                 it = drivers.begin(); it != drivers.end(); ++it, ++i)
            {
                try
                {
                    if (!link)
                    {
                        // Create the output files.
                        if (!outputList[i]->open())
                        {
                            as::logger::fatal("unable to open '%s' for writing. %s.",
                                              outputList[i]->getPath().toCharArray(),
                                              outputList[i]->getLastErrorString().toCharArray());
                            
                        }
                        else
                        {
                            io::FileOutputStream* fstream = new io::FileOutputStream(outputList[i]);
                            io::ConsistentOutputStream* bstream = new io::ConsistentOutputStream(*fstream);

                            (*it)->addOutputHandler(bstream);
                        }
                    }

                    core::StrongReference<binutils::Module> module = (*it)->performAssemblerPass();
                    assert(!module.isNull() && "How come module is null?");

                    // Done!
                    if (verbose)
                        as::logger::info("assembly completed for module '%s'.",
                                         (*it)->getInputStreamName().toCharArray());
                }
                catch (core::Exception& ex)
                {
                    //TODO: Remove files on exception!! :0
                    as::logger::fatal("assembly failed.");
                }
            }

            // Clean up.
            for (std::deque<io::File*>::const_iterator it = outputList.begin(),
                 end = outputList.end(); it != end; ++it)
            {
                (*it)->release();
            }
        }
    }
    return EXIT_SUCCESS;
}
