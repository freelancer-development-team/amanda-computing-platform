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
 * File:   ConsistentOutputStream.cpp
 * Author: Javier Marrero
 * 
 * Created on March 27, 2022, 12:25 AM
 */

#include <amanda-vm/IO/ConsistentOutputStream.h>
#include <amanda-vm/IO/ConsistentInputStream.h>

using namespace amanda;
using namespace amanda::io;

ConsistentOutputStream::ConsistentOutputStream(const OutputStream& stream)
:
stream(stream)
{
}

ConsistentOutputStream::~ConsistentOutputStream()
{
}

void ConsistentOutputStream::close() const
{
    stream.close();
}

void ConsistentOutputStream::write(const char* data) const
{
    write(data, strlen(data));
}

void ConsistentOutputStream::write(const void* data, size_t size) const
{
    char* temporary = (char*) data;
    char buffer[size] = {0};
    if (!ConsistentInputStream::isBigEndian())
    {
        for (size_t i = 0, j = size - 1; i < size; ++i, --j)
        {
            buffer[i] = temporary[j];
            buffer[j] = temporary[i];
        }
    }
    stream.write(buffer, size);
}




