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
 * File:   Logging.h
 * Author: Javier Marrero
 *
 * Created on April 16, 2022, 4:18 PM
 */

#ifndef _AMANDA_BINUTILS_LOGGING_H
#define _AMANDA_BINUTILS_LOGGING_H

#include <amanda-vm/Logging/Logger.h>
#include <amanda-vm/Logging/Formatter.h>

namespace amanda
{
namespace binutils
{

/**
 * This function sets the default logging formatter for the members of this
 * library. This function may be called every time you need to change the
 * formatter for the library (<i>i.e</i> in the assembler program, the output
 * is formatted according to the formatted output of the GNU guidelines).
 * For changing formatters of individual handlers you must gain access to the
 * corresponding <code>amanda::logging::Logger</code> object. This function
 * exists primarily for convenience.
 * 
 * @param formatter
 */
void setFormatterForPackage(const logging::Formatter& formatter);

/**
 * Returns a reference to the global library logging facility.
 * 
 * @return a <code>logging::Logger</code> reference.
 */
logging::Logger& getPackageLogger();

}
}

#endif /* LOGGING_H */

