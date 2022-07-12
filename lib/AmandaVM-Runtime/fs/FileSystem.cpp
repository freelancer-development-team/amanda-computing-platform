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
 * File:   FileSystemManager.cpp
 * Author: Javier Marrero
 * 
 * Created on May 22, 2022, 10:42 AM
 */

#include <amanda-vm/Runtime/FileSystem.h>
#include <amanda-vm/Runtime/Context.h>
#include <amanda-vm/IO/FileInputStream.h>
#include <amanda-vm/NIO/NoSuchFileException.h>

using namespace amanda;
using namespace amanda::vm;

const core::String& FileSystem::BIN_DIRECTORY = "bin";
const core::String& FileSystem::CONFIG_DIRECTORY = "conf";
const core::String& FileSystem::LIBRARIES_DIRECTORY = "lib";
const core::String& FileSystem::MODULES_DIRECTORY = "mods";

FileSystem::FileSystem(const Context& context, io::Path* root)
:
context(context),
logger(logging::Logger::getLogger("amanda.vm.FileSystem")->getReference()),
executablePath(root),
rootPath(new io::Path(root->getParent().getParent()))
{
    // Set the logger properties
    logger.setUseParentHandlers(false);
    logger.addHandler(context.getFileHandlerForLog()->getReference());

    // Log the initialization phase
    logger.info("initializing virtual file-system server (root path '%s').",
                rootPath->toString().toCharArray());
    
}

FileSystem::~FileSystem()
{
}

bool FileSystem::checkExistenceOfDirectory(const core::String& name) const
{
    bool result = true;
    io::File directory(io::Path(rootPath->getConstReference(), name), io::File::READ);

    if (!directory.exists() || directory.isDirectory())
    {
        result = false;
        throw nio::IOException(core::String::makeFormattedString("the specified directory (%s) is not a directory or does not exists.",
                                                                 directory.getPath().toCharArray()));
    }
    else
    {
        logger.finest("successfully checked existence of directory: %s", directory.getPath().toCharArray());
    }
    return result;
}

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
    logger.trace("accessing resource with id <%s>", id.toString().toCharArray());

    io::InputStream* result = NULL;

    // Identify the protocol and act accordingly
    if (id.isLocal())
    {
        result = new io::FileInputStream(getResourceAsFile(id));
    }

    return result;
}



