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
 * File:   Thread.h
 * Author: Javier Marrero
 *
 * Created on May 31, 2022, 3:27 PM
 */

#ifndef THREAD_H
#define THREAD_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Runtime/Stack.h>
#include <amanda-vm/Runtime/Schedulable.h>

namespace amanda
{
namespace vm
{

/**
 * The <code>Thread</code> class encapsulates schedulable behavior.
 */
class Thread : public Schedulable
{
    AMANDA_OBJECT(Thread, Schedulable)
public:

    Thread(const Schedulable* parent);

    Stack&          getOperationStack() const;

protected:

    core::StrongReference<Stack>    operationStack;
    
} ;

}
}

#endif /* THREAD_H */

