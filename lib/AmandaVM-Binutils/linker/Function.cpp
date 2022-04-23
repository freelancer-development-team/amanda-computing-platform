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
 * Created on April 17, 2022, 1:21 AM
 */

#include <amanda-vm/Binutils/Function.h>

using namespace amanda;
using namespace amanda::binutils;

Function::Function(const core::String& name)
:
Symbol(name)
{
    setType(Symbol::Type_Function);
    setBindClass(Symbol::Bind_Global);
}

Function::~Function()
{
    for (size_t i = 0; i < instructions.size(); ++i)
    {
        instructions[i]->release();
    }
}

void Function::emit(Instruction* insn)
{
    assert(insn != NULL && "Null pointer exception.");
    instructions.push_back(insn);

    // Grab a reference to the object. The reference is owned by the function.
    insn->grab();
}

size_t Function::getSize() const
{
    size_t result = 0;
    for (size_t i = 0; i < instructions.size(); ++i)
    {
        result += instructions[i]->getSize();
    }

    return result;
}




