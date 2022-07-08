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

#include <amanda-vm/Runtime/Types/Object.h>
#include <amanda-vm/Runtime/OutOfMemoryError.h>
#include <amanda-vm/Logging/Logger.h>

// C++
#include <cstdio>
#include <cstring>
#include <stdlib.h>

using namespace amanda;
using namespace amanda::cts;

static logging::Logger& LOGGER = logging::Logger::getLogger("amanda.vm.CommonTypeSystem")->getReference();

Amanda_ObjectVTable* amanda::cts::Amanda_ObjectVTable_alloc(size_t entries)
{
    Amanda_ObjectVTable* result = (Amanda_ObjectVTable*) std::calloc(1, sizeof (Amanda_ObjectVTable));
    if (!result)
        throw vm::OutOfMemoryError();

    result->m_ecount = entries;
    result->m_entries = (Amanda_VTableEntry*) std::calloc(entries, sizeof (Amanda_VTableEntry));
    if (!result->m_entries)
        throw vm::OutOfMemoryError();

    LOGGER.trace("allocated object v-table with %llu entries to address 0x%p", entries, result);
    return result;
}

void amanda::cts::Amanda_ObjectVTable_delete(Amanda_ObjectVTable* self)
{
    if (self != NULL)
    {
        LOGGER.trace("de-allocating object v-table at address 0x%p", self);
        if (self->m_entries != NULL)
        {
            std::free(self->m_entries);
        }
        std::free(self);
    }
}

size_t amanda::cts::Amanda_ObjectVTable_getSize(Amanda_ObjectVTable* self)
{
    assert(self != NULL && "Null pointer exception");
    return self->m_ecount * sizeof (Amanda_VTableEntry);
}
