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

#include <amanda-as/initialization.h>
#include <amanda-vm/Option/package.hxx>

#include <amanda-as/version.h>
#include <amanda-as/logging.h>

using namespace amanda;
using namespace amanda::as;

using amanda::cli::OptionBuilder;

cli::CommandLine* amanda::as::parseCommandLineOptions(cli::Options& options, adt::Array<core::String>& arguments)
{
    cli::CommandLine* commandLine = NULL;

    /* Add the options. Please, keep them sorted in alphabetical order. */
    options.addOption(OptionBuilder::build().withShortOption("h").withLongOption("help").withDescription("Shows this message and exits.").get());
    options.addOption(OptionBuilder::build().withShortOption("o").withLongOption("output").hasRequiredArgument(true).withDescription("Outputs executable code to the given file.").get());
    options.addOption(OptionBuilder::build().withLongOption("verbose").withDescription("Produces a more descriptive output.").get());
    options.addOption(OptionBuilder::build().withLongOption("version").withDescription("Shows the version information and exits.").get());

    /* Parse the command line. */
    try
    {
        core::StrongReference<cli::CommandLineParser> parser = new cli::DefaultParser();
        commandLine = parser->parse(options, arguments, false);
    }
    catch (cli::ParseException& ex)
    {
        printFormattedHelpMessage(options);
        logger::fatal(ex.getMessage());
    }
    /* Return the parsed command line. */
    return commandLine;
}

void amanda::as::printFormattedHelpMessage(cli::Options& options)
{
    cli::HelpFormatter formatter;
    formatter.printHelp("amanda-as [options...] <assembly-file>",
                        "Where possible options may include:",
                        options,
                        "Please, report bugs to the discussion page of the "
                        "Amanda Platform project, at:\n"
                        "\thttps://github.com/freelancer-development-team/amanda-computing-platform");
}

void amanda::as::printVersionInformation()
{
    io::console().out.println(
                              "amanda-as %s (AmandaSDK, version %s)\n"
                              "Copyright (C) 2022, FreeLancer Development Team\n"
                              "License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>\n"
                              "This is free software; you are free to change and redistribute it.\n"
                              "There is NO WARRANTY, to the extent permitted by law.",
                              AMANDA_AS_FULLVERSION_STRING, SDK_FULLVERSION_STRING);
}
