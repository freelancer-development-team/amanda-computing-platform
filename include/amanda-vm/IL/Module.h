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
 * File:   Module.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 3:06 PM
 */

#ifndef MODULE_H
#define MODULE_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace il
{

class Module : public core::Object
{
    AMANDA_OBJECT(Module, core::Object)

public:

    Module(const core::String& id);
    virtual ~Module();

    const core::String& getIdentifier() const;

protected:

    core::String identifier;
} ;

}
}

#endif /* MODULE_H */

