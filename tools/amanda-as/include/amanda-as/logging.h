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
 * File:   logging.h
 * Author: Javier Marrero
 *
 * Created on March 27, 2022, 3:50 PM
 */

#ifndef LOGGING_H
#define LOGGING_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace as
{
namespace logger
{

void info(const core::String& fmt, ...);
void warning(const core::String& fmt, ...);
void error(const core::String& fmt, ...);
void fatal(const core::String& fmt, ...);

}
}
}

#endif /* LOGGING_H */

