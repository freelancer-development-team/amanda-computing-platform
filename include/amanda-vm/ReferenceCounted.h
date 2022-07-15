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
 * File:   ReferenceCounted.h
 * Author: Javier Marrero
 *
 * Created on February 13, 2022, 2:34 PM
 */

#ifndef REFERENCECOUNTED_H
#define REFERENCECOUNTED_H

// C/C++
#include <stddef.h>
#include <stdint.h>
#include <map>

namespace amanda
{
namespace core
{

#define AMANDA_REFCOUNTED(ClassName) \
    public: \
        virtual size_t getClassSize() const \
        { \
            return sizeof(ClassName); \
        } \
    private:

/**
 * <code>ReferenceCounted</code> objects are objects managed by the framework's
 * memory utilities such as smart pointers and normal reference counting methods.
 *
 */
class ReferenceCounted
{
public:

    ReferenceCounted();
    virtual ~ReferenceCounted();

    long long       getReferenceCount() const;
    long long       getWeakReferenceCount() const;
    virtual size_t  getClassSize() const;
    void            grab() const;
    void            grabWeakReference() const;
    bool            isHeapAllocated() const;
    void            release() const;
    void            releaseWeakReference() const;

    void            operator delete(void* pointer);
    void*           operator new(size_t size);
    void*           operator new(size_t size, void* where);

private:

    bool                    heapAllocated;
    mutable long long       strongReferenceCount;
    mutable long long       weakReferenceCount;

} ;

}
}

#endif /* REFERENCECOUNTED_H */

