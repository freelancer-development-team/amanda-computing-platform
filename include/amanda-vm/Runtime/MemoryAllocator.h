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
 * File:   MemoryAllocator.h
 * Author: Javier Marrero
 *
 * Created on May 17, 2022, 2:51 PM
 */

#ifndef MEMORYALLOCATOR_H
#define MEMORYALLOCATOR_H

#include <amanda-vm/TypeSystem.h>
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

    MemoryAllocator(MemoryManager& memoryManager);

    virtual void*           allocate(size_t size) = 0;
    virtual void*           allocateAligned(size_t size, size_t alignment) = 0;
    virtual void            deallocate(size_t size) = 0;
    const MemoryManager&    getMemoryManager() const;

protected:

    MemoryManager& memoryManager;
} ;

}
}

#endif /* MEMORYALLOCATOR_H */

