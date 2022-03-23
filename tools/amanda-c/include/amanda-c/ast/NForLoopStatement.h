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
 * File:   NForLoopStatement.h
 * Author: Javier Marrero
 *
 * Created on March 22, 2022, 10:20 AM
 */

#ifndef NFORLOOPSTATEMENT_H
#define NFORLOOPSTATEMENT_H

#include <amanda-c/ast/NCompoundStatement.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NForLoopStatement : public NCompoundStatement
{
    AMANDA_OBJECT(NForLoopStatement, NCompoundStatement)

public:

    NForLoopStatement(NExpression* initializationExpression,
                      NExpression* conditionExpression,
                      NExpression* updateExpression,
                      NBlock* block);
    virtual ~NForLoopStatement();

    virtual core::String toString() const;

protected:

    core::StrongReference<NExpression> initializationExpression;
    core::StrongReference<NExpression> conditionExpression;
    core::StrongReference<NExpression> updateExpression;
} ;

}
}
}

#endif /* NFORLOOPSTATEMENT_H */

