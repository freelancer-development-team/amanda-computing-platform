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
 * File:   DefaultPoolAllocator.h
 * Author: Javier Marrero
 *
 * Created on July 5, 2022, 2:46 PM
 */

#ifndef DEFAULTPOOLALLOCATOR_H
#define DEFAULTPOOLALLOCATOR_H

#include <amanda-vm/Runtime/MemoryAllocator.h>

namespace amanda
{
namespace vm
{

/**
 * This namespace is a placeholder memory allocator that used standard malloc,
 * calloc and free.
 *
 * @param memoryManager
 */
class DefaultPoolAllocator : public MemoryAllocator
{
public:

    DefaultPoolAllocator(MemoryManager& memoryManager);
    virtual ~DefaultPoolAllocator();

    virtual void* allocate(size_t size);

protected:


    virtual void expandAddressSpace(size_t amount);
    virtual const MemoryAllocator::AllocationHeader& find(size_t size) const;
    virtual bool isNeedingExpansion() const;

} ;

}
}

#endif /* DEFAULTPOOLALLOCATOR_H */

