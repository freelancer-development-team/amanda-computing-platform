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
 * File:   Value.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 3:36 PM
 */

#ifndef VALUE_H
#define VALUE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IL/Type.h>

namespace amanda
{
namespace il
{

class BasicBlock;
class CodeGenContext;
class ValueReferrer;
class ValueListener;

/**
 * The <code>Value</code> class is the base class for the object hierarchy
 * comprising the compiler's intermediate representation. It represents all
 * the possible values computed by a program that may be used as operands to
 * other values. <code>Value</code> is the base class of other classes such as
 * <code>Instruction</code> and <code>Function</code>. All values have a
 * <code>Type</code> that represents its static type at compile time. All
 * types have a name and they belong to some compilation unit, known as
 * <code>Module</code>. Setting the name on the value updates its reference in
 * the <code>Module</code>'s symbol table.
 * <p>
 * Every value has a list that keeps track of which other values are using this
 * value. A Value can also have an arbitrary number of <code>Listener</code>
 * objects that can receive events.
 *
 * @author J. Marrero
 */
class Value : public core::Object
{
    AMANDA_OBJECT(Value, core::Object)

public:

    typedef std::vector<ValueListener*>                 ListenerList;
    typedef std::vector<ValueReferrer*>                 ReferrerList;
    typedef std::vector<ValueReferrer*>::iterator       ReferrerListIterator;
    typedef std::vector<ValueReferrer*>::const_iterator ReferrerListConstIterator;

    virtual ~Value();

    void                clearMetadata();
    CodeGenContext&     getContext() const;
    const core::String& getName() const;
    unsigned            getNumberOfUsers() const;
    const Type*         getType() const;
    unsigned            getValueId() const;
    bool                hasName() const;
    bool                hasNUsesOrMore(const unsigned n) const;
    bool                hasValueListener() const;
    bool                isUsedInBasicBlock(const BasicBlock* basicBlock) const;
    bool                isUsed(const unsigned n) const;
    bool                isUniquelyUsed() const;
    bool                isUseListEmpty() const;
    void                setName(const core::String& name);
    void                takeName(Value* v);
    void                replaceAllUsesWith(Value* v);

protected:

    unsigned                            id;
    ListenerList                        listeners;  //TODO: Fix
    core::String                        name;
    core::StrongReference<const Type>   type;
    ReferrerList                        users;

    Value(const Type* type, unsigned scid);
} ;

}
}

#endif /* VALUE_H */

