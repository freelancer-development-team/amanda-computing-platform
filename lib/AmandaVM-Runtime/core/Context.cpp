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
#include <amanda-vm-c/sdk-version.h>
#include <amanda-vm/NIO/IOException.h>
#include <amanda-vm/NIO/NoSuchFileException.h>

// C++
#include <cstdlib>
#include <cerrno>

using namespace amanda;
using namespace amanda::vm;

// Const fields
const core::String Context::OS_NAME_KEY = "amanda::vm::os.name";
const core::String Context::SDK_VERSION_KEY = "amanda::vm::sdk.version";

Context::Context(MemoryAllocator* memoryAllocator,
                 const core::String& path)
:
memoryAllocator(memoryAllocator),
memoryManager(amanda::eliminateConstness(&memoryAllocator->getMemoryManager()))
{
    // Get the virtual machine execution path
    {
        // Get the full path object
        io::Path full(path);

        // Assign to the path reference
        this->path = new io::Path(full.getParent().toString());
    }

    // Initialize the default system properties.
    initializeSystemProperties();
}

Context::~Context()
{
    properties.clear();
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

