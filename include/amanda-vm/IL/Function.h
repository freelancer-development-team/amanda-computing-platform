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
 * Created on July 13, 2022, 10:12 PM
 */

#ifndef FUNCTION_H
#define FUNCTION_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IL/Type.h>
#include <amanda-vm/IL/Value.h>
#include <amanda-vm/IL/BasicBlock.h>

namespace amanda
{
namespace il
{

class Module;

/**
 * A function is one of the basic building blocks of a module. It allows to
 * seal functionality into a black-box unit that receives an input and produces
 * an output. This is the main unit of code reuse. This is language agnostic,
 * but basically, all the imperative languages provide some sort of
 * function-like object.
 * <p>
 * <code>Function</code> objects are subclasses of the <code>Value</code> class.
 *
 * @author J. Marrero
 */
class Function : public Value
{
    AMANDA_OBJECT(Function, Value)
public:

    static Function* create(const Type* type, const core::String& name = core::String::EMPTY,
                            Module* m = NULL);

    virtual ~Function();

    void                    deleteBody() const;
    BasicBlock&             front();
    const BasicBlock&       front() const;
    const BasicBlockList&   getBasicBlockList() const;
    BasicBlock&             getEntryBlock() const;
    const Type*             getReturnType() const;
    bool                    hasReturnValue() const;
    bool                    isVariadicFunction() const;
    virtual bool            isDeclaration() const;
    bool                    isThrowingExceptions() const;
    virtual void            removeFromParent();
    void                    setReturns(bool returns = false);
    void                    setThrowsExceptions(bool throws = false);

protected:

    BasicBlockList  basicBlocks;
    bool            returns;
    bool            throwsExceptions;
    bool            variadic;

    Function(const Type* type, const core::String& name, Module* m);

} ;

}
}

#endif /* FUNCTION_H */

