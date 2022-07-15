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
 * File:   BasicBlock.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 3:22 PM
 */

#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IL/CodeGenContext.h>
#include <amanda-vm/IL/Value.h>

// C++
#include <vector>

namespace amanda
{
namespace il
{

class Function;
class Module;
class Instruction;

/**
 * <code>BasicBlock</code> represents a single basic block in the Amanda IL
 * representation. A basic block is simply a container of instructions that are
 * executed sequentially with no branches in except to the entry and no branches
 * out except at the exit. This restricted form makes a basic block highly
 * amenable to analysis. Compilers usually decompose programs into their basic
 * blocks as a first step in the analysis process. Basic blocks form the vertices
 * of nodes in a control-flow graph.
 * <p>
 * Basic blocks are considered <code>Value</code> subtypes because they may be
 * referenced by instructions such as branches and switch tables. The type of
 * a <code>BasicBlock</code> is a label, as they represents labels into which
 * a branch can jump.
 * <p>
 * Well formed basic blocks are formed of a list on non-terminating instructions
 * followed by a single terminator instruction. Terminator instructions may not
 * occur in the middle of basic blocks, and must terminate the blocks.
 *
 * @todo get value symbol table
 *
 * @author J. Marrero
 */
class BasicBlock : public Value
{
    AMANDA_OBJECT(BasicBlock, Value)

public:

    typedef std::vector<Instruction*>   InstListType;

    BasicBlock(CodeGenContext& context, const core::String& name = core::String::EMPTY,
               Function* parent = NULL, BasicBlock* insertBefore = NULL);
    virtual ~BasicBlock();

    bool                canSplitPredecessors() const;
    const Instruction*  getFirstNonPhi() const;
    const InstListType& getInstructionList() const;
    const Module*       getModule() const;
    const Function*     getParent() const;
    const BasicBlock*   getSinglePredecessor() const;
    const BasicBlock*   getSingleSuccessor() const;
    Instruction*        getTerminator() const;
    bool                hasAddressTaken() const;    /// Returns true if there are any uses of this basic block other than direct branches, switches, etc
    bool                hasPredecessors(unsigned n) const;
    bool                hasNPredecesorsOrMore(unsigned n) const;
    void                insertInto(Function* parent, BasicBlock* insertBefore = NULL);
    bool                isEntryBlock() const;
    bool                isExceptionHandler() const;
    void                moveAfter(BasicBlock* movePos);
    void                moveBefore(BasicBlock* movePos);
    void                removeFromParent() const;
    void                removePredecessor(BasicBlock* pred, bool keepOneInputPhi = false);
    BasicBlock*         splitBasicBlock(Instruction* insn, const core::String& name, bool before = false);
    BasicBlock*         splitBasicBlock(InstListType::iterator it, const core::String& name, bool before = false);
    void                replacePhiUsesWith(BasicBlock* o, BasicBlock* n);

protected:

    core::WeakReference<Module*>    module;
    core::WeakReference<Function*>  parent;

} ;

typedef std::vector<BasicBlock*> BasicBlockList;

}
}

#endif /* BASICBLOCK_H */

