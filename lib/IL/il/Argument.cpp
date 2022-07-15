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
 * File:   Argument.cpp
 * Author: Javier Marrero
 * 
 * Created on July 14, 2022, 6:40 PM
 */

#include <amanda-vm/IL/Argument.h>
#include <amanda-vm/IL/CodeGenContext.h>

using namespace amanda;
using namespace amanda::il;

Argument::Argument(const Type* type, const core::String& name, Function* f, unsigned argumentNumber)
:
Value(type, type->getContext().allocateValueIdentifier()),
argumentNumber(argumentNumber),
name(name),
parent(f)
{
}

Argument::~Argument()
{
}

unsigned Argument::getArgumentNumber() const
{
    return argumentNumber;
}

const Function* Argument::getParent() const
{
    return parent;
}




