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
 * File:   ParseException.h
 * Author: Javier Marrero
 *
 * Created on March 2, 2022, 12:56 PM
 */

#ifndef PARSEEXCEPTION_H
#define PARSEEXCEPTION_H

#include <amanda-vm/Exception.h>

namespace amanda
{
namespace cli
{

class ParseException : public core::Exception
{
    AMANDA_OBJECT(ParseException, core::Exception)

public:

    ParseException(const core::String& message);
    virtual ~ParseException() throw();
    
} ;

}
}

#endif /* PARSEEXCEPTION_H */

