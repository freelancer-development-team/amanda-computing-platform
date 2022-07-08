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
 * File:   DataObject.h
 * Author: Javier Marrero
 *
 * Created on April 30, 2022, 2:41 PM
 */

#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <amanda-vm/Binutils/Symbol.h>
#include <amanda-vm/Binutils/vm-types.h>
#include <amanda-vm/ADT/BinaryBuffer.h>

namespace amanda
{
namespace binutils
{

/**
 * Data objects are symbols representing some sort of data. They may contain
 * other data objects in a recursive tree-like fashion. This allows to create
 * composite data objects that works similarly to C structures. One can define
 * arbitrary data inside a data object.
 *
 * @author J. Marrero
 */
class DataObject : public Symbol
{
    AMANDA_OBJECT(DataObject, Symbol)
public:

    DataObject(const core::String& name, vm::vm_byte_t visibility = Bind_Global);
    ~DataObject();

    virtual void    addData(const void* data, size_t size);
    virtual void    addUtf8Data(const char* data, size_t size);
    virtual void    constructBinaryData();
    virtual size_t  getSize() const;

protected:

    /**
     * A data type encapsulating binary data + size.
     */
    typedef struct TaggedData
    {
        char*   buffer;
        size_t  size;
        bool    utf8;
    } TaggedData;

    std::vector<TaggedData*> data;

    virtual size_t  calculateSize() const;

    /// Create a new <code>TaggedData</code> struct with the specified size.
    TaggedData* makeTag(size_t size) const;
} ;

}
}

#endif /* DATAOBJECT_H */

