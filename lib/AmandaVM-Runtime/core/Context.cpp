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
 * File:   Context.cpp
 * Author: Javier Marrero
 * 
 * Created on May 21, 2022, 11:06 PM
 */

#include <amanda-vm/Runtime/Context.h>
#include <amanda-vm/Runtime/NativeProcedure.h>
#include <amanda-vm/Runtime/NativeCProcedure.h>
#include <amanda-vm/Runtime/LinkageError.h>
#include <amanda-vm/Runtime/Procedure.h>
#include <amanda-vm/Runtime/IllegalStateException.h>
#include <amanda-vm/Runtime/Optimization/NullOptimizationCriteria.h>
#include <amanda-vm/Binutils/package.hxx>
#include <amanda-vm-c/sdk-version.h>
#include <amanda-vm/NIO/IOException.h>
#include <amanda-vm/NIO/NoSuchFileException.h>
#include <amanda-vm/IllegalArgumentException.h>
#include <amanda-vm/System.h>

// C++
#include <ffi.h>
#include <ffitarget.h>
#include <cstdlib>
#include <cerrno>
#include <ctime>
#include <csignal>
#include <clocale>
#include <streambuf>

#if _W32
#    include <windows.h>
#endif

//**************************** SIGNAL HANDLERS ********************************/

void amanda::vm::Context::handleSigsegv(int signum)
{
    amanda::vm::Context::getLogger().fatal("segmentation failure (signal %d).", signum);
#if _W32
    MessageBoxW(NULL,
                L"The virtual machine has detected a memory access violation "
                "and therefore must abort program execution. (VM internal error)",
                L"Access violation (Internal error)", MB_ICONERROR);
#endif

    // Abort the program
    std::abort();
}

//****************************************************************************//

using namespace amanda;
using namespace amanda::vm;

const logging::Logger& Context::getLogger()
{
    return LOGGER;
}

// Const fields
const core::String Context::OS_NAME_KEY = "amanda::vm::os.name";
const core::String Context::SDK_VERSION_KEY = "amanda::vm::sdk.version";

logging::ConsoleHandler Context::CONSOLE_HANDLER;
logging::GNUFormatter Context::FORMATTER("amanda-vm", true);
logging::Logger& Context::LOGGER = logging::Logger::getLogger("amanda.vm.Context")->getReference();

Context::Context(MemoryAllocator* memoryAllocator,
                 const core::String& path)
:
memoryAllocator(memoryAllocator),
memoryManager(amanda::eliminateConstness(&memoryAllocator->getMemoryManager())),
moduleLoader(new ModuleLoader(memoryAllocator->getReference()))
{
    // Set the signal handlers
    std::signal(SIGSEGV, handleSigsegv);

    // Create the logging file
    loggingFile = new io::File("amandavm-session.log", io::File::WRITE | io::File::CREATE);
    if (!loggingFile->open())
    {
        fprintf(stderr, "amanda-vm: fatal error: unable to open log file (%s).", loggingFile->getLastErrorString().toCharArray());
        throw nio::IOException("unable to open log file.");
    }

    // Get the virtual machine execution path
    {
        // Get the full path object
        io::Path full(path);

        // Assign to the path reference
        this->path = new io::Path(full.getParent().toString());
    }

    // Initialize the local file system
    fileSystem = new FileSystem();

    // Initialize the default system properties.
    initializeSystemProperties();

    // Create the logging object and output the first message.
    LOGGER.setUseParentHandlers(false);
    LOGGER.setLevel(logging::Logger::ALL);

    // Create the file handler
    fileFormatter = new logging::GNUFormatter("amanda-vm", false);
    fileHandler = new logging::FileHandler(loggingFile, fileFormatter);

    // Configure the handlers
    CONSOLE_HANDLER.setFormatter(FORMATTER);
    CONSOLE_HANDLER.setLevel(logging::Logger::WARN);

    // Add the handlers
    LOGGER.addHandler(CONSOLE_HANDLER);
    LOGGER.addHandler(fileHandler->getReference());

    // Trace the context creation
    LOGGER.info("creating virtual machine context object (0x%p)", this);

    // Load the C library
    LOGGER.info("loading runtime descriptor for the standard C library.");
    loadLibrary(core::getOperatingSystem() == core::WINDOWS ?
                "msvcrt" : "c");

    // Set the locale
    // Amanda-VM uses UTF8 encoding and utf8 locale
    // TODO: Complete UTF8 locale request
    std::setlocale(LC_ALL, "");

    // Add the null optimization criteria if we're building without optimization
#ifdef NO_JIT_COMPILATION
    addGlobalOptimizationCriteria(new NullOptimizationCriteria());
#endif

    // Prepare the console to display ANSI escape codes if on Windows
    //TODO: Finish this
#if _W32

#endif

    // If we are in release mode
    // set the logging level to info
#ifndef DEBUG
    LOGGER.setLevel(logging::Logger::INFO);
#endif
}

