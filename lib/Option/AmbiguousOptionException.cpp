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
 * File:   AmbiguousOptionException.cpp
 * Author: Javier Marrero
 * 
 * Created on March 12, 2022, 10:28 AM
 */

#include <amanda-vm/Option/AmbiguousOptionException.h>

using namespace amanda;
using namespace amanda::cli;

using amanda::core::String;

AmbiguousOptionException::AmbiguousOptionException(const core::String& option, std::list<core::String> matchingOptions)
:
ParseException(createMessage(option, matchingOptions)),
matchingOptions(matchingOptions)
{
}

AmbiguousOptionException::~AmbiguousOptionException() throw ()
{
}

const std::list<String>& AmbiguousOptionException::getMatchingOptions() const
{
    return matchingOptions;
}

String AmbiguousOptionException::createMessage(const core::String& option, std::list<core::String> matchingOptions)
{
    String buf("ambiguous option: '");
    buf.append(option).append("' (could be: ");

    std::list<core::String>::iterator it = matchingOptions.begin();
    while (it != matchingOptions.end())
    {
        buf.append('\'').append(*it).append('\'');
        if (++it != matchingOptions.end())
        {
            buf.append(", ");
        }
    }

    return buf.append(')');
}
