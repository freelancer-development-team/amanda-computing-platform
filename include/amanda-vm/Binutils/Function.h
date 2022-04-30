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
 * Created on April 17, 2022, 1:21 AM
 */

#ifndef AMANDA_FUNCTION_H
#define AMANDA_FUNCTION_H

#include <amanda-vm/Binutils/Symbol.h>
#include <amanda-vm/Binutils/Instruction.h>
#include <amanda-vm/Binutils/Label.h>

// C++
#include <deque>
#include <vector>

namespace amanda
{
namespace binutils
{

/**
 * A <code>Function</code> is a special kind of symbol with the ability to emit
 * byte code (instructions).
 *
 * @author J. Marrero
 */
class Function : public Symbol
{
    AMANDA_OBJECT(Function, Symbol)
public:

    Function(const core::String& name);
    virtual ~Function();

    void                            addLabel(Label* label);
    virtual void                    constructBinaryData();
    void                            emit(Instruction* insn);
    const std::deque<Instruction*>& getInstructions() const;
    size_t                          getSize() const;

private:

    std::deque<Instruction*>    instructions;
    std::vector<Label*>         labels;
} ;

}
}

#endif /* FUNCTION_H */

