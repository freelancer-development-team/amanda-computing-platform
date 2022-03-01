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
 * File:   PrintStream.cpp
 * Author: Javier Marrero
 * 
 * Created on February 15, 2022, 12:31 AM
 */

#include <amanda-vm/io/PrintStream.h>

#include <stdio.h>
#include <stdarg.h>

using amanda::io::PrintStream;

PrintStream::PrintStream(const File* file)
:
FileOutputStream(file)
{
}

PrintStream::~PrintStream()
{
}

bool PrintStream::println(const core::String& fmt, ...) const
{
    bool result = false;
    if (file && (file->getAccessMode() & File::WRITE))
    {
        va_list va;
        va_start(va, fmt);

        char buffer[0x4000] = {0};
        vsnprintf(buffer, 0x3FFF, fmt.toCharArray(), va);
        strcat(buffer, "\n");

        va_end(va);
        result = file->write(buffer, strlen(buffer));
    }

    return result;
}

bool PrintStream::printf(const core::String& fmt, ...) const
{
    bool result = false;
    if (file && (file->getAccessMode() & File::WRITE))
    {
        va_list va;
        va_start(va, fmt);

        char buffer[0x4000] = {0};
        vsnprintf(buffer, 0x3FFF, fmt.toCharArray(), va);

        va_end(va);
        result = file->write(buffer, strlen(buffer));
    }

    return result;
}
