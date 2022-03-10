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
 * File:   MissingArgumentException.cpp
 * Author: Javier Marrero
 * 
 * Created on March 2, 2022, 9:04 PM
 */

#include <amanda-vm/Option/MissingArgumentException.h>

using namespace amanda::cli;

using amanda::core::String;

MissingArgumentException::MissingArgumentException(const Option* option)
:
ParseException(String("Missing argument for option: ").append(option->getKey()))
{
}

MissingArgumentException::MissingArgumentException(const core::String& message)
:
ParseException(message)
{
}

MissingArgumentException::~MissingArgumentException() throw()
{
}




