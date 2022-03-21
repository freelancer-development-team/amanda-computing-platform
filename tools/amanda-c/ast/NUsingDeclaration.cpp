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
 * File:   NUsingDeclaration.cpp
 * Author: Javier Marrero
 * 
 * Created on March 20, 2022, 10:32 AM
 */

#include <amanda-c/ast/NUsingDeclaration.h>

using namespace amanda;
using namespace amanda::compiler::ast;

NUsingDeclaration::NUsingDeclaration(const core::String& package)
:
package(package)
{
}

NUsingDeclaration::~NUsingDeclaration()
{
}

core::String NUsingDeclaration::toString() const
{
    core::String buffer(buildHeaderString());
    buffer.append("Importing: ").append(package);
    return buffer;
}



