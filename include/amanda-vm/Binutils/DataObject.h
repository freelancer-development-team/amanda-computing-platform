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
 * File:   DataObject.h
 * Author: Javier Marrero
 *
 * Created on April 30, 2022, 2:41 PM
 */

#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <amanda-vm/Binutils/Symbol.h>

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

    DataObject(const core::String& name, unsigned visibility = Bind_Global);
    ~DataObject();
    
protected:

} ;

}
}

#endif /* DATAOBJECT_H */

