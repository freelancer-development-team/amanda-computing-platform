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
 * File:   MemoryAllocator.cpp
 * Author: Javier Marrero
 * 
 * Created on May 17, 2022, 2:51 PM
 */

#include <amanda-vm/Runtime/MemoryAllocator.h>
#include <amanda-vm/Runtime/OutOfMemoryError.h>

// C
#include <assert.h>

using namespace amanda;
using namespace amanda::vm;

const logging::Logger& MemoryAllocator::LOGGER = logging::Logger::getLogger("amanda.vm.MemoryAllocator")->getConstReference();

MemoryAllocator::MemoryAllocator(MemoryManager& memoryManager)
:
memoryManager(memoryManager)
{
}

const MemoryManager& MemoryAllocator::getMemoryManager() const
{
    return memoryManager;
}

size_t MemoryAllocator::align(size_t size) const
{
    return align(size, sizeof (uintptr_t));
}

size_t MemoryAllocator::align(size_t size, size_t alignment) const
{
    return (size + alignment - 1) & ~(alignment - 1);
}

void* MemoryAllocator::allocate(size_t size)
{
    if (size == 0)
    {
        LOGGER.error("attempted allocation of a zero bit size block.");
        throw InvalidAllocationError("requested allocation of a zero bit size block");
    }

    // Align the address to word boundary
    size = align(size);

    //DEBUG, may remove later
    LOGGER.trace("attempting allocation of an %lluB bounded block.",
                 size);

    // Search for an available free block
    if (isNeedingExpansion())
    {
        LOGGER.trace("heap expansion needed, out of virtual memory.");

        // Expand the heap by size * 2
        expandAddressSpace(size * 2);
        if (isNeedingExpansion())
        {
            throw OutOfMemoryError();
        }
    }

    const AllocationHeader& header = find(size);
    if (header.isNull() == false)
    {
        return header.getAddressAsPointer();
    }
    return NULL;
}

void* MemoryAllocator::allocateAligned(size_t size, size_t alignment)
{
    return NULL;
}

MemoryAllocator::AllocationHeader MemoryAllocator::coalesce(const AllocationHeader& h1, const AllocationHeader& h2) const
{
    AllocationHeader header(h1.getAddressAsInteger(), h1.getSize());
    assert((h1.getAddressAsInteger() + h1.getSize()) != h2.getAddressAsInteger() && "Attempted to coalesce two non contiguous blocks.");

    // Set the basic properties
    header.used = false;

    // Coalesce
    header.size += h2.size;

    return header;
}

void MemoryAllocator::deallocate(size_t size)
{
}

MemoryAllocator::AllocationHeader MemoryAllocator::split(const AllocationHeader& block, AllocationHeader& sp, size_t split) const
{
    assert(split < block.size && "Attempting to split a block smaller than the split threshold.");

    // Split and create the result block
    AllocationHeader result(block.getAddressAsInteger(), split);

    // Set the properties of the sub-product
    sp.address = block.address + split;
    sp.size = block.size - split;
    sp.used = false;

    // Return the main block
    return result;
}

/* ========================== INTERNAL CLASS ================================ */

const MemoryAllocator::AllocationHeader MemoryAllocator::AllocationHeader::INVALID_ALLOCATION((uintptr_t) NULL, 0);

MemoryAllocator::AllocationHeader::AllocationHeader(uintptr_t address, size_t size)
:
address(address),
size(size),
used(false)
{
}

MemoryAllocator::AllocationHeader::~AllocationHeader()
{
}

int MemoryAllocator::AllocationHeader::compare(const AllocationHeader& rhs) const
{
    // Result variable
    int result;

    if (address < rhs.address)
    {
        result = -1;
    }
    else if (address == rhs.address)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }

    return result;
}

uintptr_t MemoryAllocator::AllocationHeader::getAddressAsInteger() const
{
    return address;
}

void* MemoryAllocator::AllocationHeader::getAddressAsPointer() const
{
    return reinterpret_cast<void*> (address);
}

size_t MemoryAllocator::AllocationHeader::getSize() const
{
    return size;
}

bool MemoryAllocator::AllocationHeader::isNull() const
{
    return getAddressAsPointer() == NULL;
}

bool MemoryAllocator::AllocationHeader::isUsed() const
{
    return used;
}

void MemoryAllocator::AllocationHeader::setUsed(bool used)
{
    this->used = used;
}

