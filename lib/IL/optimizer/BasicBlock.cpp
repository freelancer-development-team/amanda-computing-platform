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
 * File:   BasicBlock.cpp
 * Author: Javier Marrero
 * 
 * Created on March 12, 2022, 3:22 PM
 */

#include <amanda-vm/IL/BasicBlock.h>
#include <amanda-vm/IL/Function.h>
#include <amanda-vm/IL/Module.h>

using namespace amanda;
using namespace amanda::il;

BasicBlock::BasicBlock(CodeGenContext& context, const core::String& name, Function* parent, BasicBlock* insertBefore)
:
Value(context.getPrimitiveType(Type::ID_LabelType), context.allocateValueIdentifier()),
module(context.getModule()),
parent(parent)
{
    /// Set the name of the function
    setName(name);

    if (insertBefore != NULL)
    {
        moveBefore(insertBefore);
    }
}

BasicBlock::~BasicBlock()
{
}

bool BasicBlock::canSplitPredecessors() const
{
}

const Instruction* BasicBlock::getFirstNonPhi() const
{
}

const BasicBlock::InstListType& BasicBlock::getInstructionList() const
{
}

const Module* BasicBlock::getModule() const
{
    return module;
}

const Function* BasicBlock::getParent() const
{
    return parent;
}

const BasicBlock* BasicBlock::getSinglePredecessor() const
{
}

const BasicBlock* BasicBlock::getSingleSuccessor() const
{
}

Instruction* BasicBlock::getTerminator() const
{
}

bool BasicBlock::hasAddressTaken() const
{
}

bool BasicBlock::hasNPredecesorsOrMore(unsigned n) const
{
}

bool BasicBlock::hasPredecessors(unsigned n) const
{
}

void BasicBlock::insertInto(Function* parent, BasicBlock* insertBefore)
{
}

bool BasicBlock::isEntryBlock() const
{
}

bool BasicBlock::isExceptionHandler() const
{
}

void BasicBlock::moveAfter(BasicBlock* movePos)
{
}

void BasicBlock::moveBefore(BasicBlock* movePos)
{
}

void BasicBlock::removeFromParent() const
{
}

void BasicBlock::removePredecessor(BasicBlock* pred, bool keepOneInputPhi)
{
}

void BasicBlock::replacePhiUsesWith(BasicBlock* o, BasicBlock* n)
{
}

BasicBlock* BasicBlock::splitBasicBlock(Instruction* insn, const core::String& name, bool before)
{
}

