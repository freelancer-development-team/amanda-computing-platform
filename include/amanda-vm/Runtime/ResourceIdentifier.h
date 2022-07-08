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
 * File:   ResourceIdentifier.h
 * Author: Javier Marrero
 *
 * Created on May 25, 2022, 11:16 PM
 */

#ifndef RESOURCEIDENTIFIER_H
#define RESOURCEIDENTIFIER_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace vm
{

class ResourceIdentifier : public core::Object
{
    AMANDA_OBJECT(ResourceIdentifier, core::Object)
public:

    static const core::String FS_SCHEME_DELIMITER;
    static const core::String LOCAL_FS_SCHEME;

    static ResourceIdentifier parse(const core::String& uri);

    const core::String&     getAddress() const;
    const core::String&     getScheme() const;
    bool                    isLocal() const;
    bool                    isScheme(const core::String& scheme) const;
    virtual core::String    toString() const;

protected:

    ResourceIdentifier(const core::String& scheme, const core::String& address);

    core::String address;
    core::String scheme;

} ;

}
}

#endif /* RESOURCEIDENTIFIER_H */

