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
 * File:   Use.h
 * Author: Javier Marrero
 *
 * Created on July 14, 2022, 12:53 PM
 */

#ifndef USE_H
#define USE_H

#include <amanda-vm/TypeSystem.h>

// C++
#include <vector>

namespace amanda
{
namespace il
{

class Value;
class ValueReferrer;

class Use : public core::Object
{
    AMANDA_OBJECT(Use, core::Object)
public:

    friend class Value;
    friend class ValueReferrer;

    Use();
    virtual ~Use();

    Value*          get() const;
    ValueReferrer*  getReferrer() const;
    void            set(Value* v);
    void            swap(Use& rhs);

    operator        Value* () const
    {
        return value;
    }

    Value*          operator= (Value* rhs);
    const Use&      operator= (const Use& rhs);
    Value*          operator->();
    const Value*    operator->() const;

private:

    core::WeakReference<ValueReferrer>  referrer;
    core::WeakReference<Value>          value;
} ;

/**
 * Define an alias for a list of uses.
 */
typedef std::vector<Use>        UseList;
typedef UseList::iterator       UseListIterator;
typedef UseList::const_iterator UseListConstIterator;

}
}

#endif /* USE_H */

