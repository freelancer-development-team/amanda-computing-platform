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
 * File:   EndiannessConsistentStream.cpp
 * Author: Javier Marrero
 * 
 * Created on March 26, 2022, 11:25 PM
 */

#include <amanda-vm/IO/ConsistentInputStream.h>

#include <stdint.h>

using namespace amanda;
using namespace amanda::io;

ConsistentInputStream::Endianness ConsistentInputStream::getMachineEndianness()
{
    Endianness result = UNKNOWN_ENDIAN;

    union
    {
        uint32_t i;
        uint8_t c[4];
    } e = {0x01020304};

    switch (e.c[0])
    {
        case 0x01:
        {
            result = BIG_ENDIAN;
            break;
        }
        case 0x02:
        {
            result = BOTH_ENDIAN;
            break;
        }
        default:
        {
            result = LITTLE_ENDIAN;
            break;
        }
    }
    return result;
}

bool ConsistentInputStream::isBigEndian()
{
    return getMachineEndianness() == BIG_ENDIAN;
}

bool ConsistentInputStream::isLittleEndian()
{
    return getMachineEndianness() == LITTLE_ENDIAN;
}

ConsistentInputStream::ConsistentInputStream(InputStream& stream)
:
stream(stream)
{
}

ConsistentInputStream::~ConsistentInputStream()
{
}

void ConsistentInputStream::close() const
{
    stream.close();
}

void ConsistentInputStream::read(void* buffer, size_t size) const
{
    // Treat the buffer as a stream of bytes
    char* data = (char*) buffer;

    // Read the endianness
    stream.read(buffer, size);

    if (!isBigEndian())
    {
        // Swap endianness
        for (size_t i = 0, j = size - 1; i < size; ++i, --j)
        {
            char temporary = data[j];
            data[j] = data[i];
            data[i] = temporary;
        }
    }
}


