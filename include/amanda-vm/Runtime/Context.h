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
 * File:   Context.h
 * Author: Javier Marrero
 *
 * Created on May 21, 2022, 11:06 PM
 */

#ifndef CONTEXT_H
#define CONTEXT_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/Path.h>
#include <amanda-vm/Logging/ConsoleHandler.h>
#include <amanda-vm/Logging/GNUFormatter.h>
#include <amanda-vm/Logging/Logger.h>
#include <amanda-vm/Runtime/FileSystem.h>
#include <amanda-vm/Runtime/MemoryManager.h>
#include <amanda-vm/Runtime/MemoryAllocator.h>
#include <amanda-vm/Runtime/ModuleLoader.h>
#include <amanda-vm/Runtime/ThreadScheduler.h>

// C++
#include <map>

namespace amanda
{
namespace vm
{

/**
 * The context class represents a running virtual machine. It holds all the
 * configuration and state information necessary to successfully load and
 * run Amanda programs.
 * <p>
 * Context object holds information about the following resources:
 * <ul>
 * <li>Memory via the memory manager</li>
 * <li>CPU time via the thread scheduler</li>
 * <li>File system via the file system manager</li>
 * <li>Configuration via itself</li>
 * <li>Loaded modules, via the module loader component</li>
 * </ul>
 *
 * @author J. Marrero
 */
class Context : public core::Object
{
    AMANDA_OBJECT(Context, core::Object)
public:

    typedef std::map<const core::String, core::String, core::AlphabeticalOrderComparator> PropertiesMap;

    static const core::String OS_NAME_KEY;
    static const core::String SDK_VERSION_KEY;

    Context(MemoryAllocator* memoryAllocator,
            const core::String& path);
    virtual ~Context();

    const core::String& getProperty(const core::String& key) const;
    void                loadLibrary(const core::String& fullPath);
    bool                putProperty(const core::String& key, const core::String& value);
    void                setMemoryAllocator(MemoryAllocator* memoryAllocator);
    void                setProperty(const core::String& key, const core::String& value);

private:

    /**
     * This class is a descriptor for a loaded native library.
     */
    class NativeLibraryDescriptor : public core::Object
    {
        AMANDA_OBJECT(NativeLibraryDescriptor, core::Object)
    public:

        NativeLibraryDescriptor(const core::String& name, const core::String& path);
        NativeLibraryDescriptor(const NativeLibraryDescriptor& rhs);

        const core::String& getName() const;
        const core::String& getPath() const;

    private:

        core::String name;
        core::String path;
    } ;

    typedef std::map<const core::String, NativeLibraryDescriptor, core::AlphabeticalOrderComparator> LibraryMap;

    static logging::ConsoleHandler              CONSOLE_HANDLER;
    static logging::GNUFormatter                FORMATTER;
    static logging::Logger&                     LOGGER;

    core::StrongReference<FileSystem>           fileSystem;
    core::StrongReference<MemoryAllocator>      memoryAllocator;
    core::StrongReference<MemoryManager>        memoryManager;
    core::StrongReference<ModuleLoader>         moduleLoader;
    LibraryMap                                  nativeLibraries;
    core::StrongReference<io::Path>             path;
    PropertiesMap                               properties;
    core::StrongReference<ThreadScheduler>      scheduler;

    /// Initializes the default system properties
    void initializeSystemProperties();
} ;

}
}

#endif /* CONTEXT_H */

