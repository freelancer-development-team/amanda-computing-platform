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
 * File:   ImageHeader.h
 * Author: Javier Marrero
 *
 * Created on March 24, 2022, 8:54 PM
 */

#ifndef IMAGEHEADER_H
#define IMAGEHEADER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/Serializable.h>
#include <amanda-vm/Binutils/VirtualMachineSpecs.h>

#include <stdint.h>

namespace amanda
{
namespace binutils
{
namespace ld
{

/**
 */
class ImageHeader : public Serializable
{
    AMANDA_OBJECT(ImageHeader, Serializable)
public:

    static uint8_t      MAGIC_NUMBER[4];
    static const short  IMAGE_SIZEOF_SHORT_NAME = 24;

private:

    vm::vm_address_t baseAddress; /// The base address of the executable image
    
} ;

}
}
}

#endif /* IMAGEHEADER_H */

