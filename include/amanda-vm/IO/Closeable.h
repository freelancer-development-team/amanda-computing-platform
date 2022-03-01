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
 * File:   Closeable.h
 * Author: Javier Marrero
 *
 * Created on March 1, 2022, 2:03 AM
 */

#ifndef CLOSEABLE_H
#define CLOSEABLE_H

#include <amanda-vm/Interface.h>

namespace amanda
{
namespace io
{

/**
 * Inheritors of this interface automatically obtain the method 'close'. It is
 * used to implement streams, that need the method close for releasing it
 * resources.
 *
 * @autor J. Marrero
 */
class Closeable : extends core::Interface
{
    AMANDA_OBJECT(Closeable, core::Interface)

public:

    virtual void close() = 0;
};

}
}

#endif /* CLOSEABLE_H */

