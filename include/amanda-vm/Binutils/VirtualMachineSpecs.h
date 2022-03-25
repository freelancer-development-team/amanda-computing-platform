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
 * File:   VirtualMachineSpecs.h
 * Author: Javier Marrero
 *
 * Created on March 24, 2022, 9:11 PM
 */

#ifndef VIRTUALMACHINESPECS_H
#define VIRTUALMACHINESPECS_H

#include <stdint.h>

namespace amanda
{
namespace vm
{

// Integral types
typedef uint8_t     VM_Byte;
typedef uint16_t    VM_Word;
typedef uint32_t    VM_DWord;
typedef uint64_t    VM_QWord;

// Floating point types

// Addresses & pointers
typedef uint64_t    VM_Address;

}
}

#endif /* VIRTUALMACHINESPECS_H */

