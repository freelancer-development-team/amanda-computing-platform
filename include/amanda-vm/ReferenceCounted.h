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
 * File:   ReferenceCounted.h
 * Author: Javier Marrero
 *
 * Created on February 13, 2022, 2:34 PM
 */

#ifndef REFERENCECOUNTED_H
#define REFERENCECOUNTED_H

namespace amanda
{
namespace core
{

class ReferenceCounted
{
public:

    ReferenceCounted();
    virtual ~ReferenceCounted();

    void grab();
    void grabWeakReference();
    void release();
    void releaseWeakReference();
    
private:

    long long strongReferenceCount;
    long long weakReferenceCount;
} ;

}
}

#endif /* REFERENCECOUNTED_H */

