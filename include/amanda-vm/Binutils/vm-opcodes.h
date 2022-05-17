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
 * File:   Instructions.h
 * Author: Javier Marrero
 *
 * Created on March 24, 2022, 8:21 PM
 */

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdint.h>

namespace amanda
{
namespace vm
{

/**
 * These are constants for byte-code
 */
typedef enum VM_BytecodeConstants
{
} VM_BytecodeConstants;

/**
 * This is a listing of all the possible opcodes for the virtual machine. Each
 * instruction operates on a well defined data type, namely:
 * <ul>
 * <li>Integral types of different (fixed) size.</li>
 * <li>Floating point types (IEEE standard).</li>
 * <li>Pointer types (for addresses)</li>
 * </ul>
 * The integral types are of the following sizes (and these are their suffixes):
 * <ul>
 * <li>8-bit, suffix: <i>b</i></li>
 * <li>16-bit, suffix: <i>w</i></li>
 * <li>32-bit, suffix: <i>l</i></li>
 * <li>64-bit, suffix: <i>q</i></li>
 * </ul>
 * Floating point types are 32bit and 64bit IEEE floating point, and their
 * instruction suffixes are:
 * <ul>
 * <li>32-bit IEEE: <i>f</i></li>
 * <li>64-bit IEEE: <i>d</i></li>
 * </ul>
 * Pointer types are 64-bit unsigned quantities, and they are used exactly as
 * the quad words.
 */
typedef enum VM_Opcodes
{
    // Reserved
    I_NOP = 0,
    I_HALT,

    // Data type conversion
    I_B2W,
    I_B2L,
    I_B2Q,
    I_B2F,
    I_B2D,

    I_W2L,
    I_W2Q,
    I_W2F,
    I_W2D,

    I_L2Q,
    I_L2F,
    I_L2D,

    I_Q2F,
    I_Q2D,

    I_F2B,
    I_F2W,
    I_F2L,
    I_F2Q,
    I_F2D,

    I_D2B,
    I_D2W,
    I_D2L,
    I_D2Q,
    I_D2F,

    // Arithmetic
    I_ADDB,
    I_ADDW,
    I_ADDL,
    I_ADDQ,
    I_ADDF,
    I_ADDD,

    I_SUBB,
    I_SUBW,
    I_SUBL,
    I_SUBQ,
    I_SUBF,
    I_SUBD,

    I_MULB,
    I_MULW,
    I_MULL,
    I_MULQ,
    I_MULF,
    I_MULD,

    I_DIVB,
    I_DIVW,
    I_DIVL,
    I_DIVQ,
    I_DIVF,
    I_DIVD,

    I_MODB,
    I_MODW,
    I_MODL,
    I_MODQ,
    I_MODF,
    I_MODD,
    // Stack manipulation
    I_PUSHB,
    I_PUSHW,
    I_PUSHL,
    I_PUSHQ,
    I_PUSHF,
    I_PUSHD,
    I_PUSHA,

    I_POPB,
    I_POPW,
    I_POPL,
    I_POPQ,
    I_POPF,
    I_POPD,
    I_POPA,

    // Comparison
    I_CEQB,
    I_CEQW,
    I_CEQL,
    I_CEQQ,
    I_CEQF,
    I_CEQD,

    I_CNEB,
    I_CNEW,
    I_CNEL,
    I_CNEQ,
    I_CNEF,
    I_CNED,

    I_CGT,
    I_CLT,
    I_CGE,
    I_CLE,

    // Flow control
    I_INVOKE,
    I_CCALL,
    I_JMP,
    I_JT,
    I_JF,

    I_RETB,
    I_RETW,
    I_RETL,
    I_RETQ,
    I_RETF,
    I_RETD,

    // Memory access
    I_ALLOC,
    I_DELLOC,
    I_LOAD,

    I_STOREB,
    I_STOREW,
    I_STOREL,
    I_STOREQ,
    I_STOREF,
    I_STORED,

    // Reserved
    I_INVALID = 0xFF
} VM_Opcodes;

/**
 * This macro retrieves an opcode number given the family prefix and the
 * instruction suffix.
 */
#define AMANDA_VM_ENCODE_INSN(F, S) amanda::vm::I_ ## F ## S

#define AMANDA_VM_INSN_SINGLE(F)    amanda::vm::I_ ## F
#define AMANDA_VM_INSN_FAMILY(F)    amanda::vm::I_ ## F ## B

/**
 * Instruction codes are 8-bit unsigned integers without exception. There is no
 * variable instruction length. This enhances the simplicity in the design and
 * implementation of the virtual machine. The virtual machine fetches an opcode
 * and its immediate operand and does not have to worry much for decoding the
 * instruction.
 */
typedef uint8_t VM_Opcode;

}
}

#endif /* INSTRUCTIONS_H */

