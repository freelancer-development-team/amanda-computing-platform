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
typedef uint8_t     vm_byte_t;
typedef uint16_t    vm_word_t;
typedef uint32_t    vm_dword_t;
typedef uint64_t    vm_qword_t;

#define VM_BYTE_SIZE    sizeof(amanda::vm::vm_byte_t)
#define VM_WORD_SIZE    sizeof(amanda::vm::vm_word_t)
#define VM_DWORD_SIZE   sizeof(amanda::vm::vm_dword_t)
#define VM_QWORD_SIZE   sizeof(amanda::vm::vm_qword_t)

// Floating point types
#include <amanda-vm/Binutils/vm-ieee754.h>

// Addresses & pointers
typedef uint64_t    vm_pointer_t;
typedef uint64_t    vm_size_t;
typedef uint64_t    vm_index_t;
typedef uint64_t    vm_address_t;

#define VM_ADDRESS_SIZE sizeof(amanda::vm::vm_address_t)

// Runtime types
typedef void*       vm_memory_t;
typedef const void* vm_readonly_memory_t;

}
}

#endif /* VIRTUALMACHINESPECS_H */

