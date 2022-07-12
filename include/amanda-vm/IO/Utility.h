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
 * File:   Utility.h
 * Author: Javier Marrero
 *
 * Created on June 21, 2022, 8:20 PM
 */

#ifndef AMANDA_IO_UTILITY_H
#define AMANDA_IO_UTILITY_H

#include <amanda-vm/IO/ConsistentInputStream.h>

namespace amanda
{
namespace io
{

typedef ConsistentInputStream::Endianness Endianness;

Endianness  getMachineEndianness();
bool        isMachineBigEndian();
bool        isMachineLittleEndian();
void        swapEndianness(void* data, size_t size);

}
}

#endif /* UTILITY_H */

