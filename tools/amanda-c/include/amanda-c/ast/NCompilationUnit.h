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
 * File:   NCompilationUnit.h
 * Author: Javier Marrero
 *
 * Created on March 18, 2022, 1:32 AM
 */

#ifndef NCOMPILATIONUNIT_H
#define NCOMPILATIONUNIT_H

#include <amanda-c/ast/NDeclaration.h>
#include <amanda-c/ast/NNamespaceDeclaration.h>

#include <stack>
#include <vector>

namespace amanda
{
namespace compiler
{
namespace ast
{

/**
 * A node representing the top-level symbol: a compilation unit. A compilation
 * unit is analog to a module in the low-level IL library terminology.
 */
class NCompilationUnit : public NDeclaration
{
    AMANDA_OBJECT(NCompilationUnit, NDeclaration)

public:

    NCompilationUnit(const core::String& name);
    virtual ~NCompilationUnit();

    NNamespaceDeclaration*  getCurrentNamespace() const;
    const core::String&     getName() const;
    void                    popNamespace();
    NNamespaceDeclaration&  pushNamespace(NNamespaceDeclaration* object);
    
protected:

    core::String                        name;
    std::stack<NNamespaceDeclaration*>  namespaces;
    std::stack<il::AstNodeBase*>        localScopes;
    
} ;

}
}
}

#endif /* NCOMPILATIONUNIT_H */

