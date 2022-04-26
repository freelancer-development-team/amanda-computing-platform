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

#include "interface.h"
#include <amanda-vm-c/sdk-version.h>

using namespace amanda;
using namespace amanda::rdx;

using cli::OptionBuilder;

void amanda::rdx::buildOptionsObject(cli::Options& options)
{
    // Add the options.
    // Try to keep the list alphabetically sorted.
    options.addOption(OptionBuilder::build().withShortOption("h").withLongOption("help").withDescription("Shows this message and exits.").get());
    options.addOption(OptionBuilder::build().withLongOption("version").withDescription("Shows the program's version information & exits.").get());
}

void amanda::rdx::displayFormattedHelp(const cli::Options& options)
{
    cli::HelpFormatter formatter;
    formatter.printHelp("amanda-rex <option(s)> <file(s)>",
                        "Where possible options may include:",
                        options,
                        "This program is free software and is part of the Amanda Computing Platform project. "
                        "Please, report bugs to the Amanda issues page at");
}

void amanda::rdx::displayVersionInfo()
{
    io::console().out.println("Amanda ReadExecutable (AmandaSDK " SDK_FULLVERSION_STRING ")\n"
                              "Copyright (C) 2022, FreeLancer Development Team\n"
                              "This program is FREE SOFWARE; you may redistribute under the terms of\n"
                              "the GNU General Public License version 3 or (at your option) any later version.\n"
                              "This program has absolutely NO WARRANTY, as permitted by law.\n");
}
