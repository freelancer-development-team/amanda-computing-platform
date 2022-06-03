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
 * File:   MemoryManager.h
 * Author: Javier Marrero
 *
 * Created on May 17, 2022, 1:14 AM
 */

#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/vm-types.h>

// C++ STL
#include <map>

namespace amanda
{
namespace vm
{

/**
 * The memory manager class handles memory access at virtual machine level.
 * Notice this is not a memory allocator, rather a sort of security-enforcing
 * mechanism in order to guarantee memory protection.
 * 
 */
class MemoryManager : public core::Object
{

    AMANDA_OBJECT(MemoryManager, core::Object)

public:

    /**
     * Memory capabilities attributes.
     */
    typedef enum Attributes
    {
        READ = 1,
        WRITE = 2,
        EXECUTE = 4
    } Attributes;

    /**
     * A memory descriptor object.
     */
    typedef struct MemoryDescriptor
    {
        vm::vm_byte_t       attributes;
        const void* const   pointer;
        vm::vm_size_t       size;
    } MemoryDescriptor;

    static const vm::vm_size_t  DEFAULT_PAGE_SIZE;
    static const vm::vm_size_t  MINIMUM_ALLOCATION_LIMIT = 0x40000; /// Minimum space that the allocator can restrict the virtual machine to (4MB)
    static const vm::vm_size_t  NO_ALLOCATION_LIMIT = 0xFFFFFFFFFFFFFFFFull;

    static vm::vm_size_t        querySystemPageSize();

    MemoryManager(vm::vm_size_t allocationLimit = MINIMUM_ALLOCATION_LIMIT);
    virtual ~MemoryManager();

    virtual MemoryDescriptor    allocateMemoryRegion(size_t size, int attributes);
    virtual void                deallocateMemoryRegion(const MemoryDescriptor& descriptor);
    const MemoryDescriptor&     findDescriptorForPointer(const void* __restrict__ pointer) const;
    vm::vm_size_t               getAllocationLimit() const;
    vm::vm_size_t               getFreeMemory() const;
    vm::vm_size_t               getUsedMemory() const;
    void                        setAllocationLimit(vm::vm_size_t newLimit);

protected:

    vm::vm_size_t                           allocatedSpace;
    vm::vm_size_t                           allocationLimit;
    std::map<const void*, MemoryDescriptor> descriptors;
    
} ;

}
}

#endif /* MEMORYMANAGER_H */

