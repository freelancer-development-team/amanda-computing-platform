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
 * File:   NNamespaceDeclaration.h
 * Author: Javier Marrero
 *
 * Created on March 19, 2022, 10:05 AM
 */

#ifndef NNAMESPACEDECLARATION_H
#define NNAMESPACEDECLARATION_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/ADT/Array.h>
#include <amanda-c/ast/NDeclaration.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NNamespaceDeclaration : public NDeclaration
{
    AMANDA_OBJECT(NNamespaceDeclaration, NDeclaration)

public:

    NNamespaceDeclaration(const core::String& name);
    virtual ~NNamespaceDeclaration();

    virtual core::String toString() const;

private:

    const core::String name;
} ;

/**
 * Builds a series of namespace objects from a single fully qualified name,
 * and then links them. Returns the parent namespace, and a reference to the
 * last created namespace (it is allocated on-the-fly, therefore the pointer).
 * 
 * @return
 */
NNamespaceDeclaration* buildNamespacesByQualifiedName(const core::String& name, NNamespaceDeclaration*& last);

}
}
}

#endif /* NNAMESPACEDECLARATION_H */

