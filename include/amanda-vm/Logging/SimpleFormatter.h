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
 * File:   SimpleFormatter.h
 * Author: Javier Marrero
 *
 * Created on April 1, 2022, 7:04 PM
 */

#ifndef SIMPLEFORMATTER_H
#define SIMPLEFORMATTER_H

#include <amanda-vm/Logging/Formatter.h>

namespace amanda
{
namespace logging
{

class SimpleFormatter : public Formatter
{
    AMANDA_OBJECT(SimpleFormatter, Formatter)
public:

    SimpleFormatter();
    virtual ~SimpleFormatter();

    virtual core::String format(const LogRecord& record) const;

protected:

    virtual core::String levelToString(int level) const;

} ;

}
}

#endif /* SIMPLEFORMATTER_H */

