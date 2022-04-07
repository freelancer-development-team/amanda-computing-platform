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
 * File:   Function.h
 * Author: Javier Marrero
 *
 * Created on April 6, 2022, 8:19 PM
 */

#ifndef _AMANDA_BINUTILS_LD_FUNCTION_H
#define _AMANDA_BINUTILS_LD_FUNCTION_H

#include <amanda-vm/Binutils/Linker/Symbol.h>
#include <amanda-vm/Binutils/Assembler/Instruction.h>

// C++ STL
#include <vector>
#include <map>

namespace amanda
{
namespace binutils
{
namespace ld
{

/**
 * Functions are one of the levels of executable code organizations. Functions
 * have an entry point and a return point. Internally, at assembly level,
 * everything is a function since the virtual machine itself does not known
 * about objects, classes or methods (they are rather ABI conventions established
 * by the well defined runtime system).
 *
 * @author J. Marrero
 */
class Function : public Symbol
{
    AMANDA_OBJECT(Function, Symbol)
public:

    Function(const core::String& name);
    virtual ~Function();

    void            emit(as::Instruction* instruction);
    virtual void    marshall(io::OutputStream& stream);

private:

    std::vector<as::Instruction*> instructions;

    /**
     * Computes the size of a given function. This operation executes in O(1)
     * time.
     * 
     * @return
     */
    virtual sdk_ullong_t computeSize() const;
    
} ;

}
}
}

#endif /* FUNCTION_H */

