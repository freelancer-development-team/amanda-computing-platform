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
 * File:   ModuleLoader.h
 * Author: Javier Marrero
 *
 * Created on May 18, 2022, 9:43 PM
 */

#ifndef MODULELOADER_H
#define MODULELOADER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/ADT/Array.h>
#include <amanda-vm/Runtime/ExecutableModule.h>
#include <amanda-vm/Runtime/MemoryAllocator.h>
#include <amanda-vm/Logging/Logger.h>

// C++
#include <vector>
#include <map>

namespace amanda
{
namespace vm
{

/**
 * A <code>ModuleLoader</code> loads a module into memory. It uses the
 * <code>ModuleReader</code> interface, but also extends its functionality
 * in order to serve the virtual machine main purposes.
 * <p>
 * Modules are loaded and their symbols resolved at load time. Once the module
 * reader returns the <code>Module</code> object, 
 *
 * @author J. Marrero
 */
class ModuleLoader : public core::Object
{
    AMANDA_OBJECT(ModuleLoader, core::Object)
private:

    typedef std::map<const core::String, ExecutableModule*> ModuleMap;

public:

    typedef ModuleMap::const_iterator                       ModuleIterator;

    ModuleLoader(MemoryAllocator& allocator);
    virtual ~ModuleLoader();

    ExecutableModule*   get(const core::String& identifier) const;
    ModuleIterator      getIterator() const;
    ModuleIterator      getIteratorEnd() const;
    ExecutableModule*   load(const core::String& identifier, io::InputStream* stream);
    bool                isLoaded(const core::String& identifier) const;

private:

    static logging::Logger& LOGGER;

    MemoryAllocator&    allocator;
    ModuleMap           modules;

} ;

}
}

#endif /* MODULELOADER_H */

