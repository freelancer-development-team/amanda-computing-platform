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
 * Created on April 6, 2022, 8:16 PM
 */

#ifndef _AMANDA_BINUTILS_LD_SYMBOL_H
#define _AMANDA_BINUTILS_LD_SYMBOL_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/Serializable.h>

namespace amanda
{
namespace binutils
{
namespace ld
{

/**
 * The <code>Symbol</code> class in an abstract base class that represents all
 * the possible link-time symbols in a concrete compilation unit or module.
 */
class Symbol : public Serializable
{
    AMANDA_OBJECT(Symbol, Serializable)
public:

    enum
    {
        FUNCTION = 1
    };

    Symbol(const core::String& name);
    virtual ~Symbol();

    const core::String& getName() const;
    const sdk_ullong_t  getSize() const;
    bool                is(const unsigned kind) const;
    
protected:
   
    unsigned                kind;
    core::String            name;
    mutable sdk_ullong_t    size;

    virtual sdk_ullong_t computeSize() const;
} ;

}
}
}

#endif /* SYMBOL_H */

