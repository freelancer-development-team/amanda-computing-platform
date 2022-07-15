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
 * File:   CodeGenContext.cpp
 * Author: Javier Marrero
 * 
 * Created on March 12, 2022, 5:59 PM
 */

#include <amanda-vm/IL/CodeGenContext.h>
#include <amanda-vm/IL/Module.h>

#include <algorithm>

using namespace amanda;
using namespace amanda::il;

CodeGenContext::CodeGenContext()
:
vid(0)
{
}

CodeGenContext::~CodeGenContext()
{
}

unsigned CodeGenContext::allocateValueIdentifier()
{
    return vid++;
}

Module* CodeGenContext::getModule() const
{
    return module;
}

const Type* CodeGenContext::getPrimitiveType(Type::TypeID idNumber)
{
    for (unsigned i = 0; i < types.size(); ++i)
    {
        if (types.at(i)->getTypeId() == idNumber)
        {
            return types.at(i);
        }
    }
    return NULL;
}

void CodeGenContext::setModule(Module* module)
{
    this->module = module;
}
