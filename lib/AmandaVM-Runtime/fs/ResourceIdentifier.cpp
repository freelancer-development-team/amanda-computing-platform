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
 * File:   ResourceIdentifier.cpp
 * Author: Javier Marrero
 * 
 * Created on May 25, 2022, 11:16 PM
 */

#include <amanda-vm/Runtime/ResourceIdentifier.h>
#include <amanda-vm/Runtime/InvalidResourceIdentifierException.h>

using namespace amanda;
using namespace amanda::vm;

const core::String ResourceIdentifier::LOCAL_FS_SCHEME = "vfs:";

ResourceIdentifier ResourceIdentifier::parse(const core::String& uri)
{
    std::vector<core::String> splitted = uri.split(":", 1);
    if (splitted.size() != 2)
    {
        throw InvalidResourceIdentifierException(uri);
    }

    return ResourceIdentifier(splitted[0], splitted[1]);
}

ResourceIdentifier::ResourceIdentifier(const core::String& scheme, const core::String& address)
:
address(address),
scheme(scheme)
{
}

bool ResourceIdentifier::isLocal() const
{
    return scheme == LOCAL_FS_SCHEME;
}

core::String ResourceIdentifier::toString() const
{
    return scheme + address;
}



