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
 * File:   Label.h
 * Author: Javier Marrero
 *
 * Created on April 24, 2022, 1:26 PM
 */

#ifndef _AMANDA_BINUTILS_LABEL_H
#define _AMANDA_BINUTILS_LABEL_H

#include <amanda-vm/Binutils/Instruction.h>

namespace amanda
{
namespace binutils
{

/**
 * The label class represents a special kind of instruction: a marker in the
 * assembler source code that allows symbolic naming of a particular address.
 * Labels carry associated a symbolic name, and they are always part of a function.
 * <p>
 * Labels also have associated an integer offset that represents the offset
 * since the function head, counting from zero onwards.
 *
 * @author J. Marrero
 */
class Label : public Instruction
{
    AMANDA_OBJECT(Label, Instruction)
public:

    Label(const core::String& symbolicName, vm::vm_address_t offset);
    virtual ~Label();

    vm::vm_address_t    getOffset() const;
    const core::String& getSymbolicName() const;

private:

    vm::vm_address_t    offset;
    core::String        symbolicName;
} ;

}
}

#endif /* LABEL_H */

