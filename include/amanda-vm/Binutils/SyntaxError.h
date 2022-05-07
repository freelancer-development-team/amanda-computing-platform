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
 * File:   SyntaxError.h
 * Author: Javier Marrero
 *
 * Created on April 12, 2022, 1:55 AM
 */

#ifndef SYNTAXERROR_H
#define SYNTAXERROR_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/Locations.h>

namespace amanda
{
namespace binutils
{

/**
 * This class is used by the assembler parser every time a syntax error is
 * detected in the assembler's source code. It may be thrown also by other
 * components on this library. It is a general implementation that allows
 * many possible specializations.
 * <p>
 * The parser actually does not catch this exception completely, but re-throws
 * it and allows it to propagate until higher instance code catches the
 * exception or the program exits.
 *
 * @author J. Marrero
 */
class SyntaxError : public core::Exception
{
    AMANDA_OBJECT(SyntaxError, core::Exception)
public:

    SyntaxError(const location_t& location, const core::String& message = "unexpected syntax error.");
    virtual ~SyntaxError() throw ();

    const location_t&   getLocation() const;

private:

    const location_t    location;
    const core::String  message;
} ;

}
}

#endif /* SYNTAXERROR_H */

