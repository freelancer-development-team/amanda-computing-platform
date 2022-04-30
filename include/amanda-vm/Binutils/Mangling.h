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
 * File:   Mangling.h
 * Author: Javier Marrero
 *
 * Created on April 29, 2022, 5:35 PM
 */

#ifndef AMANDA_BINUTILS_NAME_MANGLING_H
#define AMANDA_BINUTILS_NAME_MANGLING_H

#include <amanda-vm/TypeSystem.h>

// C++
#include <algorithm>
#include <vector>

namespace amanda
{
namespace binutils
{

/**
 * Name descriptors are auxiliary data structures that helps encoding and
 * decoding procedure names in the Amanda platform.
 *
 * @author J. Marrero
 */
class ProcedureNameDescriptor : public core::Object
{
    AMANDA_OBJECT(ProcedureNameDescriptor, core::Object)
public:

    static bool                     isArrayType(const core::String& typeName);
    static ProcedureNameDescriptor  parse(const core::String& string);

    const core::String& getIdentifier() const;
    const core::String& getReturnType() const;

protected:

    ProcedureNameDescriptor();

    std::vector<core::String>   arguments;
    core::String                identifier;
    core::String                returnType;
    
} ;

}
}

#endif /* MANGLING_H */

