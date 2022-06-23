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
#include <amanda-vm/Binutils/package.hxx>
#include <amanda-vm-c/sdk-version.h>
#include <amanda-vm/NIO/IOException.h>
#include <amanda-vm/NIO/NoSuchFileException.h>

// C++
#include <ffi.h>
#include <ffitarget.h>
#include <cstdlib>
#include <cerrno>
#include <ctime>

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
    CONSOLE_HANDLER.setFormatter(fileFormatter->getReference());
    CONSOLE_HANDLER.setLevel(logging::Logger::WARN);

    // Add the handlers
    LOGGER.addHandler(CONSOLE_HANDLER);
    LOGGER.addHandler(fileHandler->getReference());

    // Trace the context creation
    LOGGER.trace("creating virtual machine context object (0x%p)", this);
}

Context::~Context()
{
    properties.clear();

    // Trace the context deletion
    LOGGER.trace("destroying virtual machine context @ 0x%p\n", this);
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

int Context::callNative(const core::String& name, void* arguments, void* retval) const
{
    // Log the attempt
    LOGGER.info("attempting call to native function named <%s> (args @0x%p, return value @0x%p)",
                name.toCharArray(), arguments, retval);

    // First of all, find the symbol we're looking for

    // Return 0
    return 0;
}

const core::String& Context::getProperty(const core::String& key) const
{
    return properties.at(key);
}

int Context::loadAndExecute(const core::String& fullPath)
{
    // The final result
    int result = EXIT_SUCCESS;

    // Load the executable module first
    ExecutableModule* module = loadModule(fullPath);

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

        // Get the current time & date
        std::time_t localtime = std::time(NULL);
        char*   localCTime = std::ctime(&localtime);
        char    strLocalTime[128] = {0};
        std::strncpy(strLocalTime, localCTime, strlen(localCTime) - 1);

        LOGGER.info("execution started (local date & time: %s)", strLocalTime);
        core::StrongReference<const Schedulable> mainSchedulable = scheduler->schedule(mainProcedure).getSelfPointer();

        // Wait until this thread (and all the spawned threads) finishes executing
        scheduler->waitForAll();

        // Collect the execution result
        result = (int) mainSchedulable->getReturnValue();
        LOGGER.info("execution finished, return value: %d", result);
    }
    return result;
}

void Context::loadLibrary(const core::String& fullPath)
{
    // Separate the path components
    io::Path full(fullPath);
    core::String name = full.getLastPathComponent();
    core::String path = full.getParent().toString();

    // Create the library descriptor
    NativeLibraryDescriptor descriptor(name, path);

    // Load the library
    io::File library(fullPath, io::File::READ);
    if (!library.isFile())
    {
        throw nio::NoSuchFileException(library.getPath());
    }

    // Add the descriptor to the list of loaded libraries
    nativeLibraries.insert(std::make_pair(descriptor.getName(), descriptor));
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

// *************************** INNER CLASS ************************************

Context::NativeLibraryDescriptor::NativeLibraryDescriptor(const core::String& name, const core::String& path)
:
name(name),
path(path)
{
}

Context::NativeLibraryDescriptor::NativeLibraryDescriptor(const NativeLibraryDescriptor& rhs)
:
name(rhs.name),
path(rhs.path)
{
}

const core::String& Context::NativeLibraryDescriptor::getName() const
{
    return name;
}

const core::String& Context::NativeLibraryDescriptor::getPath() const
{
    return path;
}

