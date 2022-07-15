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
 * File:   Module.cpp
 * Author: Javier Marrero
 * 
 * Created on March 12, 2022, 3:06 PM
 */

#include <amanda-vm/IL/Module.h>

using namespace amanda;
using namespace amanda::il;

Module::Module(const core::String& id)
:
identifier(id)
{
}

Module::~Module()
{
    for (std::vector<Function*>::iterator it = functions.begin(),
         end = functions.end(); it != end; ++it)
    {
        (*it)->release();
    }
}

void Module::addFunction(Function* f)
{
    f->grab();
    functions.push_back(f);
}

const std::vector<Function*>& Module::getFunctions() const
{
    return functions;
}

const core::String& Module::getIdentifier() const
{
    return identifier;
}
