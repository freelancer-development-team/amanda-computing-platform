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
 * File:   Stack.h
 * Author: Javier Marrero
 *
 * Created on May 31, 2022, 5:14 PM
 */

#ifndef STACK_H
#define STACK_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Logging/Logger.h>
#include <amanda-vm/Binutils/vm-types.h>

// C++
#include <stack>

namespace amanda
{
namespace vm
{

/**
 * A stack into which values may be pushed and popped. This is not a general
 * purpose stack. It is the stack used in the virtual machine execution model
 * to model the abstract stack machine according to the specification.
 * <p>
 * There's no need to implement synchronization mechanisms on this class since
 * every thread must have its own stack.
 *
 * @author J. Marrero
 */
class Stack : public core::Object
{
    AMANDA_OBJECT(Stack, core::Object)
public:

    Stack();
    virtual ~Stack();

    void*           allocl(size_t size);                                                /// Allocates memory on the stack
    const void*     dma(ptrdiff_t offset);                                              /// Performs direct memory access to the stack memory, offset from the stack pointer
    void            discard(size_t size);                                               /// Discard the last 'size' bytes from the stack pointer
    sdk_ullong_t    countFrames() const;                                                /// Counts how many frames have been allocated
    vm_address_t    getBasePointer() const;                                             /// Gets the address of the base pointer of the current stack frame
    sdk_ullong_t    getDepth();                                                         /// Gets the depth of the stack (in units)
    bool            isEmpty() const;                                                    /// Is this stack empty?
    void            peek(vm_byte_t* buffer, vm_size_t size) const;                      /// Reads the top value of the stack but does not moves the stack pointer
    void            pop(vm_byte_t* buffer, vm_size_t size);                             /// Reads and moves the stack pointer backwards
    void            popFrame(ptrdiff_t rvsize);                                         /// Pops the last allocated stack frame
    void            push(const vm_byte_t* data, vm_size_t size, bool convert = true);   /// Pushes a value onto the stack
    void            pushFrame();                                                        /// Allocates and pushes a new stack frame
    void*           read(void* result, ptrdiff_t offset, vm_size_t length) const;       /// Read from an arbitrary position within the stack
    bool            write(const void* data, ptrdiff_t offset, vm_size_t length);        /// Writes data to the stack

    template <typename T>
    inline T pop()
    {
        T data;
        pop((vm::vm_byte_t*) (&data), sizeof (T));

        return data;
    }

    template <typename T>
    inline void push(T data)
    {
        push((vm::vm_byte_t*) (&data), sizeof (data), false);
    }

private:

    typedef std::stack<vm_address_t>    FrameStack;
    typedef std::stack<vm_size_t>       DepthStack;

    static const logging::Logger& LOGGER;

    sdk_ullong_t    depth;
    DepthStack      depthStack;
    FrameStack      frameStack;
    vm_byte_t*      stackArea;
    vm_address_t    stackPointer;
    vm_size_t       stackSize;

    void resizeStack(ptrdiff_t delta);

} ;

}
}

#endif /* STACK_H */

