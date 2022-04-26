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
 * Created on April 19, 2022, 8:40 PM
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/Operand.h>
#include <amanda-vm/Binutils/vm-opcodes.h>
#include <amanda-vm/Binutils/vm-types.h>

namespace amanda
{
namespace binutils
{

/**
 * An instruction represents a virtual machine instruction. It can take zero or
 * one immediate operand whose size is explicitly specified and known at
 * assemble time. This class is mainly provided for serialization purposes but
 * it has also other applications within the virtual machine runtime.
 * <p>
 * This class must be able to encode an instruction into binary form and produce
 * the output in several forms for different consumers.
 *
 * @author J. Marrero
 */
class Instruction : public core::Object
{

    AMANDA_OBJECT(Instruction, core::Object)

public:

    enum
    {
        ZERO_OPERAND_SIZE = 0
    } ;

    static unsigned getInstructionNumericSuffix(char suffix);
    static unsigned getOperandSizeForSuffix(char suffix);

    Instruction(vm::VM_Opcode opcode, unsigned operandSize);

    size_t          encode(void* memory) const;
    bool            equals(vm::VM_Opcode opcode) const;
    vm::vm_byte_t   getOpcode() const;
    const Operand*  getOperand() const;
    size_t          getSize() const;
    bool            hasOperand() const;
    bool            isBranchInstruction() const;
    void            setOperand(Operand* operand);

private:

    vm::vm_byte_t   opcode;
    unsigned        operandSize;

    /**
     * Defines the immediate operand on which the instruction works.
     */
    core::StrongReference<Operand> operand;
} ;

}
}

#endif /* INSTRUCTION_H */

