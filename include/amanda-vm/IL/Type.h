/*
 * Copyright (C) 2022 FreeLancer Development Team
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
 * File:   Type.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 2:51 PM
 */

#ifndef TYPE_H
#define TYPE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/OutputStream.h>

namespace amanda
{
namespace il
{

class Type : public core::Object
{

    AMANDA_OBJECT(Type, core::Object)

public:

    typedef enum
    {
        // Derived types
        ID_VoidType = 0,
        ID_IntegerType,
        ID_FloatingPointType,
        ID_FunctionType,
        ID_PointerType,
        ID_StructuredType,
        ID_SequentialType
    } TypeID;

    virtual ~Type();

    TypeID          getTypeId() const;
    virtual bool    isIntegralType() const;
    virtual bool    isFloatingPointType() const;
    virtual bool    isSized() const;
    virtual void    print(io::OutputStream& os, bool debug = false, bool detailed = false) const;

protected:

    TypeID id;
} ;

}
}

#endif /* TYPE_H */

