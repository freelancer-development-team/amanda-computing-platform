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
 * File:   NWhileStatement.h
 * Author: Javier Marrero
 *
 * Created on March 20, 2022, 11:07 AM
 */

#ifndef NWHILESTATEMENT_H
#define NWHILESTATEMENT_H

#include <amanda-c/ast/NCompoundStatement.h>
#include <amanda-c/ast/NExpression.h>
#include <amanda-c/ast/NBlock.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NWhileStatement : public NCompoundStatement
{
    AMANDA_OBJECT(NWhileStatement, NCompoundStatement)
public:

    NWhileStatement(NExpression* condition, NBlock* block);
    virtual ~NWhileStatement();

    virtual core::String toString() const;

protected:

    core::StrongReference<NExpression> condition;
} ;

}
}
}

#endif /* NWHILESTATEMENT_H */

