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
 * File:   Symbol.h
 * Author: Javier Marrero
 *
 * Created on February 24, 2022, 11:46 PM
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <amanda-vm/Object.h>
#include <amanda-vm/String.h>

namespace amanda
{
namespace il
{

/**
 * A symbol represents a reference to some memory space, address, constant or
 * binary object defined inside an object or executable file.
 */
class Symbol : public core::Object
{
    AMANDA_OBJECT(Symbol, core::Object)

public:

    Symbol(const core::String& name);
    virtual ~Symbol();
    
    const core::String& getName() const;

private:

    core::String    name;
} ;

}
}

#endif /* SYMBOL_H */

