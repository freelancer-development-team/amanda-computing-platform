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
 * File:   Schedulable.h
 * Author: Javier Marrero
 *
 * Created on May 22, 2022, 9:09 AM
 */

#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Threading/Runnable.h>
#include <amanda-vm/Runtime/Stack.h>
#include <amanda-vm/Runtime/Schedulable.h>
#include <amanda-vm/Binutils/vm-types.h>

#include "Procedure.h"

namespace amanda
{
namespace vm
{

class Context;

/**
 * Objects of this class are designed to be used as discrete scheduling units
 * by the virtual machine thread scheduler.
 *
 * @author J. Marrero
 */
class Schedulable : public concurrent::Runnable
{
    AMANDA_OBJECT(Schedulable, concurrent::Runnable)

public:

    Schedulable(const Schedulable* parent,
                const Context& context,
                Procedure* init);
    virtual ~Schedulable();

    const Context&  getContext() const;
    vm::vm_qword_t  getReturnValue() const;
    bool            hasParent() const;
    bool            isRoot() const;
    virtual void    run();

private:

    const Context&                              context;
    core::StrongReference<Procedure>            currentProcedure;
    core::StrongReference<const Schedulable>    parent;
    vm::vm_qword_t                              returnValue;
    core::StrongReference<Stack>                stack;

} ;

}
}

#endif /* SCHEDULABLE_H */

