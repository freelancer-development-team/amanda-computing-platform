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
 * File:   ReferenceCounted.cpp
 * Author: Javier Marrero
 * 
 * Created on February 13, 2022, 2:34 PM
 */

#include <amanda-vm/ReferenceCounted.h>

#include <assert.h>

using amanda::core::ReferenceCounted;

ReferenceCounted::ReferenceCounted()
:
strongReferenceCount(0),
weakReferenceCount(0)
{
}

ReferenceCounted::~ReferenceCounted()
{
}

void ReferenceCounted::grab() const
{
    strongReferenceCount++;
}

void ReferenceCounted::grabWeakReference() const
{
    weakReferenceCount++;
}

void ReferenceCounted::release() const
{
    assert(strongReferenceCount >= 0);
    if (--strongReferenceCount <= 0)
    {
        delete this;
    }
}

void ReferenceCounted::releaseWeakReference() const
{
    assert(weakReferenceCount >= 0);
    if (--weakReferenceCount <= 0)
    {
        if (strongReferenceCount == 0)
        {
            delete this;
        }
    }
}



