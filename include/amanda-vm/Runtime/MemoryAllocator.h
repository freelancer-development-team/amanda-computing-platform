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
 * File:   MemoryAllocator.h
 * Author: Javier Marrero
 *
 * Created on May 17, 2022, 2:51 PM
 */

#ifndef MEMORYALLOCATOR_H
#define MEMORYALLOCATOR_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Logging/Logger.h>
#include <amanda-vm/Runtime/MemoryManager.h>

namespace amanda
{
namespace vm
{

/**
 * This is an abstract class that implements the needed skeleton for different
 * memory allocation algorithms. This allows to implement different memory
 * allocation policies and switch amongst them on-the-fly.
 * <p>
 *
 * @author J. Marrero
 */
class MemoryAllocator : public core::Object
{

    AMANDA_OBJECT(MemoryAllocator, core::Object)

public:

    /**
     * An allocation header is a descriptor containing meta-data pertinent to
     * some memory allocation performed by the subclasses of this class. Since
     * what commonly changes among allocators is the subjacent data structure,
     * this class encapsulates common functionality which is shared amongst all
     * the memory allocator implementations.
     * <p>
     * Methods using instances of this class as parameters are usually fully
     * overridable by the allocator class, and therefore this class may be
     * extended in order to implement more obscure memory allocation techniques.
     *
     * @author J. Marrero
     */
    class AllocationHeader
    {
    public:

        // Friends
        friend class MemoryAllocator;

        static const AllocationHeader INVALID_ALLOCATION;

        AllocationHeader(uintptr_t address, size_t size);
        virtual ~AllocationHeader();

        int         compare(const AllocationHeader& rhs) const; /// Compares by address
        uintptr_t   getAddressAsInteger() const;
        void*       getAddressAsPointer() const;
        size_t      getSize() const;
        bool        isNull() const;
        bool        isUsed() const;
        void        setUsed(bool used);

    protected:

        uintptr_t   address;
        size_t      size;
        bool        used;
    } ;

    MemoryAllocator(MemoryManager& memoryManager);
    virtual ~MemoryAllocator();

    virtual void*           allocate(size_t size);
    virtual void*           allocateAligned(size_t size, size_t alignment);
    virtual void            deallocate(void* elem);
    const MemoryManager&    getMemoryManager() const;

protected:

    static const logging::Logger&   LOGGER;

    MemoryManager&                  memoryManager;
    std::vector<void*>              trackedAllocations;

    virtual size_t                  align(size_t size) const;                                                       /// Aligns to the default machine word
    size_t                          align(size_t size, size_t alignment) const;                                     /// Aligns to some specific value
    virtual AllocationHeader        coalesce(const AllocationHeader& h1, const AllocationHeader& h2) const;         /// Coalesce two adjacent blocks
    virtual void                    expandAddressSpace(size_t amount) = 0;
    virtual const AllocationHeader& find(size_t size) const = 0;                                                    /// Find a suitable block of size 'size'
    virtual bool                    isNeedingExpansion() const = 0;
    virtual AllocationHeader        split(const AllocationHeader& block, AllocationHeader& sp, size_t split) const; /// Splits a memory block.

} ;

}
}

#endif /* MEMORYALLOCATOR_H */

