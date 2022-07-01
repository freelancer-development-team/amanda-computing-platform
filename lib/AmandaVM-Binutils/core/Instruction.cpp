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
 * File:   Instruction.cpp
 * Author: Javier Marrero
 * 
 * Created on April 19, 2022, 8:40 PM
 */

#include <amanda-vm/Binutils/Instruction.h>
#include <amanda-vm/IO/MemoryOutputStream.h>
#include <amanda-vm/IO/ConsistentOutputStream.h>

// C++
#include <cctype>

using namespace amanda;
using namespace amanda::binutils;

unsigned Instruction::getInstructionNumericSuffix(char suffix)
{
    suffix = toupper(suffix);
    switch (suffix)
    {
        case 'B':
            return 0u;
            break;
        case 'W':
            return 1u;
            break;
        case 'L':
            return 2u;
            break;
        case 'Q':
            return 3u;
            break;
        case 'F':
            return 4u;
            break;
        case 'D':
            return 5u;
            break;
        case 'A':
            return 6u;
            break;
        case 'V':
            return 7u;
            break;
        default:
            return 0u;
            break;
    }
}

unsigned Instruction::getOperandSizeForSuffix(char suffix)
{
    suffix = toupper(suffix);
    switch (suffix)
    {
        case 'B':
            return VM_BYTE_SIZE;
            break;
        case 'W':
            return VM_WORD_SIZE;
            break;
        case 'L':
            return VM_DWORD_SIZE;
            break;
        case 'Q':
            return VM_QWORD_SIZE;
            break;
        case 'F':
            return VM_FLOAT32_SIZE;
            break;
        case 'D':
            return VM_FLOAT64_SIZE;
            break;
        case 'A':
            return VM_ADDRESS_SIZE;
            break;
        default:
            return ZERO_OPERAND_SIZE;
    }
}

Instruction::Instruction(vm::VM_Opcode opcode, unsigned operandSize)
:
opcode((vm::vm_byte_t) opcode),
operandSize(operandSize)
{
    assert(opcode >= 0 && opcode <= 0xFF && "opcode number must be between zero & 255.");
}

size_t Instruction::encode(void* memory) const
{
    io::MemoryOutputStream mstream(memory);
    io::ConsistentOutputStream stream(mstream);

    stream.write(&opcode, VM_BYTE_SIZE);

    //TODO: Write the value
    if (!operand.isNull())
    {
        const void* immediateOperand = operand->getValue();
        assert(immediateOperand != NULL && "Null pointer exception.");

        stream.write(immediateOperand, operandSize);
    }
    return VM_BYTE_SIZE + operandSize;
}

bool Instruction::equals(vm::VM_Opcode opcode) const
{
    return this->opcode == (vm::vm_byte_t) opcode;
}

vm::vm_byte_t Instruction::getOpcode() const
{
    return opcode;
}

const Operand* Instruction::getOperand() const
{
    return operand;
}

size_t Instruction::getSize() const
{
    return VM_BYTE_SIZE + operandSize;
}

bool Instruction::hasOperand() const
{
    return operandSize != 0;
}

bool Instruction::isBranchInstruction() const
{
    using namespace amanda::vm;

    bool result = false;
    switch (opcode)
    {
        case I_JMP:
        case I_JT:
        case I_JF:
            result = true;
            break;
        default:
            result = false;
            break;
    }
    return result;
}

void Instruction::setOperand(Operand* operand)
{
    assert(operand != NULL && "Operand is null");
    this->operand = operand;
}
