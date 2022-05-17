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
 * File:   MemoryManager.cpp
 * Author: Javier Marrero
 * 
 * Created on May 17, 2022, 1:14 AM
 */

#include <amanda-vm/Runtime/MemoryManager.h>
#include <amanda-vm/Runtime/SegmentationFault.h>
#include <amanda-vm/Runtime/InvalidAllocationError.h>
#include <amanda-vm/Runtime/OutOfMemoryError.h>

#ifdef _W32
#    include <memoryapi.h>
#endif

using namespace amanda;
using namespace amanda::vm;

// WARNING: Architecture dependent definition
#include <amanda-vm-c/sdk-definitions.h>
#include <errhandlingapi.h>
#include <winerror.h>

#if SDK_CPU_ARCHITECTURE == ARCH_i386 || SDK_CPU_ARCHITECTURE == ARCH_AMD64
#    define _DEFAULT_PAGE_SIZE    0x1000
#endif

const vm::vm_size_t MemoryManager::DEFAULT_PAGE_SIZE = _DEFAULT_PAGE_SIZE;

vm::vm_size_t MemoryManager::querySystemPageSize()
{
    vm::vm_size_t size = DEFAULT_PAGE_SIZE;
#if defined(_W32)

#endif

    return size;
}

MemoryManager::MemoryManager(vm::vm_size_t allocationLimit)
:
allocatedSpace(0),
allocationLimit(allocationLimit >= MINIMUM_ALLOCATION_LIMIT ? allocationLimit : MINIMUM_ALLOCATION_LIMIT)
{
}

MemoryManager::~MemoryManager()
{
    for (std::map<const void*, MemoryDescriptor>::const_iterator it = descriptors.begin(),
         end = descriptors.end(); it != end; ++it)
    {
        deallocateMemoryRegion(it->second);
    }
}

MemoryManager::MemoryDescriptor MemoryManager::allocateMemoryRegion(size_t size, Attributes attributes)
{
    void* pointerToRegion = NULL;
    if (allocatedSpace + size > allocationLimit)
    {
        throw OutOfMemoryError();
    }

    // Synchronization lock (calls to the allocator must be synchronized)
    AMANDA_SYNCHRONIZED(lock);
    {
        // WARNING ++ WARNING ++ WARNING ++ WARNING
        // OS-SPECIFIC CODE
#if defined(_W32)

        DWORD flags = 0;
        if (attributes & READ)
        {
            if (attributes & WRITE)
            {
                flags = PAGE_READWRITE;
            }
            else
            {
                flags = PAGE_READONLY;
            }
        }
        if (attributes & EXECUTE)
        {
            flags |= PAGE_EXECUTE;
        }

        pointerToRegion = VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE,
                flags);
        if (pointerToRegion == NULL)
        {
            DWORD error = GetLastError();
            if (error == ERROR_INVALID_ADDRESS)
            {
                throw InvalidAllocationError("Invalid allocation");
            }
            else
            {
                throw OutOfMemoryError();
            }
        }
#else
#    error "There's no warranty that the allocated memory area contains memory with the requested attributes."
#endif

        // Increase the allocated space by the size amount
        allocatedSpace += size;
    }
    AMANDA_DESYNCHRONIZED(lock);

    // Create the memory descriptor
    MemoryDescriptor descriptor = {attributes, pointerToRegion, size};

    // Add the descriptor to the map of descriptors & return
    descriptors.insert(std::make_pair(descriptor.pointer, descriptor));
    return descriptor;
}

void MemoryManager::deallocateMemoryRegion(const MemoryDescriptor& descriptor)
{
    if (allocatedSpace < descriptor.size || descriptor.pointer == NULL)
    {
        throw InvalidAllocationError("The system attempted to deallocate unallocated memory.");
    }

    AMANDA_SYNCHRONIZED(lock);
    {
#if defined(_W32)
        if (!VirtualFree(const_cast<LPVOID> (descriptor.pointer), 0, MEM_DECOMMIT | MEM_RELEASE))
        {
            throw InvalidAllocationError(
                    core::String::makeFormattedString("The system was unable to release memory at address 0x%p",
                    descriptor.pointer));
        }
#else
#    error "Unable to employ deallocation algorithm."
#endif

        // Decrease the allocated space counter
        allocatedSpace -= descriptor.size;
    }
    AMANDA_DESYNCHRONIZED(lock);

    // Remove the descriptor from the map
    descriptors.erase(descriptor.pointer);
}

const MemoryManager::MemoryDescriptor& MemoryManager::findDescriptorForPointer(const void* pointer) const
{
    std::map<const void*, MemoryDescriptor>::const_iterator found = descriptors.find(pointer);
    if (found != descriptors.end())
    {
        return found->second;
    }

    // Throw a segmentation fault
    throw SegmentationFault("Access violation", pointer);
}

vm::vm_size_t MemoryManager::getAllocationLimit() const
{
    return allocationLimit;
}

vm::vm_size_t MemoryManager::getFreeMemory() const
{
    return allocationLimit - allocatedSpace;
}

vm::vm_size_t MemoryManager::getUsedMemory() const
{
    return allocatedSpace;
}

void MemoryManager::setAllocationLimit(vm::vm_size_t newLimit)
{
    if (newLimit < MINIMUM_ALLOCATION_LIMIT)
        newLimit = MINIMUM_ALLOCATION_LIMIT;
    this->allocationLimit = newLimit;
}
