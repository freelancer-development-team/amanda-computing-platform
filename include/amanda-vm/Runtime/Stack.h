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
 * File:   Stack.h
 * Author: Javier Marrero
 *
 * Created on May 31, 2022, 5:14 PM
 */

#ifndef STACK_H
#define STACK_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/vm-types.h>

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

    bool    isEmpty() const;
    void    pop(vm_byte_t* buffer, vm_size_t size);
    void    push(const vm_byte_t* data, vm_size_t size);

    template <typename T>
    inline T pop()
    {
        T data;
        pop(&data, sizeof(T));
        
        return data;
    }

    template <typename T>
    inline void push(T data)
    {
        push(&data, sizeof (data));
    }

private:

    vm_address_t    basePointer;
    vm_byte_t*      stackArea;
    vm_address_t    stackPointer;
    vm_size_t       stackSize;

    void resizeStack(ptrdiff_t delta);

} ;

}
}

#endif /* STACK_H */

