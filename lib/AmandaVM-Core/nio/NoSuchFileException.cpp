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
 * File:   NoSuchFileException.cpp
 * Author: Javier Marrero
 * 
 * Created on May 22, 2022, 9:51 AM
 */

#include <amanda-vm/NIO/NoSuchFileException.h>

using namespace amanda;
using namespace nio;

NoSuchFileException::NoSuchFileException(const core::String& file)
:
IOException("No such file or directory"),
file(file)
{
}

NoSuchFileException::~NoSuchFileException() throw()
{
}

const core::String& NoSuchFileException::getFileName() const
{
    return file;
}
