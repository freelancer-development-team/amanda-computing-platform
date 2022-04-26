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

/* 
 * File:   main.cpp
 * Author: Javier Marrero
 *
 * Created on April 17, 2022, 12:24 PM
 */

// Amanda
#include <AmandaSDK.h>
#include <amanda-vm/Option/package.hxx>

// C++ & proper
#include <cstdlib>
#include "interface.h"

using namespace amanda;

/*
 * Main function... like every main function... Are you seriously reading this?
 * I mean... this doc is useless. This is a main function, just like every other
 * main function on earth.
 * 
 */
int main(int argc, char** argv)
{
    // Create the parent logging object & set the format
    core::StrongReference<logging::Logger> logger = logging::Logger::getLogger("amanda.read-executable");
    logger->setUseParentHandlers(false);

    logging::ConsoleHandler* handler = new logging::ConsoleHandler(new logging::GNUFormatter("amanda-rex", true));
    logger->addHandler(*handler);

    // Create the options & parse the arguments
    cli::Options options;
    rdx::buildOptionsObject(options);

    const adt::Array<core::String>& arguments = cli::makeArgumentsArray(argc, argv);
    if (arguments.length() < 1)
    {
        rdx::displayFormattedHelp(options);
        logger->fatal("no input file specified. Run with --help or -h arguments for more information.");
    }
    else
    {
        try
        {
            core::StrongReference<cli::CommandLineParser> parser = new cli::DefaultParser(true, true);
            core::StrongReference<cli::CommandLine> commandLine = parser->parse(options, arguments, true);

            // Start checking for options
            if (commandLine->hasOption('h'))
            {
                rdx::displayFormattedHelp(options);
            }
            else if (commandLine->hasOption("version"))
            {
                rdx::displayVersionInfo();
            }
            else
            {
                const std::list<core::String>& filenames = commandLine->getArgumentList();
                for (std::list<core::String>::const_iterator it = filenames.begin(),
                     end = filenames.end(); it != end; ++it)
                {
                    core::String filename = (*it);
                    rdx::displayObjectFileInformation(filename);
                }
            }
        }
        catch (cli::UnrecognizedOptionException& ex)
        {
            logger->fatal("unrecognized option: %s", ex.getOption().toCharArray());
        }
    }
    return EXIT_SUCCESS;
}

