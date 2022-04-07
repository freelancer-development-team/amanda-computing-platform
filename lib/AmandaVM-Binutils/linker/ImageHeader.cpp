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
 * File:   ImageHeader.cpp
 * Author: Javier Marrero
 * 
 * Created on March 24, 2022, 8:54 PM
 */

#include <amanda-vm/Binutils/Linker/ImageHeader.h>

using namespace amanda;
using namespace amanda::binutils::ld;

uint8_t ImageHeader::MAGIC_NUMBER[4] = {0x7F, '@', 'A', 'X'};

void ImageHeader::marshall(io::OutputStream& stream)
{
    stream.write(MAGIC_NUMBER, 1, 4);
    stream.write(&this->headerSize, sizeof(headerSize));
    stream.write(&this->sectionHeaderOffset, sizeof(sectionHeaderOffset));
    stream.write(&this->sectionNamesIndex, sizeof(sectionNamesIndex));
}

void ImageHeader::setSectionNamesIndex(vm::vm_qword_t sectionNamesIndex)
{
    this->sectionNamesIndex = sectionNamesIndex;
}

vm::vm_qword_t ImageHeader::getSectionNamesIndex() const
{
    return sectionNamesIndex;
}

void ImageHeader::setSectionHeaderOffset(vm::vm_address_t sectionHeaderOffset)
{
    this->sectionHeaderOffset = sectionHeaderOffset;
}

vm::vm_address_t ImageHeader::getSectionHeaderOffset() const
{
    return sectionHeaderOffset;
}

void ImageHeader::setHeaderSize(vm::vm_word_t headerSize)
{
    this->headerSize = headerSize;
}

vm::vm_word_t ImageHeader::getHeaderSize() const
{
    return headerSize;
}

void ImageHeader::setBaseAddress(vm::vm_address_t baseAddress)
{
    this->baseAddress = baseAddress;
}

vm::vm_address_t ImageHeader::getBaseAddress() const
{
    return baseAddress;
}

