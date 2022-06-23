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
 * File:   FileSystemManager.cpp
 * Author: Javier Marrero
 * 
 * Created on May 22, 2022, 10:42 AM
 */

#include <amanda-vm/Runtime/FileSystem.h>
#include <amanda-vm/IO/FileInputStream.h>
#include <amanda-vm/NIO/NoSuchFileException.h>

using namespace amanda;
using namespace amanda::vm;

const logging::Logger& FileSystem::LOGGER = logging::Logger::getLogger("amanda.vm.FileSystem")->getConstReference();

io::File* FileSystem::getResourceAsFile(const ResourceIdentifier& id) const
{
    if (!id.isLocal())
    {
        throw nio::NoSuchFileException(id.toString());
    }

    io::File* result = new io::File(id.getAddress(), io::File::READ | io::File::WRITE | io::File::BINARY);
    if (!result->exists())
    {
        throw nio::NoSuchFileException(result->getPath());
    }
    if (!result->open())
    {
        throw nio::IOException(result->getLastErrorString());
    }

    return result;
}

io::InputStream* FileSystem::getResourceAsStream(const ResourceIdentifier& id) const
{
    // Debug
    LOGGER.trace("accessing resource with id <%s>", id.toString().toCharArray());

    io::InputStream* result = NULL;

    // Identify the protocol and act accordingly
    if (id.isLocal())
    {
        result = new io::FileInputStream(getResourceAsFile(id));
    }

    return result;
}



