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
 * File:   Types.h
 * Author: Javier Marrero
 *
 * Created on February 28, 2022, 12:38 AM
 */

#ifndef TYPES_H
#define TYPES_H

#include <cstddef>
#include <cstring>

namespace amanda
{

/**
 * This template function eliminates "constness" of a reference. Use at your
 * own risk, since const elimination can be harmful (const things are const
 * for a reason).
 *
 * @param constReference
 * @return
 */
template <typename T>
static inline T& eliminateConstness(const T& constReference)
{
    return const_cast<T&> (constReference);
}

/**
 * Fills the values of an array with a specified value. The count parameter is
 * not the physical size, but the element count of the array.
 *
 * @param array
 * @param value
 * @param count
 */
template <typename T>
static inline void fill(T array[], T value, size_t count)
{
    for (size_t i = 0; i < count; ++i)
    {
        array[i] = value;
    }
}

/**
 * Fills the values of an array through a range of indexes.
 *
 * @param array
 * @param value
 * @param start
 * @param end
 */
template <typename T>
static inline void fill(T array[], T value, size_t start, size_t end)
{
    for (size_t i = start; i < end; i++)
    {
        array[i] = value;
    }
}

}

#endif /* TYPES_H */

