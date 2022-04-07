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

#include <amanda-vm/vm-initialization.h>
#include <amanda-vm/vm-version.h>

using namespace amanda;
using namespace amanda::vm;

void amanda::vm::printFormattedHelpMessage(cli::Options& options)
{
    cli::HelpFormatter formatter;
    formatter.printHelp("amanda-vm [options] <module>",
                        "Where possible options may include:",
                        options,
                        "Report bugs to the discussion page of the Amanda project.",
                        false);
}

void amanda::vm::printVersionInformation()
{
    core::String buffer("Amanda Virtual Machine, version ");
    buffer.format("%s (Amanda Computing Platform, version %s)\n"
                  "Copyright (C) 2022 FreeLancer Development Team\n"
                  "License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>\n"
                  "This is free software; you are free to change and redistribute it.\n"
                  "There is NO WARRANTY; to the extent permitted by law.\n",
                  AMANDA_VM_FULLVERSION_STRING,
                  SDK_FULLVERSION_STRING);

    // Print the help string
    io::console().out.println(buffer);
}
