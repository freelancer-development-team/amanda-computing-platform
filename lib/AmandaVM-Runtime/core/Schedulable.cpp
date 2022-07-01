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
 * File:   Schedulable.cpp
 * Author: Javier Marrero
 * 
 * Created on May 22, 2022, 9:09 AM
 */

#include <amanda-vm/Runtime/Schedulable.h>
#include <amanda-vm/Runtime/Context.h>

// C++
#include <cerrno>
#include <csignal>

using namespace amanda;
using namespace amanda::vm;

Schedulable::Schedulable(const Schedulable* parent,
                         const Context& context,
                         Procedure* init)
:
context(context),
currentProcedure(init),
parent(parent),
returnValue(NULL),
stack(new Stack())
{
}

Schedulable::~Schedulable()
{
    if (returnValue != NULL)
    {
        std::free(returnValue);
    }
}

const Context& Schedulable::getContext() const
{
    // Lock access to the context
    AMANDA_SYNCHRONIZED(lock);

    // Set result as the reference
    const Context& result = context;

    // Unlock access to the context
    AMANDA_DESYNCHRONIZED(lock);
    return result;
}

vm::vm_dword_t Schedulable::getReturnValueAsLong() const
{
    return *((vm::vm_dword_t*) returnValue);
}

vm::vm_qword_t Schedulable::getReturnValueAsQuad() const
{
    return *((vm::vm_qword_t*) returnValue);
}

bool Schedulable::hasParent() const
{
    return parent.isNotNull();
}

bool Schedulable::isRoot() const
{
    return parent.isNull();
}

void Schedulable::run()
{
    // Preconditions
    assert(currentProcedure.isNotNull() && "Null pointer exception");
    assert(stack.isNotNull() && "Null pointer exception");

    // Set the signal handlers
    std::signal(SIGSEGV, Context::handleSigsegv);

    // Apply the stack to the current procedure and begin executing
    vm::vm_size_t rvsize = 0;
    try
    {
        //stack->pushFrame();
        rvsize = currentProcedure->execute(stack->getReference(), eflags);
        //stack->popFrame();
    }
    catch (core::Exception& ex)
    {
        returnValue = NULL;
        throw ex;
    }

    // The last value in the stack is the return value
    // the trouble is how to know which data is the adequate
    if (rvsize > 0)
    {
        returnValue = (vm_byte_t*) std::calloc(rvsize, VM_BYTE_SIZE);
        stack->pop(returnValue, rvsize);
    }
}
