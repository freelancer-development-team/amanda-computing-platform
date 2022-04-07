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
#include <amanda-vm/Binutils/Assembler/AssemblerContext.h>

/* C++ API */
#include <cstdio>
#include <cstdlib>
#include <vector>

/* Internal API */
#include <amanda-as/initialization.h>
#include <amanda-as/logging.h>

using namespace amanda;

int main(int argc, char** argv)
{
    /* Build the array of options */
    adt::Array<core::String> arguments = cli::makeArgumentsArray(argc, argv);

    /* Build the option object & perform the option parsing. */
    cli::Options options;
    core::StrongReference<cli::CommandLine> commandLine = amanda::as::parseCommandLineOptions(options, arguments);
    assert(!commandLine.isNull() && "Null pointer exception");

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
            std::vector<binutils::as::AssemblerContext*> contexts;
            contexts.reserve(argumentList.size());
            for (unsigned i = 0; i < argumentList.size(); ++i)
            {
                contexts.push_back(new binutils::as::AssemblerContext());
                contexts[i]->grab(); // Grab a reference to the newly created object.

                core::String inputFileName = adt::atListPosition(argumentList, i);
                io::File* input = new io::File(inputFileName, io::File::READ | io::File::BINARY);
                if (!input->open())
                {
                    as::logger::fatal("unable to open file '%s'. %s.",
                                      input->getPath().toCharArray(),
                                      input->getLastErrorString().toCharArray());
                }

                contexts[i]->setInputFile(input);
                contexts[i]->setVerbose(verbose);

                if (verbose)
                {
                    as::logger::info("added '%s' to the list of input files.",
                                     input->getPath().toCharArray());
                }
            }


            if (commandLine->hasOption('o'))
            {
                adt::Array<core::String> values = commandLine->getOptionValues('o');
                for (unsigned i = 0; i < contexts.size(); ++i)
                {
                    binutils::as::AssemblerContext* context = contexts[i];
                    core::String fileName = (i < values.length())
                            ? values[i]
                            : context->getInputFile()->getPath();
                    ;
                    fileName.replace(".ams", ".ax", false);

                    if (verbose)
                    {
                        as::logger::info("added '%s' to the list of output files.", fileName.toCharArray());
                    }
                    context->setOutputFile(new io::File(fileName, io::File::CREATE | io::File::WRITE | io::File::READ | io::File::BINARY));
                }
            }

            /* Perform the assembly pass. */
            for (unsigned i = 0; i < contexts.size(); ++i)
            {
                //TODO: Complete this
                contexts[i]->performAssemblyPass();
            }

            // Release a reference to all the hold contexts.
            for (std::vector<binutils::as::AssemblerContext*>::iterator it = contexts.begin(),
                 end = contexts.end(); it != end; ++it)
            {
                (*it)->release();
            }
        }
    }
    return EXIT_SUCCESS;
}
