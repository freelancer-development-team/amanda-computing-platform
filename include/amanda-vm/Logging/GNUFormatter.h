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
 * File:   GNUFormatter.h
 * Author: Javier Marrero
 *
 * Created on April 2, 2022, 12:27 AM
 */

#ifndef GNUFORMATTER_H
#define GNUFORMATTER_H

#include <amanda-vm/Logging/Formatter.h>

namespace amanda
{
namespace logging
{

/**
 * The GNU Formatter class formats log messages according to what is specified
 * in the GNU coding standards for C/C++. It produces output messages similar
 * to those provided by GNU GCC or GNU Make.
 *
 * @author J. Marrero
 */
class GNUFormatter : public Formatter
{
    AMANDA_OBJECT(GNUFormatter, Formatter)
public:

    GNUFormatter(const core::String& executableName, bool useAnsiEscapes = false);
    
    virtual core::String format(const LogRecord& record) const;

protected:

    core::String    executableName;
    bool            useAnsiEscapes;
    
    virtual core::String levelToString(int level) const;
} ;

}
}

#endif /* GNUFORMATTER_H */

