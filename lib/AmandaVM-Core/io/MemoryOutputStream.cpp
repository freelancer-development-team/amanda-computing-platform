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
 * File:   MemoryOutputStream.cpp
 * Author: Javier Marrero
 * 
 * Created on April 9, 2022, 11:05 PM
 */

#include <amanda-vm/IO/MemoryOutputStream.h>

// C++
#include <cstdlib>

using namespace amanda;
using namespace amanda::io;

MemoryOutputStream::MemoryOutputStream(const void* buffer, bool deleteOnClose,
                                       bool usesNewOperator)
:
buffer((char*) buffer),
deleteOnClose(deleteOnClose),
pointer(0),
usesNewOperator(usesNewOperator)
{
}

MemoryOutputStream::~MemoryOutputStream()
{
    close();
}

void MemoryOutputStream::close() const
{
    if (deleteOnClose)
    {
        if (usesNewOperator)
        {
            delete[] buffer;
        }
        else
        {
            free(buffer);
        }
    }
}

void MemoryOutputStream::flush() const
{
    size_t size = pointer;
    pointer = 0;

    memset(buffer, 0, size);
}

bool MemoryOutputStream::isUsingNewOperator() const
{
    return usesNewOperator;
}

void MemoryOutputStream::write(const void* data, size_t size) const
{
    const char* temporary = (const char*) data;
    for (size_t i = 0; i < size; ++i)
    {
        buffer[pointer++] = temporary[i];
    }
}



