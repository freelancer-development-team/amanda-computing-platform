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
 * File:   FileOutputStream.cpp
 * Author: Javier Marrero
 * 
 * Created on March 1, 2022, 1:46 AM
 */

#include <amanda-vm/IO/FileOutputStream.h>

using amanda::io::FileOutputStream;

FileOutputStream::FileOutputStream(const File* file)
:
file(file)
{
    if (file)
    {
        file->grab();
    }
}

FileOutputStream::~FileOutputStream()
{
    releaseResource();
}

void FileOutputStream::close() const
{
    releaseResource();
}

void FileOutputStream::releaseResource() const
{
    if (file && !File::isTerminalStream(file))
    {
        file->release();
    }
    file = NULL;
}

void FileOutputStream::write(const void* data, size_t size) const
{
    file->write(data, size);
}

void FileOutputStream::write(const char* data) const
{
    file->write(data);
}

