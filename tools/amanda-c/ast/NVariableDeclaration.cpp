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
 * File:   NVariableDeclaration.cpp
 * Author: Javier Marrero
 * 
 * Created on March 22, 2022, 5:42 PM
 */

#include <amanda-c/ast/NVariableDeclaration.h>

using namespace amanda;
using namespace amanda::compiler::ast;

NVariableDeclaration::NVariableDeclaration(const core::String& type, NIdentifier* id)
:
type(type),
identifier(id)
{
}

NVariableDeclaration::~NVariableDeclaration()
{
}

core::String NVariableDeclaration::toString() const
{
    core::String buffer(buildHeaderString());
    buffer.appendWithFormat("type <%S> | name: '", type).append(identifier->getName()).append("'");

    return buffer;
}

void NVariableDeclaration::setAssignmentExpression(NExpression* assignment)
{
    this->assignment = assignment;
}
