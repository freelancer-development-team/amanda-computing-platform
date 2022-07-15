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
 * File:   PassManager.cpp
 * Author: Javier Marrero
 * 
 * Created on March 23, 2022, 9:17 AM
 */

#include <amanda-vm/IL/PassManager.h>

using namespace amanda;
using namespace amanda::il;

PassManager::PassManager(Module& module)
:
module(module)
{
}

PassManager::~PassManager()
{
    for (PassList::iterator it = passes.begin(); it != passes.end(); ++it)
    {
        // Release the owned reference (possibly releasing all the associated
        // memory)
        (*it)->release();
    }
}

bool PassManager::addPassForScheduling(AbstractPass* pass)
{
    assert(pass != NULL && "Null pointer exception.");

    const std::pair < PassList::const_iterator, bool>& result = passes.insert(pass);
    if (result.second)
    {
        pass->grab(); // We own a reference to the pass.
    }

    return result.second;
}

void PassManager::run()
{
    for (PassList::const_iterator it = passes.begin(); it != passes.end(); ++it)
    {
        assert(*it != NULL && "Null pointer exception.");
        AbstractPass* pass = *it;

        pass->setModule(this->module);
        pass->runTransformation();
    }
}

void PassManager::setModule(Module& module)
{
    this->module = module;
}



