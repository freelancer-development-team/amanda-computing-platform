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
 * File:   Path.cpp
 * Author: Javier Marrero
 * 
 * Created on February 15, 2022, 12:24 AM
 */

#include <amanda-vm/io/Path.h>

using amanda::io::Path;

using amanda::core::String;

Path::Path()
:
pathName("")
{
}

Path::Path(const core::String& pathName)
:
pathName(pathName)
{
    normalize();
}

Path::Path(const Path& first, ...)
:
pathName(first.pathName)
{
}

Path::~Path()
{
}

String Path::getLastPathComponent()
{
    return toString().substring(toString().findLast(PATH_SEPARATOR) != String::NPOS ? toString().findLast(PATH_SEPARATOR) : toString().length());
}

Path Path::getParent()
{
    Path path(pathName);
    unsigned index = pathName.findLast(PATH_SEPARATOR);
    if (index != String::NPOS)
    {
        path = Path(pathName.substring(0, index));
    }
    return path;
}

Path& Path::join(const Path& second)
{
    pathName.append(PATH_SEPARATOR).append(second.pathName);
    return *this;
}

Path& Path::normalize()
{
    pathName.replace('\\', PATH_SEPARATOR);
    return *this;
}

String Path::toString() const
{
    return pathName;
}
