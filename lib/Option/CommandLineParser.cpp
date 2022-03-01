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
 * File:   CommandLineParser.cpp
 * Author: Javier Marrero
 * 
 * Created on March 1, 2022, 1:43 PM
 */

#include <amanda-vm/Option/CommandLineParser.h>

using namespace amanda;

using amanda::cli::CommandLineParser;
using amanda::core::String;

adt::Array<String> amanda::cli::makeArgumentsArray(int argc, char* argv[])
{
    adt::Array<String> array(argc - 1);
    for (int i = 1; i < argc; i++)
    {
        array[i] = argv[i];
    }

    return array;
}
