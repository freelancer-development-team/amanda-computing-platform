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
 * File:   EndiannessConsistentStream.cpp
 * Author: Javier Marrero
 * 
 * Created on March 26, 2022, 11:25 PM
 */

#include <amanda-vm/IO/ConsistentInputStream.h>
#include <amanda-vm/Binutils/vm-types.h>

// C
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

ConsistentInputStream::ConsistentInputStream(InputStream& stream, Endianness endianness)
:
endianness(endianness),
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

ConsistentInputStream::Endianness ConsistentInputStream::getEndianness() const
{
    return endianness;
}

void ConsistentInputStream::read(void* buffer, size_t size) const
{
    read(buffer, size, 1);
}

void ConsistentInputStream::read(void* buffer, size_t size, size_t count) const
{
    // Read the data and place it in the buffer
    stream.read(buffer, sizeof (char), size * count);

    // Now do the endianness swap if necessary.
    // This is determined by the following.
    // If we are reading data from different endianness than the local machine
    // we must do the swap.
    for (unsigned k = 0; k < count && (size != 1); ++k)
    {
        if (endianness != getMachineEndianness())
        {
            // Treat the buffer as a stream of chars
            char* data = (char*) buffer + (k * size);

            switch (size)
            {
                case VM_WORD_SIZE:
                {
                    vm::vm_word_t* swapped = (vm::vm_word_t*) data;
                    *swapped = (*swapped >> 8) | (*swapped << 8);
                    break;
                }
                case VM_DWORD_SIZE:
                {
                    vm::vm_dword_t* swapped = (vm::vm_dword_t*) data;
                    *swapped = ((*swapped >> 24) && 0xFF)
                            | ((*swapped << 8) & 0xFF0000)
                            | ((*swapped >> 8) & 0xFF00)
                            | ((*swapped << 24 & 0xFF000000));
                    break;
                }
                case VM_QWORD_SIZE:
                {
                    vm::vm_qword_t* swapped = (vm::vm_qword_t*) data;
                    *swapped = ((*swapped << 8) & 0xFF00FF00FF00FF00ull)
                            | ((*swapped >> 8) & 0x00FF00FF00FF00FFull);
                    *swapped = ((*swapped << 16) & 0xFFFF0000FFFF0000ull)
                            | ((*swapped >> 16) & 0x0000FFFF0000FFFFull);
                    *swapped = (*swapped << 32) | (*swapped >> 32);
                    break;
                }
                default:
                {
                    for (size_t i = 0, j = (size - 1);
                         i < (size / 2); ++i, --j)
                    {
                        char temporary = data[j];
                        data[j] = data[i];
                        data[i] = temporary;
                    }
                    break;
                }
            }
        }
    }
}

void ConsistentInputStream::reset() const
{
    stream.reset();
}

void ConsistentInputStream::seek(uint64_t offset) const
{
    stream.seek(offset);
}

uint64_t ConsistentInputStream::tell() const
{
    return stream.tell();
}

InputStream& ConsistentInputStream::getWrappedStream() const
{
    return stream;
}
