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
 * File:   Function.cpp
 * Author: Javier Marrero
 * 
 * Created on April 6, 2022, 8:19 PM
 */

#include <amanda-vm/Binutils/Linker/Function.h>

using namespace amanda;
using namespace amanda::binutils::ld;

Function::Function(const core::String& name)
:
super(name)
{
}

Function::~Function()
{
    for (std::vector<as::Instruction*>::iterator it = instructions.begin(),
            end = instructions.end(); it != end; ++it)
    {
        (*it)->release();
    }
}

sdk_ullong_t Function::computeSize() const
{
    for (std::vector<as::Instruction*>::const_iterator it = instructions.begin(),
         end = instructions.end(); it != end; ++it)
    {
        size += (*it)->getSize();
    }
    return size;
}

void Function::emit(as::Instruction* instruction)
{
    assert(instruction != NULL && "Expected non-null pointer for an instruction.");
    instruction->grab();
    instructions.push_back(instruction);
}

void Function::marshall(io::OutputStream& stream)
{
    for (sdk_ullong_t i = 0; i < instructions.size(); ++i)
    {
        as::Instruction* insn = instructions[i];
        assert(insn != NULL && "Null pointer exception.");

        vm::vm_byte_t opcode = insn->getOpcode();
        stream.write(&opcode, sizeof(vm::vm_byte_t));
    }
}
