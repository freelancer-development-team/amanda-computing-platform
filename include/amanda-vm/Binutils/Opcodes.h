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
 */
typedef enum VM_Opcodes
{
    // Data type conversion

    // Arithmetic
    I_ADDB,
    I_ADDW,
    I_ADDL,
    I_ADDQ,
    I_SUBB,
    I_SUBW,
    I_SUBL,
    I_SUBQ,
    // Stack manipulation
} VM_Opcodes;

/**
 * Instruction codes are 8-bit unsigned integers without exception. There is no
 * variable instruction length.
 */
typedef uint8_t VM_Opcode;

}
}

#endif /* INSTRUCTIONS_H */

