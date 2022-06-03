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
 * File:   Stack.cpp
 * Author: Javier Marrero
 * 
 * Created on May 31, 2022, 5:14 PM
 */

#include <amanda-vm/Runtime/Stack.h>

// C++
#include <cstdlib>
#include <cstring>

using namespace amanda;
using namespace amanda::vm;

Stack::Stack()
:
basePointer(0),
stackArea((vm_byte_t*) std::malloc(0x1000)),
stackPointer(0),
stackSize(0x1000)
{
    assert(stackArea != NULL && "Null pointer exception");
}

Stack::~Stack()
{
    std::free(stackArea);
}

bool Stack::isEmpty() const
{
    return stackPointer == 0;
}

void Stack::pop(vm_byte_t* buffer, vm_size_t size)
{
    assert(stackPointer > 0 && "Invalid pop operation on empty stack.");
    std::memcpy(buffer, (const void*) (stackArea + stackPointer), size);

    // Reduce the stack pointer
    stackPointer -= size;
}

void Stack::push(const vm_byte_t* data, vm_size_t size)
{
    if (stackPointer + size > size)
    {
        resizeStack(size + (size * 0.5f));
    }

    std::memcpy(stackArea + stackPointer, data, size);
    stackPointer += size;
}

void Stack::resizeStack(ptrdiff_t delta)
{
    // Increase or decrease the stack size
    stackSize += delta;

    // Re-allocate the memory area
    stackArea = (vm_byte_t*) std::realloc(stackArea, stackSize);

    // Post-conditions
    assert(stackArea != NULL && "Null pointer exception");
}
