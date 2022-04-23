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

#include <amanda-vm/Integer.h>
#include <amanda-vm/IllegalArgumentException.h>

// C++
#include <cstdlib>
#include <cerrno>

using namespace amanda;
using namespace amanda::core;
using namespace amanda::util;

unsigned long long amanda::util::fromStreamOfBytes(const char* bytes)
{
    // This union allows to treat signed/unsigned values as the same stream of bytes.
    union
    {
        unsigned long long  ull;
        signed long long    sll;
    } result = {0ULL};

    // Create a literal object
    core::String literal(bytes);

    if (literal.startsWith("0x", false))
    {
        // Hexadecimal constant
        result.ull = strtoull(bytes, NULL, 16);
    }
    else if (literal.startsWith("0b", false))
    {
        // Binary constant
        result.ull = strtoull(bytes, NULL, 2);
    }
    else if (literal.startsWith("0") && literal.length() > 1)
    {
        // Octal constant
        result.ull = strtoull(bytes, NULL, 8);
    }
    else
    {
        // Decimal constant
        if (literal.startsWith("-"))
        {
            // Signed constant. It is safe to use atol
            result.sll = strtoll(bytes, NULL, 10);
        }
        else
        {
            result.ull = strtoull(bytes, NULL, 10);
        }
    }

    // Check for errors & raise an exception if an error was recorded
    if (errno == ERANGE)
    {
        throw IllegalArgumentException("Integer literal out of limits.");
    }
    return result.ull;
}

