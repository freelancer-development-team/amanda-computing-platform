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
 * File:   _tokens.h
 * Author: Javier Marrero
 *
 * Created on April 2, 2022, 2:38 AM
 */

#ifndef _TOKENS_H
#define _TOKENS_H

#include <amanda-vm/Binutils/VirtualMachineSpecs.h>
#include <amanda-vm/Binutils/Opcodes.h>

namespace amanda
{
namespace binutils
{
namespace as
{

typedef enum Tokens
{
    __TOKEN_MINIMUM = 0xff,
    TOKEN_ATTRIBUTES,
    TOKEN_DEF,
    TOKEN_ENDEF,
    TOKEN_IDENTIFIER,
    TOKEN_SECTION,
    TOKEN_STRING,
    TOKEN_INTEGER,
    // Instructions
    // Binary operations
    __TOKEN_BINARY_MIN,
    TOKEN_PUSH,
    __TOKEN_BINARY_MAX,
    // Unary operations
    __TOKEN_UNARY_MIN,
    // Arithmetic
    TOKEN_ADD,
    TOKEN_SUB,
    TOKEN_DIV,
    TOKEN_MUL,
    TOKEN_POP,
    TOKEN_RET,
    __TOKEN_UNARY_MAX,
    // Instruction prefixes
    TOKEN_SUFFIX_BYTE,
    TOKEN_SUFFIX_WORD,
    TOKEN_SUFFIX_LONG,
    TOKEN_SUFFIX_QUAD,
    TOKEN_SUFFIX_FLOAT,
    TOKEN_SUFFIX_DOUBLE
}
Tokens;

#define AMANDA_ICONV_NO_SUFFIX  -1

static inline const vm::vm_byte_t tokenToInstruction(int token, int suffix)
{
    vm::vm_byte_t insn = vm::I_INVALID;
    switch (token)
    {
    case TOKEN_RET:
        insn = vm::I_RETB - 1;
        break;
    }
    switch (suffix)
    {
    case AMANDA_ICONV_NO_SUFFIX:
        break;
    case TOKEN_SUFFIX_BYTE:
        ++insn;
        break;
    case TOKEN_SUFFIX_WORD:
        insn += 2;
        break;
    case TOKEN_SUFFIX_LONG:
        insn += 3;
        break;
    case TOKEN_SUFFIX_QUAD:
        insn += 4;
        break;
    case TOKEN_SUFFIX_FLOAT:
        insn += 5;
        break;
    case TOKEN_SUFFIX_DOUBLE:
        insn += 6;
        break;
    }
    return insn;
}

}
}
}

#endif /* _TOKENS_H */