Context::~Context()
{
    properties.clear();

    // Trace the context deletion
    LOGGER.info("destroying virtual machine context @ 0x%p.", this);

    // Clear the caches
    for (LibraryMap::const_iterator it = nativeLibraries.begin(),
         end = nativeLibraries.end(); it != end; ++it)
    {
        LOGGER.info("unloading dynamic link library '%s'.", it->first.toCharArray());
        it->second.unload();
    }
    for (NativeProceduresCache::const_iterator it = cachedNativeProcedures.begin(),
         end = cachedNativeProcedures.end(); it != end; ++it)
    {
        LOGGER.info("un-caching native symbol '%s'.", it->second->getName().toCharArray());
        it->second->release();
    }
    for (ProceduresCache::const_iterator it = cachedProcedures.begin(),
         end = cachedProcedures.end(); it != end; ++it)
    {
        LOGGER.info("un-caching local symbol '%s'.", it->second->getName().toCharArray());
        it->second->release();
    }
    for (unsigned i = 0; i < globalOptimizationCriteria.size(); ++i)
    {
        LOGGER.info("deleting global optimization criteria of class '%s'", globalOptimizationCriteria.at(i)->getClassDynamically().getName());
        globalOptimizationCriteria.at(i)->release();
    }

    // We've destroyed the objects
    LOGGER.info("\t-- EXEC FINISHED --\n");
}

void Context::addGlobalOptimizationCriteria(AdaptiveOptimizationCondition* condition)
{
    condition->grab();
    globalOptimizationCriteria.push_back(condition);
}

void Context::initializeSystemProperties()
{
#ifdef _W32
    putProperty(OS_NAME_KEY, "Windows");
#else
    putProperty(OS_NAME_KEY, core::String::EMPTY);
#endif

    putProperty(SDK_VERSION_KEY, SDK_FULLVERSION_STRING);
}

void Context::cacheProcedure(const core::String& name, Procedure* proc) const
{
    assert(proc != NULL && "Null pointer exception");
    AMANDA_SYNCHRONIZED(lock);
    if (!isCachedProcedure(name))
    {
        proc->grab();                                           // Own a reference to the procedure object
        cachedProcedures.insert(std::make_pair(name, proc));    // Insert it into the cache
    }
    AMANDA_DESYNCHRONIZED(lock);
}

