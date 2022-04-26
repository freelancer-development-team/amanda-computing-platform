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
 * File:   Flushable.h
 * Author: Javier Marrero
 *
 * Created on April 11, 2022, 11:29 PM
 */

#ifndef FLUSHABLE_H
#define FLUSHABLE_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace io
{

class Flushable : extends core::Interface
{
    AMANDA_OBJECT(Closeable, core::Interface)

public:

    virtual void flush() const = 0;
};

}
}

#endif /* FLUSHABLE_H */

