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
    cli::Options options;
    options.addOption(new cli::Option("f", "file", "The file to be processed", true, true));
    options.addOption(new cli::Option("h", "help", "Shows help", false, false));

    core::String header = "Do something.";
    core::String footer = "Report bugs down your ass.";

    cli::HelpFormatter formatter;
    formatter.printHelp(80, "myapp", header, options, footer, true);

    return EXIT_SUCCESS;
}

