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

#include <amanda-c/OptionsParser.h>
#include <amanda-c/Messages.h>

#include <amanda-vm-c/sdk-version.h>
#include <amanda-c/c/version.h>

using namespace amanda;
using namespace amanda::core;
using namespace amanda::compiler;

cli::CommandLine* amanda::compiler::parseCommandLineArguments(adt::Array<core::String>& args, cli::Options* options)
{
    assert(options != NULL && "Null pointer dereference for 'Options' object.");
    cli::CommandLine* cmdline = NULL; // The return value

    /* Add the program options:
     * 
     * Please, keep this list sorted in alphabetical order, in order to prevent
     * cluttering. This is an already pretty much dense code. Try to keep it
     * organized.
     * 
     */
    options->addOption(cli::OptionBuilder::build().withShortOption("c").withDescription("Compile and assemble, but do not link.").get());
    options->addOption(cli::OptionBuilder::build().withLongOption("dump-version").withDescription("Dump the version string (does not exits the program).").get());
    options->addOption(cli::OptionBuilder::build().withShortOption("h").withLongOption("help").withDescription("Shows this message and exits.").get());
    options->addOption(cli::OptionBuilder::build().withShortOption("o").withLongOption("output").hasRequiredArgument(true).withDescription("Redirects output to the specified file.").get());
    options->addOption(cli::OptionBuilder::build().withShortOption("S").withDescription("Compile only, do not assemble or link.").get());
    options->addOption(cli::OptionBuilder::build().withLongOption("statistics").withDescription("Shows the final compilation statistics.").get());
    options->addOption(cli::OptionBuilder::build().withLongOption("verbose").withDescription("Produces a much more complete description of the compilation process.").get());
    options->addOption(cli::OptionBuilder::build().withLongOption("version").withDescription("Outputs version information and exits.").get());
    options->addOption(cli::OptionBuilder::build().withShortOption("W").hasRequiredArgument(true).withDescription("Sets the default warning level (none, some, all).").get());

    /* Parse the command line arguments. */
    try
    {
        StrongReference<cli::CommandLineParser> parser = new cli::DefaultParser();
        assert(!parser.isNull() && "Could not create command line parser object.");

        cmdline = parser->parse(*(options), args, false);
    }
    catch (cli::ParseException& ex)
    {
        log::fatal(ex.getMessage());
    }
    return cmdline;
}

void amanda::compiler::displayHelpMessage(cli::Options& options)
{
    String header = "Where possible options may include:";
    String footer = "Please, report bugs to the discussions page of the Amanda project:\n"
            "\thttps://github.com/freelancer-development-team/amanda-computing-platform \n";

    StrongReference<cli::HelpFormatter> formatter = new cli::HelpFormatter();
    formatter->printHelp("amanda-c <input-file>", header, options, footer, true);
}

void amanda::compiler::displayVersionInformation()
{
    io::console().out.println("amanda-c (AmandaSDK %s) %s\n"
                              "Copyright (C) 2022 FreeLancer Development Team.\n"
                              "License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>\n"
                              "This is free software: you are free to change and redistribute it.\n"
                              "There is NO WARRANTY, to the extent permitted by law.",
                              SDK_FULLVERSION_STRING, AMANDA_C_FULLVERSION_STRING);
}
