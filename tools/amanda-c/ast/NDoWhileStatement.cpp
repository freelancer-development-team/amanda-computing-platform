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
 * File:   NDoWhileStatement.cpp
 * Author: Javier Marrero
 * 
 * Created on July 13, 2022, 2:55 PM
 */

#include <amanda-c/ast/NDoWhileStatement.h>

using namespace amanda;
using namespace amanda::compiler::ast;

NDoWhileStatement::NDoWhileStatement(NExpression* condition, NBlock* block)
:
NCompoundStatement(block),
condition(condition)
{
}

NDoWhileStatement::~NDoWhileStatement()
{
}

core::String NDoWhileStatement::toString() const
{
    core::String buffer(buildHeaderString());
    buffer.append("\nWith condition: <").append(condition->toString()).append(">\n");

    return buffer;
}