int Context::callLocal(const core::String& name, Stack& stack, Procedure::ProcessorFlags& eflags) const
{
    int result = ENOERR;
    Procedure* subroutine = NULL;
    if (isCachedProcedure(name))
    {
        LOGGER.trace("the procedure '%s' is cached, executing (local stack: 0x%p).", name.toCharArray(), stack.getSelfPointer());
        subroutine = const_cast<Procedure*> (getCachedLocalProcedure(name));
    }
    else
    {
        AMANDA_SYNCHRONIZED(lock);
        {
            // Start looking for the symbol in all the available modules
            LOGGER.trace("symbol '%s' is un-cached, lazy-binding symbol and caching search results.", name.toCharArray());

            // Find the symbol to which the function is local
            ExecutableModule* module = NULL;
            const binutils::Symbol::SymbolTableEntry* symbol = NULL;

            bool found = false;
            for (ModuleLoader::ModuleIterator it = moduleLoader->getIterator(),
                 end = moduleLoader->getIteratorEnd(); it != end && !found; ++it)
            {
                module = it->second;
                symbol = module->findSymbol(name, binutils::Symbol::Type_Function);
                if (symbol != NULL)
                {
                    found = true;
                }
            }
            if (!found)
            {
                LOGGER.error("the requested procedure (%s) is not local to any currently loaded symbol.", name.toCharArray());
                result = ENOSYM;
            }

            if (result == ENOERR)
            {
                core::WeakReference<Procedure> procedure = new Procedure(this->getConstReference(), name, symbol);
                procedure->setExecutableModule(module->getReference());
                cacheProcedure(name, procedure);

                // Assign a reference to the freshly created subroutine
                subroutine = procedure;
            }
        }
        AMANDA_DESYNCHRONIZED(lock);
    }

    if (subroutine == NULL) result = ENOPROC;
    if (result == ENOERR && subroutine != NULL)
    {
        for (unsigned i = 0; i < globalOptimizationCriteria.size(); ++i)
        {
            subroutine->addOptimizationCriteria(globalOptimizationCriteria.at(i));
        }

        LOGGER.debug("made local jump to local subroutine '%s' with local stack at 0x%p.",
                     name.toCharArray(), stack.getSelfPointer());
        subroutine->execute(stack, eflags);
    }
    // Return our final execution result
    return result;
}

int Context::callNative(const core::String& name, Stack& stack) const
{
    // Log the attempt
    LOGGER.debug("attempting call to native function named <%s> (local stack: 0x%p)",
                name.toCharArray(), stack.getSelfPointer());

    // Set the default result to OK
    int result = FFI_OK;
    if (cachedNativeProcedures.find(name) != cachedNativeProcedures.end())
    {
        LOGGER.trace("the method '%s' is already cached and ready to execute (local stack: 0x%p)", name.toCharArray(), stack.getSelfPointer());
        cachedNativeProcedures.find(name)->second->call(stack);
    }
    else
    {
        // First of all, find the symbol we're looking for
        std::vector<core::String> partitionedName = name.split("@", 0);
        if (partitionedName.size() != 3)
        {
            LOGGER.error("invalid native symbol file name: cannot parse method signature (need 3 components, got %llu).", partitionedName.size());
            result = ENOPROC;
        }
        else
        {
            std::vector<core::String> languageMethod = partitionedName.at(0).split("!!", 2);
            if (languageMethod.size() == 2)
            {
                const core::String language = languageMethod.at(0);
                const core::String methodName = languageMethod.at(1);
                const core::String methodReturnType = partitionedName.at(1);
                const core::String methodArguments = partitionedName.at(2);

                core::WeakReference<NativeProcedure> procedure;
                if (language == "$c")
                {
                    // Check on every native library for the symbol. If the symbol is there, cache
                    // the symbol
                    const void* symbol = NULL;
                    if (cachedSymbols.find(methodName) != cachedSymbols.end())
                    {
                        LOGGER.trace("found cached procedure (%s), no need to look into dynamic link libraries.", methodName.toCharArray());
                        symbol = cachedSymbols.find(methodName)->second;
                    }
                    else
                    {
                        LibraryMap::const_iterator library = nativeLibraries.begin();
                        for (LibraryMap::const_iterator end = nativeLibraries.end(); library != end && symbol == NULL; ++library)
                        {
#if _W32
                            LOGGER.trace("looking for symbol '%s' at library '%s'",
                                         methodName.toCharArray(),
                                         library->second.getName().toCharArray());
                            FARPROC procedure = GetProcAddress((HMODULE) library->second.getHandle(),
                                                               methodName.toCharArray());
                            if (procedure != NULL)
                            {
                                symbol = (const void*) procedure;
                                AMANDA_SYNCHRONIZED(lock);
                                {
                                    cachedSymbols.insert(std::make_pair(methodName, (void*) symbol));
                                }
                                AMANDA_DESYNCHRONIZED(lock);
                            }
#endif
                        }
                    }

                    if (symbol == NULL)
                    {
                        LOGGER.error("unable to find symbol '%s' at any loaded library.", methodName.toCharArray());
                        result = ENOSYM;
                    }
                    else
                    {
                        procedure = new NativeCProcedure(symbol, methodName, methodArguments, methodReturnType);
                        AMANDA_SYNCHRONIZED(lock);
                        {
                            procedure->grab();
                            cachedNativeProcedures.insert(std::make_pair(name, procedure));
                        }
                        AMANDA_DESYNCHRONIZED(lock);
                    }
                }
                else
                {
                    LOGGER.error("invalid invocation language target (%s): no valid language binding on current context (0x%p).",
                                 language.substring(1).toCharArray(), this);
                    result = ENOLANG;
                }

                // If we have a valid invocation language target
                if (result != ENOLANG && procedure.isNotNull())
                {
                    procedure->call(stack);
                }
            }
            else
            {
                LOGGER.error("invalid native invocation language target: no target language specified.");
                result = ENOLANG;
            }
        }
    }
    // Return 0
    return result;
}

