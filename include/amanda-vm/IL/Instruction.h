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
 * File:   Instruction.h
 * Author: Javier Marrero
 *
 * Created on July 14, 2022, 6:53 PM
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IL/ValueReferrer.h>

namespace amanda
{
namespace il
{

class BasicBlock;
class Function;
class Module;

class Instruction : public il::ValueReferrer
{
    AMANDA_OBJECT(Instruction, ValueReferrer)
public:

    friend class BasicBlock;

    Instruction(const Type* type, unsigned iType, const UseList& operands, Instruction* insertBefore = NULL);
    Instruction(const Type* type, unsigned iType, const UseList& operands, BasicBlock* insertAtEnd);
    virtual ~Instruction();

    bool            comesBefore(const Instruction* other) const;
    Function*       getFunction() const;
    Module*         getModule() const;
    unsigned        getOpcode() const;
    const char*     getOpcodeName() const;
    BasicBlock*     getParent() const;
    void            insert(Instruction* insertPosition, bool before);
    virtual bool    isAssociative() const;
    virtual bool    isCommutative() const;
    virtual bool    isIdempotent() const;
    virtual bool    isNilpotent() const;
    bool            isExact() const;
    bool            isFast() const;
    virtual bool    isTerminator() const;
    virtual bool    isUnaryOperation() const;
    virtual bool    isBinaryOperation() const;
    virtual bool    isIntegerDivisionRemainder() const;
    virtual bool    isShift() const;
    virtual bool    isCast() const;
    virtual bool    isExceptionalTerminator() const;
    virtual bool    isOnlyUserOfAnyOperand() const;
    virtual bool    isLogicalShift() const;
    virtual bool    isArithmeticShift() const;
    virtual bool    isBitwiseLogicOp() const;
    virtual bool    hasMetadata() const;
    bool            hasAllocReassoc() const;
    bool            hasAllowContract() const;
    bool            hasApproxFunc() const;
    bool            hasNoNans() const;
    bool            hasNoInfs() const;
    bool            hasNoUnsignedWrap() const;
    bool            hasNoSignedWrap() const;
    bool            hasNoSignedZeros() const;
    void            move(Instruction* movePosition, bool before);
    void            removeFromParent();
    void            setExact(bool b = true);
    void            setFast(bool b);
    void            setHasAllowContract(bool b);
    void            setHasApproxFunction(bool b);
    void            setHasAllowReassoc(bool b);
    void            setHasNoUnsignedWrap(bool b = true);
    void            setHasNoSignedWrap(bool b = true);
    void            setHasNoNans(bool b);
    void            setHasNoInfs(bool b);
    void            setHasNoSignedZeros(bool b);

protected:

    struct
    {
        int allowc : 1;
        int approx : 1;
        int exact : 1;
        int fmath : 1;
        int ninfs : 1;
        int nnans : 1;
        int nuw : 1;
        int nsw : 1;
        int nsz : 1;
        int reassoc : 1;
    } __attribute__((packed)) flags;

    core::WeakReference<Function>   function;
    unsigned                        opcode;
    core::WeakReference<BasicBlock> parent;

private:

    /// This attribute represents the relative ordering in its parent block.
    /// used for O(1) access to the order
    unsigned order;
} ;

}
}

#endif /* INSTRUCTION_H */

