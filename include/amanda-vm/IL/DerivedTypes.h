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
 * File:   DerivedTypes.h
 * Author: Javier Marrero
 *
 * Created on March 24, 2022, 5:32 PM
 */

#ifndef DERIVEDTYPES_H
#define DERIVEDTYPES_H

#include <amanda-vm/IL/Type.h>

/* C standard integer types. */
#include <stdint.h>
#include <climits>

namespace amanda
{
namespace il
{

class IntegerType : public Type
{
    AMANDA_OBJECT(IntegerType, Type)

public:

    enum
    {
        MIN_INT_BITS = 1,
        MAX_INT_BITS = (1 << 23)
    };

    typedef uint64_t    uinteger_t;
    typedef int64_t     integer_t;

    static IntegerType* get(unsigned numBits);

    uinteger_t  getBitMask() const;
    unsigned    getNumberOfBits() const;
    uinteger_t  getSignBit() const;
    
protected:

    IntegerType(const unsigned numBits);

private:

    const unsigned numBits;
};

}
}

#endif /* DERIVEDTYPES_H */
