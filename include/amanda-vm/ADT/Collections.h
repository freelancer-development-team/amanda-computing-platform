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
 * File:   Collections.h
 * Author: Javier Marrero
 *
 * Created on February 27, 2022, 11:18 PM
 */

#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include <map>
#include <list>
#include <vector>

namespace amanda
{
namespace adt
{

/**
 * Returns true if a given container contains a given element.
 * 
 * @param container
 * @param element
 * @return
 */
template <class C, class E>
static inline bool contains(const C& container, const E& element)
{
    return container.find(element) != container.end();
};

/**
 * Overloading of the <code>contains</code> method for working with
 * vectors.
 *
 * @param container
 * @param element
 * @return
 */
template <typename E>
static inline bool contains(const std::vector<E>& container, const E& element)
{
    bool result = false;

    typename std::vector<E>::const_iterator iter;
    for (iter = container.begin();
         iter != container.end() && (!result);
         ++iter)
    {
        if (*iter == element)
        {
            result = true;
        }
    }
    return result;
}

/**
 * Overloading of the contains method for working with STL linked lists.
 *
 * @param container
 * @param element
 * @return
 */
template <typename E>
static inline bool contains(const std::list<E>& container, const E& element)
{
    bool result = false;

    typename std::list<E>::const_iterator iter;
    for (iter = container.begin();
         iter != container.end() && (!result);
         ++iter)
    {
        if (*iter == element)
        {
            result = true;
        }
    }
    return result;
}

template <typename E>
static inline void vectorAsList(const std::vector<E>& vector, std::list<E>& list)
{
    typename std::vector<E>::const_iterator iter;
    for (iter = vector.begin(); iter != vector.end(); iter++)
    {
        list.push_back(*iter);
    }
}

template <typename E>
static inline std::list<E>& vectorAsList(const std::vector<E>& vector)
{
    std::list<E>& list;
    vectorAsList(vector, list);
    return list;
}

}
}

#endif /* COLLECTIONS_H */

