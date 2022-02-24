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
 * File:   Class.h
 * Author: Javier Marrero
 *
 * Created on February 13, 2022, 5:44 PM
 */

#ifndef CLASS_H
#define CLASS_H

namespace amanda
{
namespace core
{

class Class
{
public:

    Class(const char* name, const Class* super);

    const char*     getName() const;
    const Class*    getSuperClass() const;
    bool            is(const Class& type) const;

private:

    static int calculateHashFromClassName(const char* name);

    const char*     name;
    const int       hash;
    const Class*    super;
} ;

}
}

#endif /* CLASS_H */

