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
 * File:   NConditionalStatement.h
 * Author: Javier Marrero
 *
 * Created on March 20, 2022, 11:17 PM
 */

#ifndef NCONDITIONALSTATEMENT_H
#define NCONDITIONALSTATEMENT_H

#include <amanda-c/ast/NCompoundStatement.h>
#include <amanda-c/ast/NExpression.h>

#include <vector>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NConditionalStatement : public NCompoundStatement
{
    AMANDA_OBJECT(NConditionalStatement, NCompoundStatement)

public:

    NConditionalStatement(NExpression* condition, NBlock* block);
    virtual ~NConditionalStatement();

    void                    addElseClause(NBlock* block);
    void                    addElseIfClause(NExpression* condition, NBlock* block);
    void                    addMultipleElseIfClauses(std::vector<NConditionalStatement*>& conditionals);
    
    virtual core::String    toString() const;

protected:

    core::StrongReference<NExpression>  condition;
    core::StrongReference<NBlock>       elseClause;
    std::vector<NConditionalStatement*> elseIfClauses;
    
} ;

}
}
}

#endif /* NCONDITIONALSTATEMENT_H */

