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
 * File:   Pointer.h
 * Author: Javier Marrero
 *
 * Created on February 17, 2022, 3:40 PM
 */

#ifndef POINTER_H
#define POINTER_H

#include <amanda-vm/Object.h>

#include <cassert>

namespace amanda
{
namespace core
{

template <class T>
class AutomaticReferenceBase : public Object
{
    AMANDA_OBJECT(AutomaticReferenceBase, Object)

public:

    AutomaticReferenceBase() : pointer(NULL) { }
    AutomaticReferenceBase(T* pointer) : pointer(pointer) {}
    AutomaticReferenceBase(const AutomaticReferenceBase<T>& rhs) : pointer(rhs.pointer) { }
    virtual ~AutomaticReferenceBase() {}

    T*      get() const { return pointer; }
    bool    isNull() const { return pointer == NULL; }

    operator bool()                                             { return pointer != NULL; }
    T*      operator->()                                        { return pointer; }
    bool    operator==(const AutomaticReferenceBase<T>& rhs)    { return pointer == rhs.pointer; }
    bool    operator==(const T* rhs)                            { return pointer == rhs; }

protected:

    T*  pointer;
} ;

template <class T>
class StrongReference : public AutomaticReferenceBase<T>
{
    AMANDA_OBJECT(StrongReference, AutomaticReferenceBase<T>);

public:

    StrongReference() : AutomaticReferenceBase<T>() { }
    StrongReference(T* pointer) : AutomaticReferenceBase<T>(pointer) { increaseReference(); }
    StrongReference(const StrongReference<T>& rhs) : AutomaticReferenceBase<T>(rhs) { increaseReference(); }
    virtual ~StrongReference() { decreaseReference(); }

protected:

    void increaseReference()  { if (this->pointer != NULL) this->pointer->grab(); }
    void decreaseReference()  { if (this->pointer != NULL) this->pointer->release(); }
};

}
}

#endif /* POINTER_H */

