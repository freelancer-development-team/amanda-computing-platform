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
 * File:   DataObject.cpp
 * Author: Javier Marrero
 * 
 * Created on April 30, 2022, 2:41 PM
 */

#include <amanda-vm/Binutils/DataObject.h>

// C++
#include <cstdlib>

using namespace amanda;
using namespace amanda::binutils;

DataObject::DataObject(const core::String& name, vm::vm_byte_t visibility)
:
Symbol(name)
{
    setBindClass(visibility);
    setType(Type_Object);

    // Reserve space.
    data.reserve(8);
}

DataObject::~DataObject()
{
    for (std::vector<TaggedData*>::const_iterator it = data.begin(),
         end = data.end(); it != end; ++it)
    {
        free((*it)->buffer);
        delete (*it);
    }
}

void DataObject::addData(const void* data, size_t size)
{
    // Make a new tag of the specified size.
    TaggedData* tdata = makeTag(size);

    // Set the data
    memcpy(tdata->buffer, data, size);
    tdata->size = size;

    // Append the pointer to the list of data
    this->data.push_back(tdata);
}

void DataObject::addUtf8Data(const char* data, size_t size)
{
    ///FIXME: Perhaps do this multi-threading safe?
    // Add the data to the list
    addData(data, size);

    // Set the UTF8 flag
    this->data.back()->utf8 = true;
}

void DataObject::constructBinaryData()
{
    for (std::vector<TaggedData*>::const_iterator it = data.begin(),
         end = data.end(); it != end; ++it)
    {
        if ((*it)->utf8)
        {
            write((*it)->buffer, VM_BYTE_SIZE, (*it)->size);
        }
        else
        {
            write((*it)->buffer, (*it)->size, 1);
        }
    }
}

DataObject::TaggedData* DataObject::makeTag(size_t size) const
{
    // Create the tagged data structure
    TaggedData* tdata = (TaggedData*) std::calloc(1, sizeof (TaggedData));
    assert(tdata != NULL && "Out of memory.");

    // Create the binary buffer
    tdata->buffer = (char*) std::calloc(size, sizeof (char));
    assert(tdata->buffer != NULL && "Out of memory");

    return tdata;
}

