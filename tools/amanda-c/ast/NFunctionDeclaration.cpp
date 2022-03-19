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
 * File:   NFunctionDeclaration.cpp
 * Author: Javier Marrero
 * 
 * Created on March 18, 2022, 2:02 AM
 */

#include <amanda-c/ast/NFunctionDeclaration.h>

using namespace amanda;
using namespace amanda::compiler::ast;

NFunctionDeclaration::NFunctionDeclaration(const core::String& identifier)
:
identifier(identifier)
{
}

NFunctionDeclaration::~NFunctionDeclaration()
{
}

core::String NFunctionDeclaration::toString() const
{
    core::String buffer(buildHeaderString());
    buffer.append("Function name: ").append(identifier);
    return buffer;
}
