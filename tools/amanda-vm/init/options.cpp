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
 * File:   vm-initialization.cpp
 * Author: Javier Marrero
 * 
 * Created on March 26, 2022, 3:52 PM
 */

#include <amanda-vm/vm-initialization.h>

using namespace amanda;
using namespace amanda::vm;

cli::CommandLine* amanda::vm::parseCommandLineArguments(adt::Array<core::String>& args, cli::Options& options)
{
    cli::CommandLine* cmdLine = NULL;

    options.addOption(cli::OptionBuilder::build().withShortOption("h").withLongOption("help").withDescription("Shows this message and exits.").get());
    options.addOption(cli::OptionBuilder::build().withLongOption("libraries-path").withShortOption("L").withDescription("A ';' separated list of directories or .ax files to load at boot time.").get());
    options.addOption(cli::OptionBuilder::build().withLongOption("show-version").withDescription("Shows the version information and continues.").get());
    options.addOption(cli::OptionBuilder::build().withLongOption("version").withDescription("Shows the version information and exits.").get());

    try
    {
        core::StrongReference<cli::CommandLineParser> parser = new cli::DefaultParser();
        assert(!parser.isNull() && "Could not create command line parser object.");

        cmdLine = parser->parse(options, args, false);
    }
    catch (cli::ParseException& ex)
    {
        printFormattedHelpMessage(options);
        io::console().out.println("amanda-vm: \033[31;1merror\033[0m: %s", ex.toString().toCharArray());
        abort();
    }
    return cmdLine;
}
