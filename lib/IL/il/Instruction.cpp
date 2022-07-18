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
 * File:   Instruction.cpp
 * Author: Javier Marrero
 * 
 * Created on July 14, 2022, 6:53 PM
 */

#include <amanda-vm/IL/Instruction.h>
#include <amanda-vm/IL/Module.h>
#include <amanda-vm/IL/BasicBlock.h>

using namespace amanda;
using namespace amanda::il;

Instruction::Instruction(const Type* type, unsigned iType, const UseList& operands, Instruction* insertBefore)
:
ValueReferrer(type, iType, operands)
{
}

Instruction::Instruction(const Type* type, unsigned iType, const UseList& operands, BasicBlock* insertAtEnd)
:
ValueReferrer(type, iType, operands)
{
}

Instruction::~Instruction()
{
}

bool Instruction::comesBefore(const Instruction* other) const
{
}

Function* Instruction::getFunction() const
{
    return function;
}

Module* Instruction::getModule() const
{
    Module* result = NULL;
    if (function.isNotNull())
    {

    }
    return result;
}

unsigned Instruction::getOpcode() const
{
    return opcode;
}

const char* Instruction::getOpcodeName() const
{
}

BasicBlock* Instruction::getParent() const
{
    return parent;
}

bool Instruction::hasAllocReassoc() const
{
    return flags.reassoc;
}

bool Instruction::hasAllowContract() const
{
    return flags.allowc;
}

bool Instruction::hasApproxFunc() const
{
    return flags.approx;
}

bool Instruction::hasMetadata() const
{
    //TODO: Implement
    return false;
}

bool Instruction::hasNoInfs() const
{
    return flags.ninfs;
}

bool Instruction::hasNoNans() const
{
    return flags.nnans;
}

bool Instruction::hasNoSignedWrap() const
{
    return flags.nsw;
}

bool Instruction::hasNoSignedZeros() const
{
    return flags.nsz;
}

bool Instruction::hasNoUnsignedWrap() const
{
    return flags.nuw;
}

void Instruction::insert(Instruction* insertPosition, bool before)
{

}

bool Instruction::isArithmeticShift() const
{

}

bool Instruction::isAssociative() const
{
}

bool Instruction::isBinaryOperation() const
{
}

bool Instruction::isBitwiseLogicOp() const
{
}

bool Instruction::isCast() const
{
}

bool Instruction::isCommutative() const
{
}

bool Instruction::isExact() const
{
    return flags.exact;
}

bool Instruction::isExceptionalTerminator() const
{
}

bool Instruction::isFast() const
{
    return flags.fmath;
}

bool Instruction::isIdempotent() const
{
}

bool Instruction::isIntegerDivisionRemainder() const
{
}

bool Instruction::isLogicalShift() const
{
}

bool Instruction::isNilpotent() const
{
}

bool Instruction::isOnlyUserOfAnyOperand() const
{
}

bool Instruction::isShift() const
{
}

bool Instruction::isTerminator() const
{
}

bool Instruction::isUnaryOperation() const
{
}

void Instruction::move(Instruction* movePosition, bool before)
{
}

void Instruction::removeFromParent()
{
}

void Instruction::setExact(bool b)
{
    flags.exact = b;
}

void Instruction::setFast(bool b)
{
    flags.fmath = b;
}

void Instruction::setHasAllowContract(bool b)
{
    flags.allowc = b;
}

void Instruction::setHasAllowReassoc(bool b)
{
    flags.reassoc = b;
}

void Instruction::setHasApproxFunction(bool b)
{
    flags.approx = b;
}

void Instruction::setHasNoInfs(bool b)
{
    flags.ninfs = b;
}

void Instruction::setHasNoNans(bool b)
{
    flags.nnans = b;
}

void Instruction::setHasNoSignedWrap(bool b)
{
    flags.nsw = b;
}

void Instruction::setHasNoSignedZeros(bool b)
{
    flags.nsz = b;
}

void Instruction::setHasNoUnsignedWrap(bool b)
{
    flags.nuw = b;
}




















