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
 * File:   NCompilationUnit.cpp
 * Author: Javier Marrero
 * 
 * Created on March 18, 2022, 1:32 AM
 */

#include <amanda-c/ast/NCompilationUnit.h>

#include <cstdio>

using namespace amanda;
using namespace amanda::compiler::ast;

NCompilationUnit::NCompilationUnit(const core::String& name)
:
name(name)
{
    
}

NCompilationUnit::~NCompilationUnit()
{
    
}

const core::String& NCompilationUnit::getName() const
{
    return name;
}

NNamespaceDeclaration* NCompilationUnit::getCurrentNamespace() const
{
    return namespaces.top();
}

void NCompilationUnit::popNamespace()
{
    assert(namespaces.size() > 0 && "Stack underflow.");
    NNamespaceDeclaration* object = namespaces.top();
    object->release();
}

NNamespaceDeclaration& NCompilationUnit::pushNamespace(NNamespaceDeclaration* object)
{
    assert(object != NULL && "Null pointer exception.");

    object->grab();
    namespaces.push(object);
    
    return *object;
}
