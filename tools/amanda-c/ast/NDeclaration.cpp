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
 * File:   NDeclaration.cpp
 * Author: Javier Marrero
 * 
 * Created on March 19, 2022, 1:26 PM
 */

#include <amanda-c/ast/NDeclaration.h>

using namespace amanda;
using namespace amanda::compiler::ast;

NDeclaration::NDeclaration()
{
}

NDeclaration::~NDeclaration()
{
}

void NDeclaration::addDeclarations(NDeclarationBlock* declarations)
{
    assert(declarations != NULL && "Null pointer exception");
    
    for (DeclarationList::const_iterator it = declarations->getDeclarations().begin();
         it != declarations->getDeclarations().end(); ++it)
    {
        assert(*it != NULL && "Attempted to append NULL pointer to declaration object.");
        addChild(static_cast<il::AstNodeBase*>(*it));
    }
}

// ================== NDECLARATIONBLOCK CLASS =============================== //

NDeclarationBlock::NDeclarationBlock()
{
    declarations.reserve(5);
}

NDeclarationBlock::~NDeclarationBlock()
{
}

void NDeclarationBlock::addDeclaration(NDeclaration* declaration)
{
    assert(declaration != NULL && "Null pointer exception.");
    declarations.push_back(declaration);
}

const DeclarationList& NDeclarationBlock::getDeclarations() const
{
    return declarations;
}




