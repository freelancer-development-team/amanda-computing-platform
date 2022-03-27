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
 * File:   VMStack.h
 * Author: Javier Marrero
 *
 * Created on March 25, 2022, 12:44 PM
 */

#ifndef VMSTACK_H
#define VMSTACK_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/VirtualMachineSpecs.h>

namespace amanda
{
namespace vm
{

/**
 * Represents the virtual machine stacks used during execution.
 */
class VMStack : public core::Object
{

    AMANDA_OBJECT(VMStack, core::Object)
public:

    /**
     * Represents exceptions thrown by the stack, such as limit overflow or
     * underflow, access denegation and segmentation faults, both provoked by
     * the running program or by a bad virtual machine operation.
     * <p>
     * This is a fatal exception and it terminates the program execution wherever
     * it is found. Therefore, it cannot be catch.
     * 
     * @author J. Marrero
     */
    class StackMemoryError : public core::Exception
    {
        AMANDA_OBJECT(StackMemoryError, core::Exception)
    public:

        StackMemoryError(const VMStack* stack);
        ~StackMemoryError() throw ();

    private:

        const VMStack* stack;
    } ;

    static const unsigned DEFAULT_MAX_STACK_SIZE = UINT_MAX;
    static const unsigned DEFAULT_CAPACITY = 0x2000;  /// Default capacity of the stack: 8192B

    VMStack(unsigned limit);
    ~VMStack();

    void        pop(void* data, size_t size);
    vm_byte_t     popByte();
    vm_word_t     popWord();
    vm_dword_t    popDoubleWord();
    vm_qword_t    popQuadWord();
    vm_address_t  popAddress();
    void        push(const void* data, size_t size);
    void        push(vm_byte_t data);
    void        push(vm_word_t data);
    void        push(vm_dword_t data);
    void        push(vm_qword_t data);
    void        pushAddress(vm_address_t data);

    template <typename T>
    void pop(T* data)
    {
        pop(data, sizeof(T));
    }

    template <typename T>
    void push(T data)
    {
        push(&data, sizeof(data));
    }

private:

    size_t      capacity;
    size_t      limit;
    vm_byte_t*    stackData;
    vm_pointer_t  stackPointer;

} ;

}
}

#endif /* VMSTACK_H */

