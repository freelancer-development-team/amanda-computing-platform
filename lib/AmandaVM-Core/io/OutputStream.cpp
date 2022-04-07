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
 * File:   Stream.cpp
 * Author: Javier Marrero
 * 
 * Created on March 1, 2022, 1:37 AM
 */

#include <amanda-vm/IO/OutputStream.h>

using amanda::io::OutputStream;

OutputStream::OutputStream()
{
}

OutputStream::~OutputStream()
{
}

void OutputStream::flush() const
{
    assert("This method is not implemented here!");
}

void OutputStream::write(const void* data, size_t size, size_t count) const
{
    const char* buffer = (const char*) data;
    for (size_t i = 0; i < count; ++i)
    {
        write(buffer, size);
        buffer += size;
    }
}

void OutputStream::write(const void* data, size_t size) const
{
    assert("This method is not implemented here!");
}

void OutputStream::write(const char* data) const
{
    write(data, strlen(data));
}


