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
 * File:   Path.h
 * Author: Javier Marrero
 *
 * Created on February 15, 2022, 12:24 AM
 */

#ifndef PATH_H
#define PATH_H

#include <amanda-vm/Object.h>
#include <amanda-vm/String.h>

namespace amanda
{
namespace io
{

class Path : public amanda::core::Object
{
    AMANDA_OBJECT(Path, amanda::core::Object)

public:

    static const char PATH_SEPARATOR = '/';

    Path(const core::String& pathName = core::String::EMPTY);
    Path(const Path& first, const Path& second);
    Path(const Path& rhs);
    virtual ~Path();

    virtual core::String    getLastPathComponent();
    virtual Path            getParent();
    virtual Path&           join(const core::String& second);
    virtual Path&           join(const Path& second);
    virtual Path&           normalize();
    virtual core::String    toString() const;

private:

    core::String pathName;
} ;

}
}

#endif /* PATH_H */

