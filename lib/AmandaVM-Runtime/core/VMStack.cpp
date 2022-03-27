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
 * File:   VMStack.cpp
 * Author: Javier Marrero
 * 
 * Created on March 25, 2022, 12:44 PM
 */

#include <amanda-vm/Runtime/VMStack.h>

using namespace amanda;
using namespace amanda::vm;

VMStack::VMStack(unsigned limit)
:
capacity((limit > DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : limit),
limit(limit),
stackData(NULL),
stackPointer(0)
{
    stackData = (vm_byte_t*) calloc(capacity, sizeof(vm_byte_t));
    if (!stackData)
    {
        throw StackMemoryError(this);
    }
}

VMStack::~VMStack()
{
    if (stackData != NULL)
    {
        free(stackData);
    }
}

void VMStack::pop(void* data, size_t size)
{
    assert(data != NULL && "Popping to invalid address");
    if (stackPointer - size < 0)
    {
        throw StackMemoryError(this);
    }

    memcpy(data, &stackData[stackPointer], size);
    stackPointer -= size;   // pop
}

vm_byte_t VMStack::popByte()
{
    vm_byte_t data;
    pop<vm_byte_t>(&data);

    return data;
}

vm_word_t VMStack::popWord()
{
    vm_word_t data;
    pop<vm_word_t>(&data);

    return data;
}

vm_dword_t VMStack::popDoubleWord()
{
    vm_dword_t data;
    pop<vm_dword_t>(&data);

    return data;
}

vm_qword_t VMStack::popQuadWord()
{
    vm_qword_t data;
    pop<vm_qword_t>(&data);

    return data;
}

vm_address_t VMStack::popAddress()
{
    vm_address_t data;
    pop<vm_address_t>(&data);

    return data;
}

void VMStack::push(const void* data, size_t size)
{
    if (stackPointer + size > limit)
    {
        throw StackMemoryError(this);
    }
    else
    {
        if (stackPointer + size > capacity)
        {
            // Enlarge the stack by 2.
            size_t newCapacity = (capacity * 2 > limit) ? limit : (capacity * 2);
            stackData = (vm_byte_t*) realloc(stackData, newCapacity);

            if (!stackData)
            {
                throw StackMemoryError(this);
            }
        }

        memcpy(&stackData[stackPointer], data, size);
        stackPointer += size; // push
    }
}

void VMStack::push(vm_byte_t data)
{
    push<vm_byte_t>(data);
}

void VMStack::push(vm_word_t data)
{
    push<vm_word_t>(data);
}

void VMStack::push(vm_dword_t data)
{
    push<vm_dword_t>(data);
}

void VMStack::push(vm_qword_t data)
{
    push<vm_qword_t>(data);
}

void VMStack::pushAddress(vm_address_t data)
{
    push<vm_address_t>(data);
}

//============================= STACK ERROR ====================================

VMStack::StackMemoryError::StackMemoryError(const VMStack* stack)
:
core::Exception(core::String("stack operation exception in stack at <").format("%p>.", stack)),
stack(stack)
{
    /* This exceptions terminates the execution right-away. */
    abort();
}

VMStack::StackMemoryError::~StackMemoryError() throw ()
{
}

