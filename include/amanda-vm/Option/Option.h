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
 * File:   Option.h
 * Author: Javier Marrero
 *
 * Created on February 26, 2022, 3:02 PM
 */

#ifndef OPTION_H
#define OPTION_H

#include <amanda-vm/Object.h>
#include <amanda-vm/String.h>

namespace amanda
{
namespace cli
{

core::String stripLeadingAndTrailingQuotes(const core::String& str);
core::String stripLeadingHyphens(const core::String& str);

class Option
{
public:
    
} ;

}
}

#endif /* OPTION_H */

