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
 * File:   ResourceIdentifier.cpp
 * Author: Javier Marrero
 * 
 * Created on May 25, 2022, 11:16 PM
 */

#include <amanda-vm/Runtime/ResourceIdentifier.h>
#include <amanda-vm/Runtime/InvalidResourceIdentifierException.h>

using namespace amanda;
using namespace amanda::vm;

const core::String ResourceIdentifier::FS_SCHEME_DELIMITER = "://";
const core::String ResourceIdentifier::LOCAL_FS_SCHEME = "vfs";

ResourceIdentifier ResourceIdentifier::parse(const core::String& uri)
{
    // The return components
    core::String scheme;
    core::String address;

    if (uri.find(FS_SCHEME_DELIMITER) != core::String::NPOS)
    {
        std::vector<core::String> splitted = uri.split(FS_SCHEME_DELIMITER, 1);
    }
    else
    {
        scheme = LOCAL_FS_SCHEME;
        address = uri;
    }

    return ResourceIdentifier(scheme, address);
}

ResourceIdentifier::ResourceIdentifier(const core::String& scheme, const core::String& address)
:
address(address),
scheme(scheme)
{
}

const core::String& ResourceIdentifier::getAddress() const
{
    return address;
}

const core::String& ResourceIdentifier::getScheme() const
{
    return scheme;
}

bool ResourceIdentifier::isLocal() const
{
    return isScheme(LOCAL_FS_SCHEME);
}

bool ResourceIdentifier::isScheme(const core::String& scheme) const
{
    return this->scheme.toLower() == scheme.toLower();
}

core::String ResourceIdentifier::toString() const
{
    return scheme + FS_SCHEME_DELIMITER + address;
}



