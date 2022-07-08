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
#include <amanda-vm/Logging/FileHandler.h>
#include <amanda-vm/Logging/GNUFormatter.h>
#include <amanda-vm/Logging/Logger.h>
#include <amanda-vm/Runtime/FileSystem.h>
#include <amanda-vm/Runtime/MemoryManager.h>
#include <amanda-vm/Runtime/MemoryAllocator.h>
#include <amanda-vm/Runtime/ModuleLoader.h>
#include <amanda-vm/Runtime/ThreadScheduler.h>
#include <amanda-vm/Runtime/ExecutableModule.h>

// C++
#include <map>
#include <vector>

// LibFFI
#include <ffi.h>

namespace amanda
{
namespace vm
{

class NativeProcedure;
class Procedure;
struct ProcesorFlags;

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
    //TODO: Add using libffi feature macro
    typedef std::vector<ffi_type*>   NativeTypeList;

    // Errors on invocation
    static const int            ENOERR  = 0;
    static const int            ENOPROC = 1;
    static const int            ENOLANG = 2;
    static const int            ENOSYM  = 4;

    static const core::String   OS_NAME_KEY;
    static const core::String   SDK_VERSION_KEY;

    static const logging::Logger& getLogger();

    static void handleSigsegv(int signum);

    Context(MemoryAllocator* memoryAllocator,
            const core::String& path);
    virtual ~Context();

    void                cacheProcedure(const core::String& name, Procedure* proc) const;
    int                 callLocal(const core::String& name, Stack& stack, Procedure::ProcessorFlags& eflags) const;
    int                 callNative(const core::String& name, Stack& stack) const;
    const Procedure*    getCachedLocalProcedure(const core::String& name) const;
    MemoryAllocator&    getMemoryAllocator() const;
    const core::String& getProperty(const core::String& key) const;
    bool                isCachedProcedure(const core::String& name) const;
    int                 loadAndExecute(const core::String& fullPath);
    void                loadLibrary(const core::String& fullPath);
    ExecutableModule*   loadModule(const core::String& fullPath);
    NativeTypeList      parseFunctionArgumentTypes(const core::String& str) const;
    bool                putProperty(const core::String& key, const core::String& value);
    void                setMemoryAllocator(MemoryAllocator* memoryAllocator);
    void                setProperty(const core::String& key, const core::String& value);
    void                setScheduler(const ThreadScheduler* scheduler);
    void                uncacheProcedure(const core::String& name) const;

private:

    /**
     * This class is a descriptor for a loaded native library.
     */
    class NativeLibraryDescriptor : public core::Object
    {
        AMANDA_OBJECT(NativeLibraryDescriptor, core::Object)
    public:

        typedef void*   NativeHandle;

        NativeLibraryDescriptor(const core::String& name, const core::String& path);
        NativeLibraryDescriptor(const NativeLibraryDescriptor& rhs);

        const NativeHandle  getHandle() const;
        const core::String& getName() const;
        const core::String& getPath() const;
        void                setHandle(NativeHandle h);
        void                unload() const;

    private:

        NativeHandle                    handle;
        core::String                    name;
        core::String                    path;
        std::vector<NativeProcedure*>   procedures;
    } ;

    typedef std::map<const core::String, NativeLibraryDescriptor, core::AlphabeticalOrderComparator>    LibraryMap;
    typedef std::map<core::String, void*, core::AlphabeticalOrderComparator>                            NativeSymbolsCache;
    typedef std::map<core::String, NativeProcedure*, core::AlphabeticalOrderComparator>                 NativeProceduresCache;
    typedef std::map<core::String, Procedure*, core::AlphabeticalOrderComparator>                       ProceduresCache;

    static logging::ConsoleHandler              CONSOLE_HANDLER;
    static logging::GNUFormatter                FORMATTER;
    static logging::Logger&                     LOGGER;


    mutable NativeProceduresCache               cachedNativeProcedures;
    mutable ProceduresCache                     cachedProcedures;
    mutable NativeSymbolsCache                  cachedSymbols;
    core::StrongReference<FileSystem>           fileSystem;
    core::StrongReference<logging::Formatter>   fileFormatter;
    core::StrongReference<logging::FileHandler> fileHandler;
    core::StrongReference<io::File>             loggingFile;
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

