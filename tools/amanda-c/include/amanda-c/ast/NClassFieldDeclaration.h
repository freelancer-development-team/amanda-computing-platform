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
 * File:   NClassFieldDeclaration.h
 * Author: Javier Marrero
 *
 * Created on March 23, 2022, 12:39 AM
 */

#ifndef NCLASSFIELDDECLARATION_H
#define NCLASSFIELDDECLARATION_H

#include <amanda-c/ast/NStatement.h>
#include <amanda-c/ast/NClassDeclaration.h>
#include <amanda-c/ast/NIdentifier.h>
#include <amanda-c/ast/Modifiers.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NClassFieldDeclaration : public NStatement
{
    AMANDA_OBJECT(NClassFieldDeclaration, NStatement)

public:

    NClassFieldDeclaration(const core::String& type, NIdentifier* identifier);

protected:

    NClassDeclaration::AccessModifier   accessModifier;
    core::String                        type;
    core::StrongReference<NIdentifier>  identifier;
    VariableModifier                    modifiers;
    
} ;

}
}
}

#endif /* NCLASSFIELDDECLARATION_H */