const Procedure* Context::getCachedLocalProcedure(const core::String& name) const
{
    return cachedProcedures.find(name)->second;
}

MemoryAllocator& Context::getMemoryAllocator() const
{
    return memoryAllocator->getReference();
}

const core::String& Context::getProperty(const core::String& key) const
{
    return properties.at(key);
}

bool Context::isCachedProcedure(const core::String& name) const
{
    return cachedProcedures.find(name) != cachedProcedures.end();
}

int Context::loadAndExecute(const core::String& fullPath)
{
    // The final result
    int result = EXIT_SUCCESS;

    // Load the executable module first
    ExecutableModule* module = loadModule(fullPath);
    if (!module)
    {
        throw core::Exception(core::String::makeFormattedString("failed load of module '%s'",
                                                                fullPath.toCharArray()));
    }

    // Look for the main function
    const binutils::Symbol::SymbolTableEntry* main = module->findSymbol(binutils::Module::ENTRY_POINT_PROCEDURE_NAME,
                                                                        binutils::Symbol::Type_Function);
    if (!main)
    {
        LOGGER.error("the selected module <%s> does not contain an entry point of name <%s>.",
                     fullPath.toCharArray(),
                     binutils::Module::ENTRY_POINT_PROCEDURE_NAME.toCharArray());
        throw nio::NoSuchFileException(fullPath);
    }
    else
    {
        LOGGER.trace("entry symbol <%s>\n"
                     "  - symbol address    : 0x%llx\n"
                     "  - symbol type       : %s\n"
                     "  - symbol size       : %lluB\n"
                     "      -- end of symbol data --",
                     binutils::Module::ENTRY_POINT_PROCEDURE_NAME.toCharArray(),
                     main->value,
                     binutils::Symbol::getTypeStringFromValue(main->type).toCharArray(),
                     main->size);

        // Create the procedure object and execute!!!
        core::WeakReference<Procedure> mainProcedure = new Procedure(this->getReference(), binutils::Module::ENTRY_POINT_PROCEDURE_NAME, main);
        mainProcedure->setExecutableModule(module->getReference());
        cacheProcedure(binutils::Module::ENTRY_POINT_PROCEDURE_NAME, mainProcedure);

        // Get the current time & date
        std::time_t localtime = std::time(NULL);
        core::String strLocalTime(std::ctime(&localtime));

        LOGGER.info("execution started (local date & time: %s)", strLocalTime.substring(0, strLocalTime.length() - 1).toCharArray());
        core::StrongReference<const Schedulable> mainSchedulable = scheduler->schedule(mainProcedure).getSelfPointer();

        // Wait until this thread (and all the spawned threads) finishes executing
        scheduler->waitForAll();

        // Collect the execution result
        result = (int) mainSchedulable->getReturnValueAsLong();
        LOGGER.info("execution finished, return value: %d", result);
    }
    return result;
}

