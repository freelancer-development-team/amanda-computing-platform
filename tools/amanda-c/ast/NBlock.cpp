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
 * File:   NBlock.cpp
 * Author: Javier Marrero
 * 
 * Created on March 13, 2022, 12:43 AM
 */

#include <amanda-c/ast/NBlock.h>

using namespace amanda;
using namespace amanda::compiler::ast;

using amanda::il::Value;
using amanda::il::CodeGenContext;

NBlock::NBlock()
{
    statements.reserve(5);
}

NBlock::~NBlock()
{
    for (StatementList::iterator it = statements.begin(); it != statements.end(); ++it)
    {
        (*it)->release();
    }
}

void NBlock::addStatement(NStatement* statement)
{
    assert(statement != NULL && "Null pointer exception.");
    statement->grab();

    statements.push_back(statement);
    addChild(statement);
}

void NBlock::cloneBlockState(NBlock* block)
{
    for (StatementList::iterator it = block->statements.begin(); it != block->statements.end(); ++it)
    {
        addStatement(static_cast<NStatement*>(*it));
    }
}

const StatementList& NBlock::getStatementList() const
{
    return statements;
}

bool NBlock::hasStatements() const
{
    return !statements.empty();
}

Value* NBlock::performSSATransformation(amanda::il::CodeGenContext& context)
{
    return NULL;
}
