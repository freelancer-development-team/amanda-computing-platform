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
 * File:   Operand.cpp
 * Author: Javier Marrero
 * 
 * Created on April 23, 2022, 7:36 PM
 */

#include <amanda-vm/Binutils/Operand.h>
#include <amanda-vm/Binutils/Instruction.h>

// C++
#include <cstring>

using namespace amanda;
using namespace amanda::binutils;

unsigned Operand::getOperandSizeForInteger(sdk_ullong_t value)
{
    unsigned result = 0;
    if (value > 0xfffffffful)
    {
        result = VM_QWORD_SIZE;
    }
    else if (value > 0xffffu)
    {
        result = VM_DWORD_SIZE;
    }
    else if (value > 0xffu)
    {
        result = VM_WORD_SIZE;
    }
    else
    {
        result = VM_BYTE_SIZE;
    }

    // Return the result
    return result;
}

Operand::Operand(const core::String& symbolicName)
{
    // Default uninitialized
    initializeConsistentState();

    // Initialize object state
    this->symbolicName = symbolicName;
    this->type = SYMBOL;
}

Operand::Operand(const sdk_ullong_t value, const size_t size)
{
    // Default uninitialized
    initializeConsistentState();

    // Default object state
    this->size = size;
    this->resolved = true;
    
    memcpy(this->value, &value, size);
}

Operand::Operand(const sdk_ullong_t value)
{
    initializeConsistentState();

    // Set the object state
    this->size = getOperandSizeForInteger(value);
    this->resolved = true;
    
    memcpy(this->value, &value, size);
}

size_t Operand::getSize() const
{
    return size;
}

const core::String& Operand::getSymbolicName() const
{
    return symbolicName;
}

const void* Operand::getValue() const
{
    return (const void*) value;
}

void Operand::initializeConsistentState()
{
    // Initialize the fields of this class.
    resolved = false;
    size = 0;
    symbolicName = core::String::EMPTY;
    memset(value, 0, VM_QWORD_SIZE);    // Make the value field a zero
}

bool Operand::isResolved() const
{
    return resolved;
}

bool Operand::isSymbol() const
{
    return type == SYMBOL;
}

void Operand::resolve(const sdk_ullong_t value, const size_t size)
{
    this->size = size;
    this->resolved = true;

    memcpy(this->value, &value, size);
}

void Operand::setSize(size_t size)
{
    this->size = size;
}

