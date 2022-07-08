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
 * File:   FileInputStream.cpp
 * Author: Javier Marrero
 * 
 * Created on March 27, 2022, 1:03 AM
 */

#include <amanda-vm/IO/FileInputStream.h>

using namespace amanda;
using namespace amanda::io;

FileInputStream::FileInputStream(const File* file)
:
file(file),
inHeap(true)
{
    if (file)
    {
        file->grab();
    }
}

FileInputStream::FileInputStream(const File& file)
:
file(&file),
inHeap(false)
{
}

FileInputStream::~FileInputStream()
{
    close();
}

void FileInputStream::close() const
{
    if (file && !File::isTerminalStream(file) && inHeap)
    {
        file->release();
    }
    file = NULL;
}

int FileInputStream::read(void* buffer, size_t size, size_t count) const
{
    int result = 0;
    bool state = file->read((char*) buffer, size, count);

    // Return the end of stream if that's what we've reached
    if (file->isEndOfFile())
    {
        result = END_OF_STREAM;
    }
    if (state == false)
    {
        result = READ_ERROR;
    }
    return result;
}

void FileInputStream::reset() const
{
    file->reset();
}

void FileInputStream::seek(uint64_t offset) const
{
    file->setPosition(offset);
}

uint64_t FileInputStream::tell() const
{
    return file->tell();
}