void Context::loadLibrary(const core::String& fullPath)
{
    AMANDA_SYNCHRONIZED(lock);
    {
        LOGGER.info("attempting load of native library: %s", fullPath.toCharArray());

        // Separate the path components
        io::Path full(fullPath);
        core::String name = full.getLastPathComponent();
        core::String path = full.getParent().toString();

        // Create the library descriptor
        NativeLibraryDescriptor descriptor(name, path);

        // Load the library
        // LOAD METHOD ON WINDOWS
#ifdef _W32
        HMODULE handle = LoadLibraryA(fullPath.replaced('/', '\\').toCharArray());
        if (handle == NULL)
        {
            throw core::Exception(core::String::makeFormattedString("unable to load native library '%s'.", fullPath.toCharArray()));
        }

        LOGGER.info("module '%s' loaded successfully as a native library. Handle at 0x%p",
                    fullPath.toCharArray(), handle);
        descriptor.setHandle(handle);
#endif

        // Add the descriptor to the list of loaded libraries
        nativeLibraries.insert(std::make_pair(descriptor.getName(), descriptor));
    }
    AMANDA_DESYNCHRONIZED(lock);
}

ExecutableModule* Context::loadModule(const core::String& fullPath)
{
    // Get the resource as input stream
    ResourceIdentifier rid = ResourceIdentifier::parse(fullPath);
    core::StrongReference<io::InputStream> stream = fileSystem->getResourceAsStream(rid);
    core::StrongReference<io::ConsistentInputStream> cstream = new io::ConsistentInputStream(stream->getReference(), io::ConsistentInputStream::BIG_ENDIAN);

    // Trace the resulting id
    LOGGER.trace("loading module: %s (scheme: %s)", rid.toString().toCharArray(), rid.getScheme().toCharArray());

    // Create the module reader object & load the resultant module object
    // propagate exceptions if any.
    return moduleLoader->load(fullPath, cstream);
}

Context::NativeTypeList Context::parseFunctionArgumentTypes(const core::String& str) const
{
    NativeTypeList result;
    result.reserve(5);

    return result;
}

bool Context::putProperty(const core::String& key, const core::String& value)
{
    return properties.insert(std::make_pair(key, value)).second;
}

void Context::setMemoryAllocator(MemoryAllocator* memoryAllocator)
{
    assert(memoryAllocator != NULL && "Null pointer exception");

    // Set the reference to the memory allocator
    this->memoryAllocator = memoryAllocator;
}

void Context::setProperty(const core::String& key, const core::String& value)
{
    properties[key] = value;
}

void Context::setScheduler(const ThreadScheduler* scheduler)
{
    assert(scheduler != NULL && "Null pointer exception");
    this->scheduler = const_cast<ThreadScheduler*> (scheduler);
}

void Context::uncacheProcedure(const core::String& name) const
{
    AMANDA_SYNCHRONIZED(lock);
    {
        ProceduresCache::const_iterator it = cachedProcedures.find(name);
        if (it != cachedProcedures.end())
        {
            LOGGER.trace("un-caching local procedure '%s'...", name.toCharArray());
            it->second->release();              // Release the reference to the procedure
            cachedProcedures.erase(it->first);  // Remove its reference in the hash map
        }
    }
    AMANDA_DESYNCHRONIZED(lock);
}

// *************************** INNER CLASS ************************************

Context::NativeLibraryDescriptor::NativeLibraryDescriptor(const core::String& name, const core::String& path)
:
name(name),
path(path)
{
    procedures.reserve(10);
}

Context::NativeLibraryDescriptor::NativeLibraryDescriptor(const NativeLibraryDescriptor& rhs)
:
handle(rhs.handle),
name(rhs.name),
path(rhs.path),
procedures(rhs.procedures)
{
}

const Context::NativeLibraryDescriptor::NativeHandle Context::NativeLibraryDescriptor::getHandle() const
{
    return handle;
}

const core::String& Context::NativeLibraryDescriptor::getName() const
{
    return name;
}

const core::String& Context::NativeLibraryDescriptor::getPath() const
{
    return path;
}

void Context::NativeLibraryDescriptor::setHandle(NativeHandle h)
{
    this->handle = h;
}

void Context::NativeLibraryDescriptor::unload() const
{
    if (handle)
    {
#if _W32
        FreeLibrary((HMODULE) handle);
#endif
    }
}

