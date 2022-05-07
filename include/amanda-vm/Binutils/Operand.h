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
 * File:   Operand.h
 * Author: Javier Marrero
 *
 * Created on April 23, 2022, 7:36 PM
 */

#ifndef OPERAND_H
#define OPERAND_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/vm-types.h>

namespace amanda
{
namespace binutils
{

/**
 * <code>Operand</code> objects encapsulate the state of the operand of an
 * instruction throughout the assembly & linking process. Operands are constants
 * and its value cannot be changed during the life time of the object.
 * <p>
 * Currently, the assembler supports three types of operands, namely:
 * <ul>
 * <li>Symbolic constants</li> that are resolved either at link time or assembly time.
 * <li>Absolute values</li> representing numerical constants.
 * <li>Offset values</li> representing relative offsets within the executable image.
 * </ul>
 *
 * @author J. Marrero
 */
class Operand : public core::Object
{
    AMANDA_OBJECT(Operand, core::Object)
public:

    static unsigned getOperandSizeForInteger(sdk_ullong_t value);

    Operand(const core::String& symbolicName);
    Operand(const sdk_ullong_t value, const size_t size);
    Operand(const sdk_ullong_t value);

    size_t              getSize() const;
    const core::String& getSymbolicName() const;
    const void*         getValue() const;
    bool                isResolved() const;
    bool                isSymbol() const;
    virtual void        resolve(const sdk_ullong_t value, const size_t size);
    void                setSize(size_t size);

private:

    enum { CONSTANT, OFFSET, SYMBOL };

    bool            resolved;
    size_t          size;
    core::String    symbolicName;
    int             type;
    unsigned char   value[VM_QWORD_SIZE];

    void    initializeConsistentState();
} ;

}
}

#endif /* OPERAND_H */

