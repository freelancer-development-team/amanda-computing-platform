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
 * File:   NConditionalStatement.cpp
 * Author: Javier Marrero
 * 
 * Created on March 20, 2022, 11:17 PM
 */

#include <amanda-c/ast/NConditionalStatement.h>

using namespace amanda;
using namespace amanda::compiler::ast;

NConditionalStatement::NConditionalStatement(NExpression* condition, NBlock* block)
:
NCompoundStatement(block),
condition(condition)
{
    elseIfClauses.reserve(1);
}

NConditionalStatement::~NConditionalStatement()
{
}

void NConditionalStatement::addElseClause(NBlock* block)
{
    addChild(block);

    // Easy access reference
    // elseClause = block;
}

void NConditionalStatement::addElseIfClause(NExpression* condition, NBlock* block)
{
    NConditionalStatement* elseIfClause = new NConditionalStatement(condition, block);

    // Add them to both the tree structure and the easy access element.
    addChild(elseIfClause);
    // elseIfClauses.push_back(elseIfClause);
}

core::String NConditionalStatement::toString() const
{
    core::String buffer(buildHeaderString());
    buffer.append("\nWith condition: <").append(condition->toString()).append(">");
    return buffer;
}
