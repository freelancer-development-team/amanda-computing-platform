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

// C API
#include <assert.h>

using namespace amanda;
using namespace amanda::vm;

LocklessDefaultAllocator::LocklessDefaultAllocator(MemoryManager& memoryManager)
:
super(memoryManager)
{
}

LocklessDefaultAllocator::~LocklessDefaultAllocator()
{
}

void* LocklessDefaultAllocator::allocate(size_t size)
{
    return NULL;
}

void* LocklessDefaultAllocator::allocateAligned(size_t size, size_t alignment)
{
    return NULL;
}

void LocklessDefaultAllocator::deallocate(size_t size)
{
}





