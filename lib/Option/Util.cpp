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

#include <amanda-vm/Option/Option.h>

using amanda::core::String;

String amanda::cli::stripLeadingAndTrailingQuotes(const core::String& str)
{
    String result(str);
    const int length = str.length();
    
    if ((length > 1) && (str.startsWith("\"") && (str.endsWith("\""))))
    {
        result = str.substring(1, length - 1);
    }
    return result;
}

String amanda::cli::stripLeadingHyphens(const core::String& str)
{
    String result(str);
    if (str.startsWith("--"))
    {
        result = str.substring(2);
    }
    else if (str.startsWith("-"))
    {
        result = str.substring(1);
    }

    return result;
}
