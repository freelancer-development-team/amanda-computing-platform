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
 * File:   Instruction.cpp
 * Author: Javier Marrero
 * 
 * Created on April 6, 2022, 8:30 PM
 */

#include <amanda-vm/Binutils/Assembler/Instruction.h>

using namespace amanda;
using namespace amanda::binutils::as;

Instruction::Instruction(const vm::vm_byte_t opcode)
:
opcode(opcode),
size(sizeof(vm::vm_byte_t))
{
}

const vm::vm_byte_t Instruction::getOpcode() const
{
    return opcode;
}

const sdk_ullong_t Instruction::getSize() const
{
    return size;
}



