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
 * File:   Callable.h
 * Author: Javier Marrero
 *
 * Created on March 1, 2022, 1:59 PM
 */

#ifndef CALLABLE_H
#define CALLABLE_H

#include <amanda-vm/Interface.h>
#include <amanda-vm/ADT/Array.h>

namespace amanda
{
namespace core
{

/**
 * Callables are objects representing functions.
 */
class Callable : extends Interface
{
    AMANDA_OBJECT(Callable, Interface)

public:

    virtual void* call(adt::Array<void*>& arguments) = 0;
};

}
}

#endif /* CALLABLE_H */

