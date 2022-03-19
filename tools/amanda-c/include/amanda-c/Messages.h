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
 * File:   Messages.h
 * Author: Javier Marrero
 *
 * Created on March 10, 2022, 10:01 AM
 */

#ifndef AMANDA_C_MESSAGES_H
#define AMANDA_C_MESSAGES_H

#include <amanda-vm/String.h>

namespace amanda
{
namespace compiler
{
namespace log
{

void info(const core::String& fmt, ...);
void warning(const core::String& fmt, ...);
void error(const core::String& fmt, ...);
void fatal(const core::String& fmt, ...);

}
}
}

#endif /* MESSAGES_H */

