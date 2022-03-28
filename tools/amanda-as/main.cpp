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

/* C++ API */
#include <cstdio>
#include <cstdlib>

using namespace amanda;

int main(int argc, char** argv)
{
    /* Build the array of options */
    adt::Array<core::String> arguments = cli::makeArgumentsArray(argc, argv);

    /* Build the option object & perform the option parsing. */
    cli::Options options;
    core::StrongReference<cli::CommandLineParser> parser = new cli::DefaultParser();
    core::StrongReference<cli::CommandLine> commandLine;

    
    
    return EXIT_SUCCESS;
}
