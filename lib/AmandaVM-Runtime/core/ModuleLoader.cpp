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
 * File:   ModuleLoader.cpp
 * Author: Javier Marrero
 * 
 * Created on May 18, 2022, 9:43 PM
 */

#include <amanda-vm/Runtime/ModuleLoader.h>

using namespace amanda;
using namespace amanda::vm;

ModuleLoader::ModuleLoader()
{
    // Reserve enough space for loading 10 modules without rebuilding the array
    modules.reserve(10);
}

ModuleLoader::~ModuleLoader()
{
    // Release a reference to every module.
    for (unsigned i = 0; i < modules.size(); ++i)
    {
        modules.at(i)->release();
    }
}

void ModuleLoader::addModules(const adt::Array<const binutils::Module*>& array)
{
    for (unsigned i = 0; i < array.length(); ++i)
    {
        addModule(array[i]);
    }
}

void ModuleLoader::addModule(const binutils::Module* module)
{
    // Assertions
    assert(module != NULL && "Null pointer exception.");

    // Grab a reference to the module
    module->grab();

    // Push the reference back into the vector
    modules.push_back(module);

    // Shouldn't this link the external symbols?
}


