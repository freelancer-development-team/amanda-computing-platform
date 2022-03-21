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
 * File:   NExpressionStatement.h
 * Author: Javier Marrero
 *
 * Created on March 20, 2022, 10:35 PM
 */

#ifndef NEXPRESSIONSTATEMENT_H
#define NEXPRESSIONSTATEMENT_H

#include <amanda-c/ast/NStatement.h>
#include <amanda-c/ast/NExpression.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NExpressionStatement : public NStatement
{

    AMANDA_OBJECT(NExpressionStatement, NStatement)

public:

    NExpressionStatement(NExpression* expression);
    virtual ~NExpressionStatement();

} ;

}
}
}

#endif /* NEXPRESSIONSTATEMENT_H */

