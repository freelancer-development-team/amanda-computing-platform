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
 * File:   OptionParser.cpp
 * Author: Javier Marrero
 * 
 * Created on February 23, 2022, 12:39 PM
 */

#include <amanda-vm/Option/OptionParser.h>

#include <amanda-vm/IO/Path.h>

using amanda::options::OptionParser;

using amanda::core::String;
using amanda::io::Path;

OptionParser::OptionParser(const int argc, const char** argv, OptionList options)
:
argc(argc),
argv(argv),
options((OptionList*) &options)
{
}

OptionParser::~OptionParser()
{
}


