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
 * File:   Instruction.h
 * Author: Javier Marrero
 *
 * Created on April 6, 2022, 8:30 PM
 */

#ifndef _AMANDA_BINUTILS_AS_INSTRUCTION_H
#define _AMANDA_BINUTILS_AS_INSTRUCTION_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/Opcodes.h>
#include <amanda-vm/Binutils/VirtualMachineSpecs.h>

namespace amanda
{
namespace binutils
{
namespace as
{

/**
 * Instructions as, as their name indicates, the minimal execution unit of the
 * virtual machine. Assembler code emits instructions to corresponding execution
 * units named functions.
 */
class Instruction : public core::Object
{
    AMANDA_OBJECT(Instruction, core::Object)
public:

    Instruction(const vm::vm_byte_t opcode);

    const vm::vm_byte_t getOpcode() const;
    const sdk_ullong_t  getSize() const;
    
private:

    vm::vm_byte_t   opcode;
    sdk_ullong_t    size;
} ;

}
}
}

#endif /* INSTRUCTION_H */

