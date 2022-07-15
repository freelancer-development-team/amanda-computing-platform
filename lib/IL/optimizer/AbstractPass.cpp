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
 * File:   AbstractPass.cpp
 * Author: Javier Marrero
 * 
 * Created on March 23, 2022, 9:20 AM
 */

#include <amanda-vm/IL/AbstractPass.h>

using namespace amanda;
using namespace il;

AbstractPass::AbstractPass()
:
name(getClass().getName())
{
}

AbstractPass::AbstractPass(const core::String& name)
:
name(name)
{
}

AbstractPass::~AbstractPass()
{
}

void AbstractPass::setName(core::String name)
{
    this->name = name;
}

const core::String& AbstractPass::getName() const
{
    return name;
}

void AbstractPass::setModule(Module& module)
{
    assert(!this->module.isNull() && "Null pointer exception.");
    this->module = &module;
}

Module& AbstractPass::getModule() const
{
    assert(module.isNull() == false && "Null pointer exception.");
    return *module;
}

void AbstractPass::runTransformation()
{
}






