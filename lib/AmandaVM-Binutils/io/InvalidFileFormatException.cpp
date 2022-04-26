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
 * File:   InvalidFileFormatException.cpp
 * Author: Javier Marrero
 * 
 * Created on April 17, 2022, 2:53 PM
 */

#include <amanda-vm/Binutils/InvalidFileFormatException.h>

using namespace amanda;
using namespace amanda::binutils;

InvalidFileFormatException::InvalidFileFormatException(const core::String& message, const core::String& fileName)
:
core::Exception(message),
fileName(fileName)
{
}

InvalidFileFormatException::~InvalidFileFormatException() throw()
{
}

const core::String& InvalidFileFormatException::getFileName() const
{
    return fileName;
}

