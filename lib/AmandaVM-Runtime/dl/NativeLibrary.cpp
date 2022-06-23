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
 * File:   NativeLibrary.cpp
 * Author: Javier Marrero
 * 
 * Created on June 23, 2022, 2:03 AM
 */

#include <amanda-vm/Runtime/NativeLibrary.h>
#include <amanda-vm/Runtime/LinkageError.h>
#include <amanda-vm-c/sdk-definitions.h>

// Windows
#ifdef _W32
#    include <windows.h>
#endif

using namespace amanda;
using namespace amanda::vm;

NativeLibrary::NativeLibrary(const core::String& path)
:
handle(NULL),
name(path)
{
#ifdef _W32
    handle = LoadLibrary(path.toCharArray());
    if (!handle)
    {
        throw LinkageError(core::String::makeFormattedString("unable to load dynamic link library (%s).",
                                                             path.toCharArray()));
    }
#endif
}

NativeLibrary::~NativeLibrary()
{
#ifdef _W32
    FreeLibrary((HMODULE) handle);
#endif
}


