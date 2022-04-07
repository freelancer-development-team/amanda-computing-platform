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
 * File:   NForLoopStatement.cpp
 * Author: Javier Marrero
 * 
 * Created on March 22, 2022, 10:20 AM
 */

#include <amanda-c/ast/NForLoopStatement.h>

using namespace amanda;
using namespace amanda::compiler::ast;

NForLoopStatement::NForLoopStatement(NExpression* initializationExpression,
                                     NExpression* conditionExpression,
                                     NExpression* updateExpression,
                                     NBlock* block)
:
NCompoundStatement(block),
initializationExpression(initializationExpression),
conditionExpression(conditionExpression),
updateExpression(updateExpression)
{
    ///TODO: Check correctness
    if (initializationExpression)
        initializationExpression->grab();
    if (conditionExpression)
        conditionExpression->grab();
    if (updateExpression)
        updateExpression->grab();
}

NForLoopStatement::~NForLoopStatement()
{
}

core::String NForLoopStatement::toString() const
{
    core::String buffer(buildHeaderString());
    buffer.append("\nInitializer: <").appendWithFormat("%S>", !initializationExpression.isNull() ? initializationExpression->toString() : "None");
    buffer.append("\nCondition: <").appendWithFormat("%S>", conditionExpression->toString());
    buffer.append("\nIncrement: <").appendWithFormat("%S>", !updateExpression.isNull() ? updateExpression->toString() : "None");

    return buffer;
}


