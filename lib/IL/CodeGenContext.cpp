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
 * File:   CodeGenContext.cpp
 * Author: Javier Marrero
 * 
 * Created on March 12, 2022, 5:59 PM
 */

#include <amanda-vm/IL/CodeGenContext.h>
#include <amanda-vm/IL/Module.h>

using namespace amanda;
using namespace amanda::il;

CodeGenContext::CodeGenContext()
{
}

CodeGenContext::~CodeGenContext()
{
}

void CodeGenContext::setModule(Module* module)
{
    this->module = module;
}
