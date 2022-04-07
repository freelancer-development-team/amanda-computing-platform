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
 * File:   Serializable.h
 * Author: Javier Marrero
 *
 * Created on March 24, 2022, 10:54 PM
 */

#ifndef _BINUTILS_SERIALIZABLE_H
#define _BINUTILS_SERIALIZABLE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/OutputStream.h>

namespace amanda
{
namespace binutils
{

/**
 * Serializable objects are capable of being converted into a byte stream and
 * later be restored from that same byte stream. It has several utilities as
 * sharing objects across networks or creating persistent objects.
 *
 * @autor J. Marrero
 */
class Serializable : public core::Object
{
    AMANDA_OBJECT(Serializable, core::Object)
    
public:

    virtual void marshall(io::OutputStream& stream);
} ;

}
}

#endif /* SERIALIZABLE_H */

