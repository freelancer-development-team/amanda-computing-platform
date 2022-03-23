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
 * File:   NVariableDeclaration.h
 * Author: Javier Marrero
 *
 * Created on March 22, 2022, 5:42 PM
 */

#ifndef NVARIABLEDECLARATION_H
#define NVARIABLEDECLARATION_H

#include <amanda-c/ast/NExpression.h>
#include <amanda-c/ast/NIdentifier.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NVariableDeclaration : public NExpression
{
    AMANDA_OBJECT(NVariableDeclaration, NExpression)

public:

    NVariableDeclaration(const core::String& type, NIdentifier* id);
    virtual ~NVariableDeclaration();

    void                    setAssignmentExpression(NExpression* assignment);
    virtual core::String    toString() const;

protected:

    core::String                        type;
    core::StrongReference<NIdentifier>  identifier;
    core::StrongReference<NExpression>  assignment;
} ;

}
}
}

#endif /* NVARIABLEDECLARATION_H */

