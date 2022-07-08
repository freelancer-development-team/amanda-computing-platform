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
 * File:   Function.cpp
 * Author: Javier Marrero
 * 
 * Created on April 17, 2022, 1:21 AM
 */

#include <amanda-vm/Binutils/Function.h>
#include <amanda-vm/Binutils/Logging.h>
#include <amanda-vm/Binutils/LinkException.h>

using namespace amanda;
using namespace amanda::binutils;

Function::Function(const core::String& name)
:
Symbol(name)
{
    setType(Symbol::Type_Function);
    setBindClass(Symbol::Bind_Global);

    // Reserve space for two possible labels
    labels.reserve(2);
}

Function::~Function()
{
    for (size_t i = 0; i < instructions.size(); ++i)
    {
        instructions[i]->release();
    }
    for (size_t i = 0; i < labels.size(); ++i)
    {
        labels[i]->release();
    }
}

void Function::addLabel(Label* label)
{
    assert(label != NULL && "Null pointer exception");

    //    getPackageLogger().info("Adding label %s : %llu",
    //                            label->getSymbolicName().toCharArray(), label->getOffset());

    // Push the label in the list of labels
    labels.push_back(label);

    // Grab a reference to the label
    label->grab();
}

void Function::constructBinaryData()
{
    for (size_t i = 0; i < instructions.size(); ++i)
    {
        Instruction* insn = instructions.at(i);
        if (insn->isBranchInstruction())
        {
            // Attempt to resolve the local branch target
            // It has to be a local branch target
            if (insn->getOperand()->isSymbol())
            {
                const Operand* operand = insn->getOperand();
                if (operand->isResolved() == false)
                {
                    Label* label = NULL;
                    for (unsigned i = 0; i < labels.size(); ++i)
                    {
                        if (labels.at(i)->getSymbolicName() == operand->getSymbolicName())
                        {
                            label = labels.at(i);
                        }
                    }

                    // Throw an exception if we are unable to determinate the
                    // branch instruction target
                    if (label == NULL)
                    {
                        getPackageLogger().error("invalid branch target. Undefined reference to local branch '%s'.",
                                                 operand->getSymbolicName().toCharArray());
                    }

                    // We have resolved the symbol.
                    // Now the operand should contain the value of the offset.
                    eliminateConstness(operand)->resolve(label->getOffset(), VM_ADDRESS_SIZE);
                }
            }
            else if (insn->equals(AMANDA_VM_INSN_SINGLE(INVOKE)))
            {
                // If the symbol is unresolved by this time, we're doing something
                // quite wrong pal. Symbols must be resolved when the function
                // is exported, except for local conditional branch targets.
                const Operand* operand = insn->getOperand();
                if (operand->isResolved() == false)
                {
                    throw LinkException("unresolved symbol", *this);
                }
            }
        }

        unsigned char encoded[insn->getSize()] = {0};
        insn->encode(encoded);
        write(encoded, VM_BYTE_SIZE, insn->getSize());
    }
}

void Function::emit(Instruction* insn)
{
    assert(insn != NULL && "Null pointer exception.");

    if (insn->is<Label>() == false)
    {
        instructions.push_back(insn);

        // Grab a reference to the object. The reference is owned by the function.
        insn->grab();

        // Update the function size
        setSize(getSize());
    }
    else
    {
        addLabel((Label*) insn);
    }
}

const std::deque<Instruction*>& Function::getInstructions() const
{
    return instructions;
}

size_t Function::getSize() const
{
    size_t result = 0;
    for (size_t i = 0; i < instructions.size(); ++i)
    {
        result += instructions[i]->getSize();
    }

    return result;
}




