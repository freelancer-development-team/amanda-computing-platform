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

/* 
 * File:   main.cpp
 * Author: Javier Marrero
 *
 * Created on February 27, 2022, 10:38 PM
 */

#include <AmandaSDK.h>
#include <amanda-vm/Option/package.hxx>

#include <cstdio>
#include <cstdlib>

using namespace amanda;

/*
 * This is the entry point for the Amanda Programming Language compiler
 * frontend.
 */
int main(int argc, char** argv)
{
    // THIS IS A TEST
    adt::Array<core::String> args = cli::makeArgumentsArray(argc, argv);
    for (size_t i = 0; i < args.length(); i++)
    {
        io::console().err.println("command-line %lu: %s", i, args[i].toCharArray());
    }

    cli::Options options;
    options.addOption(new cli::Option("f", "file", "The file to be processed", true, true));
    options.addOption(new cli::Option("h", "help", "Shows help", false, false));
    options.addOption(new cli::Option("v", "version", "Shows version information.", false, true));
    options.addOption(new cli::Option(cli::Option::NO_OPTION, "random", "This is a random description, that is long enough to be wrapped. I believe so at least. I don't know.", true, false));
    options.addOption(new cli::Option("n", cli::Option::NO_OPTION, "New file. Hope this description suits.", true, true));

    cli::DefaultParser parser(false, false);
    cli::CommandLine* cmd = parser.parse(options, args, false);
    std::list<const cli::Option*>::const_iterator iter;
    for (iter = cmd->getOptionsList().begin(); iter != cmd->getOptionsList().end(); ++iter)
    {
        io::console().out.println("Option: %s", const_cast<cli::Option*> ((*iter))->toString().toCharArray());
    }

    std::list<core::String>::const_iterator siter;
    for (siter = cmd->getArgumentList().begin(); siter != cmd->getArgumentList().end(); ++siter)
    {
        io::console().out.println("Argument: %s", (*siter).toCharArray());
    }

    if (cmd->hasOption('f'))
    {
        io::console().out.println("Got the -f parameter!");
    }
    else
    {
        io::console().out.println("Did not got the -f switch.");
    }
    if (cmd->hasOption("help"))
    {
        core::String header = "Do something.";
        core::String footer = "Report bugs to a random address.";

        cli::HelpFormatter formatter;
        formatter.printHelp("myapp", header, options, footer, true);
    }
    else
    {
        io::console().err.println("Did not got the -h parameter!");
    }

    delete cmd;

    // THIS IS A TEST
    return EXIT_SUCCESS;
}

