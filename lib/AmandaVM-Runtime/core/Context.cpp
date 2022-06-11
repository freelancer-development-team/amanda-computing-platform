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
#include <cstdlib>
#include <cerrno>

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
moduleLoader(new ModuleLoader())
{
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

    // Configure the handlers
    CONSOLE_HANDLER.setFormatter(FORMATTER);

    // Add the handlers
    LOGGER.addHandler(CONSOLE_HANDLER);

    // Trace the context creation
    LOGGER.trace("creating virtual machine context object (0x%p)", this);
}

Context::~Context()
{
    properties.clear();

    // Trace the context deletion
    LOGGER.trace("destroying virtual machine context @ 0x%p", this);
}

void Context::execute(binutils::Function* function)
{
    // Spawn a new thread with the procedure defined by the selected
    // function as function
    core::StrongReference<Procedure> procedure = new Procedure(this->getConstReference(), function);
    scheduler->schedule(procedure);
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

const core::String& Context::getProperty(const core::String& key) const
{
    return properties.at(key);
}

binutils::Module* Context::loadAndExecute(const core::String& fullPath)
{
    // Load the module as a library first.
    binutils::Module* module = loadModule(fullPath);

    // Initialize the first virtual machine thread (the main thread) with
    // information on the current thread
    LOGGER.trace("initializing virtual machine 'init' thread...");

    // If the module does not contain an entry point throw an exception
    if (module->hasEntryPoint() == false)
    {
        throw binutils::InvalidFileFormatException(core::String::makeFormattedString("The module <%s> does not contain a valid entry point.",
                                                                                     fullPath.toCharArray()),
                                                   fullPath);
    }
    else
    {
        // Create the procedure with the main entry point
        binutils::Function* mainFunction = static_cast<binutils::Function*> (module->findSymbol(binutils::Module::ENTRY_POINT_PROCEDURE_NAME));
        assert(mainFunction != NULL && "Null pointer exception.");

        execute(mainFunction);
    }
    return module;
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

binutils::Module* Context::loadModule(const core::String& fullPath)
{
    // Get the resource as input stream
    ResourceIdentifier rid = ResourceIdentifier::parse(fullPath);
    core::StrongReference<io::InputStream> stream = fileSystem->getResourceAsStream(rid);

    // Trace the resulting id
    LOGGER.trace("loading module: %s (scheme: %s)", rid.toString().toCharArray(), rid.getScheme().toCharArray());

    // Create the module reader object & load the resultant module object
    // propagate exceptions if any.
    binutils::ModuleReader reader(rid.getAddress(), stream->getReference());
    binutils::Module* module = reader.read();
    moduleLoader->addModule(fullPath, module);

    return module;
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
    this->scheduler = const_cast<ThreadScheduler*>(scheduler);
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

