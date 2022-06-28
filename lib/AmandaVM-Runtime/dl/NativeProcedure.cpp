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
 * File:   NativeProcedure.cpp
 * Author: Javier Marrero
 * 
 * Created on May 25, 2022, 10:57 PM
 */

#include <amanda-vm/Runtime/NativeProcedure.h>

using namespace amanda;
using namespace amanda::vm;

const core::String& NativeProcedure::FFI_TYPE_INT8              = "i8";
const core::String& NativeProcedure::FFI_TYPE_INT16             = "i16";
const core::String& NativeProcedure::FFI_TYPE_INT32             = "i32";
const core::String& NativeProcedure::FFI_TYPE_INT64             = "i64";
const core::String& NativeProcedure::FFI_TYPE_NATIVE_POINTER    = "p";
const core::String& NativeProcedure::FFI_TYPE_NONE              = "nil";

NativeProcedure::NativeProcedure(fpointer_t address, const core::String& name)
:
functionHandle(address),
name(name)
{
    assert(address != NULL && "Null pointer exception");
}

const core::String& NativeProcedure::getName() const
{
    return name;
}

