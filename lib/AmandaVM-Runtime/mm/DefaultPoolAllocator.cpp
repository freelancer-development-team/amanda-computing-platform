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
 * File:   DefaultPoolAllocator.cpp
 * Author: Javier Marrero
 * 
 * Created on July 5, 2022, 2:46 PM
 */

#include <amanda-vm/Runtime/DefaultPoolAllocator.h>

using namespace amanda;
using namespace amanda::vm;

DefaultPoolAllocator::DefaultPoolAllocator(MemoryManager& memoryManager)
:
MemoryAllocator(memoryManager)
{
}

DefaultPoolAllocator::~DefaultPoolAllocator()
{
}

void* DefaultPoolAllocator::allocate(size_t size)
{
    return std::calloc(size, sizeof (char));
}

void DefaultPoolAllocator::expandAddressSpace(size_t amount)
{
}

const MemoryAllocator::AllocationHeader& DefaultPoolAllocator::find(size_t size) const
{
    return AllocationHeader::INVALID_ALLOCATION;
}

bool DefaultPoolAllocator::isNeedingExpansion() const
{
    return false;
}




