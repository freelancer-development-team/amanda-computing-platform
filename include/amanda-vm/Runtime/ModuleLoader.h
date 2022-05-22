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
 * File:   ModuleLoader.h
 * Author: Javier Marrero
 *
 * Created on May 18, 2022, 9:43 PM
 */

#ifndef MODULELOADER_H
#define MODULELOADER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/ADT/Array.h>
#include <amanda-vm/Binutils/ModuleReader.h>

// C++
#include <vector>

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
public:

    ModuleLoader();
    virtual ~ModuleLoader();
    
    void addModules(const adt::Array<const binutils::Module*>& array);
    void addModule(const binutils::Module* module);

private:

    typedef std::vector<const binutils::Module*> ModuleList;

    ModuleList modules;
} ;

}
}

#endif /* MODULELOADER_H */

