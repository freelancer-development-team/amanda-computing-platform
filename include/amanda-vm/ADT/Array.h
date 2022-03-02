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
 * File:   Array.h
 * Author: Javier Marrero
 *
 * Created on March 1, 2022, 1:51 PM
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <amanda-vm/Interface.h>
#include <amanda-vm-c/sdk-assert-helper.h>

#include <cstdlib>
#include <cstring>

namespace amanda
{
namespace adt
{

/**
 * A simple static array.
 */
template <typename T>
class Array : extends core::Object
{

    AMANDA_OBJECT(Array<T>, core::Object)

public:

    Array(size_t count)
    :
    array((T*) calloc(count, sizeof (T))),
    size(count)
    {
        assert(array != NULL && ASSERT_MESSAGE("Unable to allocate array!"));
    }

    Array(const Array<T>& rhs)
    :
    array((T*) calloc(rhs.size, sizeof (T))),
    size(rhs.size)
    {
        for (size_t i = 0; i < size; i++)
        {
            array[i] = rhs.array[i];
        }
    }

    ~Array()
    {
        free(array);
    }

    size_t length()
    {
        return size;
    }

    T& operator[](size_t index)
    {
        assert(index < size && ASSERT_MESSAGE("Array index out of bounds."));
        return array[index];
    }

private:

    T*      array;
    size_t  size;
} ;

}
}

#endif /* ARRAY_H */

