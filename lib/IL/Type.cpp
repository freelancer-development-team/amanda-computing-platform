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
 * File:   Type.cpp
 * Author: Javier Marrero
 * 
 * Created on March 12, 2022, 2:51 PM
 */

#include <amanda-vm/IL/Type.h>

using namespace amanda::il;

Type::~Type()
{
}

Type::TypeID Type::getTypeId() const
{
    return id;
}

bool Type::isFloatingPointType() const
{
    return getTypeId() == ID_FloatingPointType;
}

bool Type::isFunctionType() const
{
    return getTypeId() == ID_FunctionType;
}

bool Type::isIntegralType() const
{
    return getTypeId() == ID_IntegerType;
}

bool Type::isSized() const
{
    return getTypeId() != ID_VoidType;
}

bool Type::operator ==(const Type& object) const
{
    return id == object.id;
}

bool Type::operator ==(const Type* object) const
{
    assert(object != NULL && "Bad pointer");

    return id == object->id;
}

/* ==================== DERIVED CLASSES ==================== */



/* =========================== TYPE ========================================= */


