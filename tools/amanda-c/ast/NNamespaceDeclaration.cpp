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
 * File:   NNamespaceDeclaration.cpp
 * Author: Javier Marrero
 * 
 * Created on March 19, 2022, 10:05 AM
 */

#include <amanda-c/ast/NNamespaceDeclaration.h>
#include <amanda-vm/ADT/Array.h>

using namespace amanda;
using namespace amanda::compiler::ast;

NNamespaceDeclaration* amanda::compiler::ast::buildNamespacesByQualifiedName(const core::String& name, NNamespaceDeclaration*& last)
{
    // The return value
    NNamespaceDeclaration* parent = NULL;

    // We need to split the qualified name into discrete subcomponents.
    std::vector<core::String> tokens = name.split("::");

    // Create the parent node
    parent = new NNamespaceDeclaration(tokens.front());
    NNamespaceDeclaration* previous = parent;
    
    for (std::vector<core::String>::iterator it = ++(tokens.begin());
         it != tokens.end(); ++it)
    {
        // Create a new namespace
        NNamespaceDeclaration* current = new NNamespaceDeclaration(*it);
        NDeclarationBlock* block = new NDeclarationBlock();

        block->addDeclaration(current);
        previous->addDeclarations(block);
        previous = current;

        last = current;
    }

    if (last == NULL)
    {
        last = parent;
    }
    return parent;
}

NNamespaceDeclaration::NNamespaceDeclaration(const core::String& name)
:
name(name)
{
}

NNamespaceDeclaration::~NNamespaceDeclaration()
{
}

core::String NNamespaceDeclaration::toString() const
{
    core::String buffer(buildHeaderString());
    buffer.append("Namespace name: ").append(name);

    return buffer;
}
