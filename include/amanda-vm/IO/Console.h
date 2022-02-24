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
 * File:   Console.h
 * Author: Javier Marrero
 *
 * Created on February 13, 2022, 7:14 PM
 */

#ifndef CONSOLE_H
#define CONSOLE_H

#include <amanda-vm/Object.h>
#include <amanda-vm/String.h>
#include <amanda-vm/io/File.h>
#include <amanda-vm/io/PrintStream.h>

namespace amanda
{
namespace io
{

class Console : public amanda::core::Object
{
    AMANDA_OBJECT(Console, amanda::core::Object)

public:

    friend Console& console();

    PrintStream in;
    PrintStream out;
    PrintStream err;

    void clear();

    /**
     * Format a string with ANSI escape codes in order to comply with hardware.
     */
    core::String formatAnsiString(const core::String& str, ...);

private:

    bool ansiInitialized;

    /// Do not use this constructor. Use the 'console' function instead.
    Console();
    ~Console();

} ;

Console& console();

}
}

#endif /* CONSOLE_H */

