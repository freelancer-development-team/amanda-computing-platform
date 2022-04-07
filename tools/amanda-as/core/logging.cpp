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

#include <amanda-as/logging.h>
#include <AmandaSDK.h>

#include <cstdlib>
#include <cstdarg>

using namespace amanda;
using namespace amanda::io;

static void printFormatted(const core::String& fmt, va_list& va)
{
    char* buffer = (char*) calloc(0x8000, sizeof (char));
    assert(buffer != NULL && "Not enough memory.");
    vsnprintf(buffer, 0x8000, fmt.toCharArray(), va);

    io::console().err.println(core::String(buffer));
    free(buffer);
}

#define VA_LIST_INIT()  va_list va; \
                        va_start(va, fmt)

#define VA_LIST_END()   va_end(va)
#define VA_LIST_NAME    va

void amanda::as::logger::info(const core::String& fmt, ...)
{
    VA_LIST_INIT();
    printFormatted(core::String("amanda-as: \033[1minfo\033[0m: ").append(fmt), VA_LIST_NAME);
    VA_LIST_END();
}

void amanda::as::logger::warning(const core::String& fmt, ...)
{
    VA_LIST_INIT();
    printFormatted(core::String("amanda-as: \033[1m\033[33mwarn\033[0m: ").append(fmt), VA_LIST_NAME);
    VA_LIST_END();
}

void amanda::as::logger::error(const core::String& fmt, ...)
{
    VA_LIST_INIT();
    printFormatted(core::String("amanda-as: \033[1m\033[31merror\033[0m: ").append(fmt), VA_LIST_NAME);
    VA_LIST_END();
}

void amanda::as::logger::fatal(const core::String& fmt, ...)
{
    VA_LIST_INIT();
    printFormatted(core::String("amanda-as: \033[1m\033[31mfatal error\033[0m: ").append(fmt), VA_LIST_NAME);
    VA_LIST_END();

    // Abort since we hit a fatal exception.
    abort();
}
