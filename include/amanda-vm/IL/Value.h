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
 * File:   Value.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 3:36 PM
 */

#ifndef VALUE_H
#define VALUE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IL/Type.h>

namespace amanda
{
namespace il
{

class Value : public core::Object
{
    AMANDA_OBJECT(Value, core::Object)

public:

    const core::String& getName() const;
    const Type*         getType() const;
    void                setName(const core::String& name);

protected:

    core::String                name;
    core::StrongReference<Type> type;
} ;

}
}

#endif /* VALUE_H */

