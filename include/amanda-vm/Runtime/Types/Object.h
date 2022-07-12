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
 * File:   Object.h
 * Author: Javier Marrero
 *
 * Created on June 23, 2022, 2:31 AM
 */

#ifndef AMANDA_NATIVE_INTERFACE_OBJECT_H
#define AMANDA_NATIVE_INTERFACE_OBJECT_H

#include <amanda-vm/Binutils/vm-types.h>
#include <amanda-vm-c/sdk-types.h>

namespace amanda
{
namespace cts
{

/**
 * This structure represents the object header that is present on every instance
 * of an object in the Amanda Common Type System model.
 */
struct Amanda_ObjectHeader
{
    sdk_u32_t       m_magic;
    sdk_u64_t       m_self;
    sdk_u64_t       m_refcount;
    sdk_u64_t       m_size;
    sdk_utf8_char_t m_classname[256];
} __attribute__((packed));
typedef struct Amanda_ObjectHeader Amanda_ObjectHeader;

/**
 * An entry in the v-table
 */
struct Amanda_VTableEntry
{
} __attribute__((packed));
typedef struct Amanda_VTableEntry Amanda_VTableEntry;

/**
 * Represents an object v-table.
 */
struct Amanda_ObjectVTable
{
    sdk_u64_t           m_ecount;
    Amanda_VTableEntry* m_entries;
} ;
typedef struct Amanda_ObjectVTable Amanda_ObjectVTable;

Amanda_ObjectVTable*    Amanda_ObjectVTable_alloc(size_t entries);
void                    Amanda_ObjectVTable_delete(Amanda_ObjectVTable* self);
size_t                  Amanda_ObjectVTable_getSize(Amanda_ObjectVTable* self);

/**
 * An object is the basic data representation model within the Amanda platform.
 */
struct Amanda_Object
{
    Amanda_ObjectHeader     header;
    Amanda_ObjectVTable*    vtable;
} ;
typedef struct Amanda_Object Amanda_Object;

}
}

#endif /* OBJECT_H */
