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

#include <amanda-vm/IO/Utility.h>

// C++
#include <stdint.h>

using namespace amanda;
using namespace amanda::io;

Endianness amanda::io::getMachineEndianness()
{
    return ConsistentInputStream::getMachineEndianness();
}

bool amanda::io::isMachineBigEndian()
{
    return ConsistentInputStream::isBigEndian();
}

bool amanda::io::isMachineLittleEndian()
{
    return ConsistentInputStream::isLittleEndian();
}

void amanda::io::swapEndianness(void* data, size_t size)
{
    char* buffer = (char*) data;
    for (size_t i = 0, j = (size - 1);
         i < (size / 2); ++i, --j)
    {
        char temporary = buffer[j];
        buffer[j] = buffer[i];
        buffer[i] = temporary;
    }
}
