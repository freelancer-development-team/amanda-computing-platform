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
 * File:   Console.cpp
 * Author: Javier Marrero
 * 
 * Created on February 13, 2022, 7:14 PM
 */

#include <amanda-vm/io/Console.h>
#include <amanda-vm-c/sdk-definitions.h>

#ifdef _W32
#    include <windows.h>
#endif

using amanda::io::Console;

using amanda::core::String;

Console::Console()
:
in(&File::STDIN),
out(&File::STDOUT),
err(&File::STDERR)
{
    ansiInitialized = true;

#ifdef _W32
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (outputHandle != INVALID_HANDLE_VALUE)
    {
        DWORD mode = 0;
        if (GetConsoleMode(outputHandle, &mode))
        {
            mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            if (!SetConsoleMode(outputHandle, mode))
            {
                ansiInitialized = false;
            }
        }
        else
        {
            ansiInitialized = false;
        }
    }
    else
    {
        ansiInitialized = false;
    }
#endif

}

Console::~Console()
{

}

void Console::clear()
{
    if (ansiInitialized)
    {
        err.printf("\033[2J");
    }
    else
    {
#ifdef _W32
        system("cls");
#else
        system("clear");
#endif
    }
}

String Console::formatAnsiString(const String& str, ...)
{
    String result;
    if (!ansiInitialized)
    {

    }
    else
    {

    }

    return result;
}

/* ========================================================================== */

Console& amanda::io::console()
{
    static Console tty;
    return tty;
}
