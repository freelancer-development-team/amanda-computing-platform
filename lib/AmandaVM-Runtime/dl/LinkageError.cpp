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
 * File:   LinkageError.cpp
 * Author: Javier Marrero
 * 
 * Created on June 23, 2022, 2:17 AM
 */

#include <amanda-vm/Runtime/LinkageError.h>

using namespace amanda;
using namespace amanda::vm;

LinkageError::LinkageError(const core::String& message)
:
core::Exception(message)
{
}

LinkageError::~LinkageError() throw ()
{
}


