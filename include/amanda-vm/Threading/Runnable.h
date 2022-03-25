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
 * File:   Runnable.h
 * Author: Javier Marrero
 *
 * Created on March 24, 2022, 11:35 PM
 */

#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace concurrent
{

class Runnable : public core::Object
{
    AMANDA_OBJECT(Runnable, core::Object)
public:

    virtual void run() = 0;
    
} ;

}
}

#endif /* RUNNABLE_H */

