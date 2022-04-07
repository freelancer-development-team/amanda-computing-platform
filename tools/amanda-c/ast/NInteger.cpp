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
 * File:   NInteger.cpp
 * Author: Javier Marrero
 * 
 * Created on March 21, 2022, 1:55 AM
 */

#include <amanda-c/ast/NInteger.h>

using namespace amanda;
using namespace amanda::compiler::ast;

NInteger::NInteger(const core::String& literal)
:
literal(literal),
signedInteger(false)
{
    // Check if has sign
}

NInteger::~NInteger()
{
}

bool NInteger::isSigned() const
{
    return signedInteger;
}

