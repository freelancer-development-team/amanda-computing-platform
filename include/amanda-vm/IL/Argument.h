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
 * File:   Argument.h
 * Author: Javier Marrero
 *
 * Created on July 14, 2022, 6:40 PM
 */

#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <amanda-vm/IL/Value.h>

namespace amanda
{
namespace il
{

class Function;

/**
 * This class represents an incoming formal argument from a <code>Function</code>.
 * <p>
 * A formal argument, since it is "formal" does not contain an actual value but
 * instead represents the type, argument number and attributes of an argument for
 * a specific function. When used in the body of said function, the argument of
 * course represents the value of the actual argument that the function was
 * called with.
 *
 * @author J. Marrero
 */
class Argument : public Value
{
public:

    friend class Function;

    Argument(const Type* type, const core::String& name = "",
             Function* f = NULL, unsigned argumentNumber = 0);
    virtual ~Argument();

    const Function* getParent() const;
    unsigned        getArgumentNumber() const;

protected:

    unsigned                        argumentNumber;
    core::String                    name;
    core::WeakReference<Function>   parent;
   
} ;

}
}

#endif /* ARGUMENT_H */

