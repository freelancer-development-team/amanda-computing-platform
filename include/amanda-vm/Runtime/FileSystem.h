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
 * File:   FileSystemManager.h
 * Author: Javier Marrero
 *
 * Created on May 22, 2022, 10:42 AM
 */

#ifndef FILESYSTEMMANAGER_H
#define FILESYSTEMMANAGER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Runtime/ResourceIdentifier.h>
#include <amanda-vm/Logging/Logger.h>
#include <amanda-vm/IO/InputStream.h>
#include <amanda-vm/IO/Path.h>
#include <amanda-vm/IO/File.h>

namespace amanda
{
namespace vm
{

class Context;

/**
 * The file system class 'sandboxes' the virtual machine visible local file system.
 * This allows for clear responsibility separation between the virtual machine
 * context and file system operations. This class is responsible for accessing
 * the file system in a coherent manner and to provide access to the virtual
 * machine auxiliary file system structure.
 * <p>
 * The virtual machine is in the need of a set of files and directories that
 * must be present in order to ensure successful execution. The responsibility
 * of locating and accessing those files is in this class.
 * <p>
 * Notice that this class also abstracts the underlying file system, and
 * therefore, resources could also be provided remotely by a network file system.
 *
 * @author J. Marrero
 */
class FileSystem : public core::Object
{
    AMANDA_OBJECT(FileSystem, core::Object)
public:
    
    static const core::String&  BIN_DIRECTORY;
    static const core::String&  CONFIG_DIRECTORY;
    static const core::String&  EXECUTABLE_FILE_EXTENSION;
    static const core::String&  LIBRARIES_DIRECTORY;
    static const core::String&  MODULES_DIRECTORY;

    FileSystem(const Context& context, io::Path* root);
    virtual ~FileSystem();

    virtual bool                checkExistenceOfDirectory(const core::String& name) const;
    const core::String          getDllExtension() const;
    virtual io::Path            getLibrariesFolder() const;
    virtual io::Path            getModulesFolder() const;
    virtual io::File*           getResourceAsFile(const ResourceIdentifier& id) const;
    virtual io::InputStream*    getResourceAsStream(const ResourceIdentifier& id) const;

protected:

    const Context&                  context;
    logging::Logger&                logger;
    core::StrongReference<io::Path> executablePath;
    core::StrongReference<io::Path> rootPath;

} ;

}
}

#endif /* FILESYSTEMMANAGER_H */

