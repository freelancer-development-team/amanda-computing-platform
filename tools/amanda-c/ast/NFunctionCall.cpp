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
 * File:   NFunctionCall.cpp
 * Author: Javier Marrero
 * 
 * Created on March 20, 2022, 10:41 PM
 */

#include <amanda-c/ast/NFunctionCall.h>

using namespace amanda;
using namespace amanda::compiler::ast;

NFunctionCall::NFunctionCall(const core::String& target)
:
callTargetIdentifier(target)
{
    passedArguments.reserve(1);
}

NFunctionCall::~NFunctionCall()
{
    for (ExpressionList::iterator it = passedArguments.begin(); it != passedArguments.end(); ++it)
    {
        static_cast<NExpression*> (*it)->release();
    }
}

void NFunctionCall::addPassedArguments(ExpressionList& list)
{
    for (ExpressionList::iterator it = list.begin();
         it != list.end(); ++it)
    {
        NExpression* expression = static_cast<NExpression*> (*it);
        assert(expression != NULL && "Null pointer exception.");

        expression->grab(); // Borrow a reference to this object
        passedArguments.push_back(expression); // And push the references
    }
}

const core::String& NFunctionCall::getCallTarget() const
{
    return callTargetIdentifier;
}

bool NFunctionCall::hasPassedArguments() const
{
    return !passedArguments.empty();
}

core::String NFunctionCall::toString() const
{
    core::String buffer(buildHeaderString());
    buffer.appendWithFormat("called <%S>", callTargetIdentifier);
    if (hasPassedArguments())
    {
        buffer.appendWithFormat("\n  Target invoked with following arguments (%u):", (unsigned) passedArguments.size());
        for (ExpressionList::const_iterator it = passedArguments.begin(); it != passedArguments.end(); ++it)
        {
            buffer.append("\n    <").append((*it)->toString()).append(">");
        }
    }
    else
    {
        buffer.append("\n  Target invoked with zero arguments!");
    }
    return buffer;
}



