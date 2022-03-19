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
 * File:   MissingOptionException.cpp
 * Author: Javier Marrero
 * 
 * Created on March 2, 2022, 9:09 PM
 */

#include <amanda-vm/Option/MissingOptionException.h>

using namespace amanda::cli;

using amanda::core::String;

String MissingOptionException::createMessage(const std::list<const Option*>& missingOptions)
{
    String buffer("Missing required option");
    buffer.append(missingOptions.size() == 1 ? "" : "s");
    buffer.append(": ");

    std::list<const Option*>::const_iterator iter = missingOptions.begin();
    while (iter != missingOptions.end())
    {
        buffer.append((*iter)->toString());
        if (++iter != missingOptions.end())
        {
            buffer.append(", ");
        }
    }

    return buffer;
}

MissingOptionException::MissingOptionException(const std::list<const Option*>& missingOptions)
:
ParseException(createMessage(missingOptions))
{
}

MissingOptionException::MissingOptionException(const core::String& message)
:
ParseException(message)
{
}

MissingOptionException::~MissingOptionException() throw ()
{
}

