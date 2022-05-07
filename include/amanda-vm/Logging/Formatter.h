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
 * File:   Formatter.h
 * Author: Javier Marrero
 *
 * Created on March 30, 2022, 1:10 AM
 */

#ifndef FORMATTER_H
#define FORMATTER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Logging/LogRecord.h>

namespace amanda
{
namespace logging
{

class Formatter : public core::Object
{
    AMANDA_OBJECT(Formatter, core::Object)
public:

    virtual core::String format(const LogRecord& record) const = 0;
    virtual core::String getHead() const;
    virtual core::String getTail() const;

protected:

    Formatter();

    virtual core::String levelToString(int level) const = 0;
} ;

}
}

#endif /* FORMATTER_H */

