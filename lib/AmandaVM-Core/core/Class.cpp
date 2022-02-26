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

#include <amanda-vm/Class.h>

#include <string.h>

using namespace amanda::core;

int Class::calculateHashFromClassName(const char* name)
{
    int hash = 0;

    for (size_t i = 0; i < strlen(name); i++)
    {
        char c = *name++;

        hash += c;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

Class::Class(const char* name, const Class* super)
:
name(name),
hash(calculateHashFromClassName(name)),
super(super)
{
}

const char* Class::getName() const
{
    return name;
}

const Class* Class::getSuperClass() const
{
    return super;
}

bool Class::is(const Class& type) const
{
    bool result = false;
    if (!result)
    {
        const Class* current = this;
        while (current != NULL)
        {
            if (current->hash == type.hash)
            {
                result = true;
                break;
            }
            current = current->super;
        }
    }
    return result;
}
