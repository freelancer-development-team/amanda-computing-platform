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
 * File:   LocklessDefaultAllocator.h
 * Author: Javier Marrero
 *
 * Created on May 17, 2022, 3:00 PM
 */

#ifndef LOCKLESSDEFAULTALLOCATOR_H
#define LOCKLESSDEFAULTALLOCATOR_H

#include <amanda-vm/Runtime/MemoryAllocator.h>

// C++ API
#include <map>
#include <set>

namespace amanda
{
namespace vm
{

/**
 * This class implements a scalable & lock-less memory allocator for the
 * Amanda Virtual Machine. On initialization, it reclaims a determined number
 * of pages and then it builds a lock-less data structure that is used to
 * manage allocation/deallocation & coalescing.
 * <p>
 * Notice this is not a general purpose allocator, and it is intended to conform
 * with the contract of the <code>MemoryAllocator</code> class, used within
 * the Amanda runtime for memory management.
 *
 * @author J. Marrero
 */
class LocklessDefaultAllocator : public MemoryAllocator
{
    AMANDA_OBJECT(LocklessDefaultAllocator, MemoryAllocator)
public:

    LocklessDefaultAllocator(MemoryManager& memoryManager);
    virtual ~LocklessDefaultAllocator();

protected:

    

    virtual void                                        expandAddressSpace(size_t amount);
    virtual const MemoryAllocator::AllocationHeader&    find(size_t size) const;
    bool                                                hasFreeNodes() const;
    virtual bool                                        isNeedingExpansion() const;
    virtual void                                        insert(uintptr_t address, size_t size);

} ;

}
}

#endif /* LOCKLESSDEFAULTALLOCATOR_H */

