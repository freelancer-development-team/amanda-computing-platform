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

#include <amanda-vm/Binutils/Mangling.h>

using namespace amanda;
using namespace amanda::binutils;

bool ProcedureNameDescriptor::isArrayType(const core::String& typeName)
{
    return typeName.startsWith("A_");
}

ProcedureNameDescriptor ProcedureNameDescriptor::parse(const core::String& string)
{
    ProcedureNameDescriptor descriptor;

    // Get the identifier.
    unsigned identifierStart = (string.startsWith("@@") ? 2 : 0);
    unsigned identifierEnd = (string.find('?') != core::String::NPOS ? string.find('?') : string.length());
    descriptor.identifier = string.substring(identifierStart, identifierEnd);

    // Get the arguments
    unsigned argumentsStart = identifierEnd + 1;
    unsigned argumentsEnd = (string.find("@!", argumentsStart) != core::String::NPOS) ? string.find("@!", argumentsStart) : string.length();
    core::String arguments = string.substring(argumentsStart, argumentsEnd);
    const std::vector<core::String>& split = arguments.split("@");

    for (std::vector<core::String>::const_iterator it = split.begin(), end = split.end();
         it != end; ++it)
    {
        descriptor.arguments.push_back(*it);
    }
    
    // Get the return type.
    unsigned returnStart = string.findLast("@!");
    descriptor.returnType = string.substring(returnStart, string.length());

    // return the copy of the descriptor
    return descriptor;
}

ProcedureNameDescriptor::ProcedureNameDescriptor()
{
}

const core::String& ProcedureNameDescriptor::getIdentifier() const
{
    return identifier;
}

const core::String& ProcedureNameDescriptor::getReturnType() const
{
    return returnType;
}

