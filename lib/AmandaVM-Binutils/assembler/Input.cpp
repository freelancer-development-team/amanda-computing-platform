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
 * File:   Input.cpp
 * Author: Javier Marrero
 * 
 * Created on April 11, 2022, 11:43 PM
 */

#include <amanda-vm/Binutils/Input.h>
#include <amanda-vm/ADT/Array.h>

// C++
#include <climits>

using namespace amanda;
using namespace amanda::binutils;

core::String amanda::binutils::buildAssemblerInputFromMemory(const char* mem)
{
    return core::String(mem);
}

core::String amanda::binutils::buildAssemblerInputFromFile(const io::File* file)
{
    assert(file != NULL && "Null pointer exception.");

    core::String result;
    if (file->canRead())
    {
        bool eof = false;
        do
        {
            // Create the line buffer object & read a line at a time.
            char buffer[1000] = {0};
            eof = file->readline(buffer, 1000) == false;
            
            result.append(buffer).append('\n');
        } while (!eof);
    }
    return result;
}

AssemblerInputStream amanda::binutils::associateInputStream(const core::String& streamName, const core::String& stream)
{
    return std::make_pair(streamName, stream);
}
