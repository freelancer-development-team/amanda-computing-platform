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
#include <amanda-vm/Runtime/InvalidAllocationError.h>
#include <amanda-vm/IO/Utility.h>

// C++
#include <cstdlib>
#include <cstring>
#include <setjmp.h>
#include <wchar.h>
#include <math.h>

using namespace amanda;
using namespace amanda::vm;

const logging::Logger& Stack::LOGGER = logging::Logger::getLogger("amanda.vm.Stack")->getConstReference();

Stack::Stack()
:
depth(0),
stackArea((vm_byte_t*) std::calloc(0x1000, sizeof (vm::vm_byte_t))),
stackPointer(0),
stackSize(0x1000)
{
    assert(stackArea != NULL && "Null pointer exception");
}

Stack::~Stack()
{
    std::free(stackArea);
}

void* Stack::allocl(size_t size)
{
    void* result = NULL;
    if (size >= ULONG_MAX)
    {
        throw InvalidAllocationError(core::String::makeFormattedString("requested a stack allocation over 0x%llx bytes.", ULONG_MAX).toCharArray());
    }
    else
    {
        if (stackPointer + size > stackSize)
        {
            resizeStack(size + (stackSize * 0.5f));
        }

        // Create the result pointer, point that to the stack pointer and
        // move the stack pointer 'size' bytes ahead
        result = (void*) stackPointer;
        stackPointer += size;
        ++depth;
    }
    return result;
}

sdk_ullong_t Stack::countFrames() const
{
    return frameStack.size();
}

const void* Stack::dma(ptrdiff_t offset)
{
    assert(stackArea != NULL && "Attempted direct memory access to uninitialized stack");
    assert(stackPointer >= ((vm_address_t) offset) && "Attempted direct memory access with negative offset.");

    // Performs direct memory access to the stack area
    // The data returned is unmodifiable
    return (const void*) (stackArea + (stackPointer - offset));
}

vm_address_t Stack::getBasePointer() const
{
    return frameStack.top();
}

sdk_ullong_t Stack::getDepth()
{
    return depth;
}

bool Stack::isEmpty() const
{
    return stackPointer == 0;
}

void Stack::peek(vm_byte_t* buffer, vm_size_t size) const
{
    std::memcpy(buffer, (const void*) (stackArea + (stackPointer - size)), size);
}

void Stack::pop(vm_byte_t* buffer, vm_size_t size)
{
    //    AMANDA_SYNCHRONIZED(lock);
    //    {
    assert((stackPointer - size) >= 0ul && "Invalid pop operation on empty stack.");
    peek(buffer, size);

    // Reduce the stack pointer
    std::memset((void*) (stackArea + (stackPointer - size)), 0, size);
    stackPointer -= size;
    --depth;
    //    }
    //    AMANDA_DESYNCHRONIZED(lock);
}

void Stack::popFrame(ptrdiff_t rvsize)
{
    assert(rvsize >= 0ul && "Passed a negative return value size");

    // Set the variables
    const vm_address_t basePointer  = getBasePointer();
    const vm_address_t frameSize    = stackPointer - basePointer;
    depth = depthStack.top();

    // Pop the stack frame
    frameStack.pop();
    depthStack.pop();

    // Set the stack pointer
    // Allocate enough space for returning a value, pop it, and
    // push it back on the stack, after resetting the frame pointer.
    vm_byte_t* buffer = NULL;
    if (rvsize > 0)
    {
        buffer = (vm_byte_t*) std::calloc(rvsize, VM_BYTE_SIZE);
        assert(buffer != NULL && "Null pointer exception");

        peek(buffer, rvsize);
    }

    // Set the stack pointer
    std::memset(stackArea + (basePointer), 0, frameSize);
    stackPointer = basePointer;

    // Push the stored result
    if (rvsize > 0 && buffer != NULL)
    {
        // Push the value back to the stack
        push(buffer, rvsize, false);
    }

    // Log the frame pop
    LOGGER.info("popping stack frame with offset 0x%llx (depth %llu)", basePointer, depth);
}

void Stack::push(const vm_byte_t* data, vm_size_t size, bool convert)
{
    //    AMANDA_SYNCHRONIZED(lock);
    //    {
    if (stackPointer + size > stackSize)
    {
        resizeStack(size + (stackSize * 0.5f));
    }

    std::memcpy(stackArea + stackPointer, data, size);
    if (!io::isMachineBigEndian() && convert)
    {
        io::swapEndianness(stackArea + stackPointer, size);
    }

    stackPointer += size;
    ++depth;
    //    }
    //    AMANDA_DESYNCHRONIZED(lock);
}

void Stack::pushFrame()
{
    // Push a new frame into the return stack
    frameStack.push(stackPointer);
    depthStack.push(depth);

    LOGGER.info("pushing stack frame with offset 0x%llx (depth %llu).", getBasePointer(), depth);
}

void* Stack::read(void* result, ptrdiff_t offset, vm_size_t length) const
{
    assert(result != NULL && "Null pointer exception.");
    assert(offset < ((ptrdiff_t) stackSize) && "Attempted read outside stack boundaries. (superior bound)");

    std::memmove(result, stackArea + (((ptrdiff_t) getBasePointer()) + offset), length);
    return result;
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

bool Stack::write(const void* data, ptrdiff_t offset, vm_size_t length)
{
    void* target = (void*) (stackArea + ((ptrdiff_t) getBasePointer() + offset));
    assert(data != NULL && "Attempted to write null data.");
    assert(target >= stackArea && "Attempted to write outside of the stack (inferior bound).");
    assert(target <= (stackArea + stackSize) && "Attempted to write outside of the stack (superior bound).");

    // Write
    bool result = (std::memmove(target, data, length) == target);

    // Reduce the stack pointer by n-units
    stackPointer -= length;

    return result;
}
