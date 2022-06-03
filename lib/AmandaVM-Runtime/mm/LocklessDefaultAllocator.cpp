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
 * File:   LocklessDefaultAllocator.cpp
 * Author: Javier Marrero
 * 
 * Created on May 17, 2022, 3:00 PM
 */

#include <amanda-vm/Runtime/LocklessDefaultAllocator.h>
#include <amanda-vm/Runtime/InvalidAllocationError.h>

// Concurrent kit
#include <ck_array.h>
#include <ck_epoch.h>
#include <ck_stack.h>
#include <ck_fifo.h>

// C API
#include <assert.h>

using namespace amanda;
using namespace amanda::vm;

LocklessDefaultAllocator::LocklessDefaultAllocator(MemoryManager& memoryManager)
:
super(memoryManager),
freeNodeCount(0),
nodeCount(0)
{
}

LocklessDefaultAllocator::~LocklessDefaultAllocator()
{
}

void LocklessDefaultAllocator::expandAddressSpace(size_t amount)
{
    // Get how many pages
    unsigned numberOfPages = (amount / memoryManager.querySystemPageSize()) > 0 ?
            (amount / memoryManager.querySystemPageSize()) : 1;
    unsigned size = numberOfPages * memoryManager.querySystemPageSize();

    // Request allocation for that space
    MemoryManager::MemoryDescriptor descriptor =
            memoryManager.allocateMemoryRegion(size, MemoryManager::WRITE | MemoryManager::READ);

    //DEBUG
    LOGGER.trace("Attempted allocation of %u pages. Allocated at 0x%p (system page size 0x%x)", numberOfPages,
            descriptor.pointer, memoryManager.querySystemPageSize());

    // Build the data structure partitioning the freshly allocated address space.

    // Increase the total number of nodes and the total free node count
    freeNodeCount++;
    nodeCount++;
}

const MemoryAllocator::AllocationHeader& LocklessDefaultAllocator::find(size_t size) const
{
    /*************************************************************************\
     * This memory allocator implements best-fit algorithm.                   *
     *                                                                        *
     * Constraints:                                                           *
     * 1- The best fit algorithm must adapt to the alignment constraints.     *
     *************************************************************************/
    const MemoryAllocator::AllocationHeader& result = MemoryAllocator::AllocationHeader::INVALID_ALLOCATION;

    return result;
}

bool LocklessDefaultAllocator::hasFreeNodes() const
{
    return freeNodeCount != 0;
}

bool LocklessDefaultAllocator::isNeedingExpansion() const
{
    return hasFreeNodes() == false;
}

/* ========================= INNER CLASS ==================================== */


LocklessDefaultAllocator::TreeNode::TreeNode(uintptr_t address, size_t size, TreeNode* root)
:
color(UNCOLORED),
data(address, size),
left(NULL),
parent(NULL),
right(NULL),
root(root)
{
}

LocklessDefaultAllocator::TreeNode* LocklessDefaultAllocator::TreeNode::rotateLeft()
{
    return this;
}

LocklessDefaultAllocator::TreeNode* LocklessDefaultAllocator::TreeNode::rotateRight()
{
    return this;
}


