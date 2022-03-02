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
 * File:   Interface.h
 * Author: Javier Marrero
 *
 * Created on March 1, 2022, 2:11 AM
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include <amanda-vm/Object.h>

namespace amanda
{
namespace core
{


#define implements      virtual public
#define extends         virtual public


/**
 * Interfaces are the way the Amanda framework deals with multiple inheritance
 * and RTTI issues. Interfaces favor composition over pure inheritance, which
 * is a good practice. Interfaces in this context, although somewhat similar to
 * Java interfaces, is more alike to a mixin. Unlike Java interfaces, these
 * can contain variables and not public methods. Of course, this derives from
 * the fact that these are normal C++ classes.
 * <p>
 *
 * @author J. Marrero
 */
class Interface : extends Object
{
    AMANDA_OBJECT(Interface, Object)

public:

} ;

}
}

#endif /* INTERFACE_H */

