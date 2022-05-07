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
 * File:   Modifiers.h
 * Author: Javier Marrero
 *
 * Created on March 23, 2022, 1:26 AM
 */

#ifndef MODIFIERS_H
#define MODIFIERS_H

// C fixed size integral types
#include <stdint.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

/**
 * This enumeration holds all the possible values for a variable modifier.
 */
typedef enum VariableModifiers
{
    VM_Constant = 0x1,
    VM_Final = 0x2,
    VM_Volatile = 0x4
} VariableModifiers;

/// The type used to store the modifiers of a variable.
typedef uint64_t VariableModifier;

/**
 * Lists all the possible function & method modifiers (not including access
 * modifiers, which are specific to classes)
 * 
 */
typedef enum MethodModifiers
{
    MM_Native = 0x1,
    MM_Volatile = 0x2,
    MM_Synchronized = 0x4
} MethodModifiers;

/// Function modifiers are just aliases for method modifiers
typedef enum MethodModifiers FunctionModifiers;

/// This type holds all the possible method modifiers
typedef uint64_t MethodModifier;

/// The same applies for functions
typedef MethodModifier FunctionModifier;

/**
 * Sets the value of a designated modifier to true (active) or false (inactive).
 * This is a template function & must be called passing the desired modifier
 * type as template parameter. This function is in-line and we should not incur
 * in any runtime penalty if using an in-lining compiler.
 *
 * @author J. Marrero
 */
template <typename T>
inline T setModifierValue(T value, T flag, bool active)
{
    T result = value;
    if (active)
    {
        result = value | flag;
    }
    else
    {
        result = value & (~flag);
    }
    return result;
}

}
}
}

#endif /* MODIFIERS_H */

