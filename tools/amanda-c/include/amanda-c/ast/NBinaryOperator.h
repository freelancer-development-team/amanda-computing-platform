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
 * File:   NBinaryOperator.h
 * Author: Javier Marrero
 *
 * Created on March 13, 2022, 12:01 AM
 */

#ifndef NBINARYOPERATOR_H
#define NBINARYOPERATOR_H

#include <amanda-c/ast/NExpression.h>
#include <amanda-c/ast/OperatorKinds.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NBinaryOperator : public NExpression
{
    AMANDA_OBJECT(NBinaryOperator, NExpression)

public:

    NBinaryOperator(BinaryOperator kind, NExpression* lhs, NExpression* rhs);
    virtual ~NBinaryOperator();

    virtual il::Value*      generateCode(il::CodeGenContext& context);
    virtual core::String    toString() const;

protected:

    BinaryOperator                      kind;
    core::StrongReference<NExpression>  lhs;
    core::StrongReference<NExpression>  rhs;
} ;

}
}
}

#endif /* NBINARYOPERATOR_H */

