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
 * File:   AmbiguousOptionException.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 10:28 AM
 */

#ifndef AMBIGUOUSOPTIONEXCEPTION_H
#define AMBIGUOUSOPTIONEXCEPTION_H

#include <amanda-vm/Option/ParseException.h>

#include <list>

namespace amanda
{
namespace cli
{

/**
 * <code>AmbiguousOptionException</code> instances represents the parse error
 * found whenever multiples instances of the same long option does not satisfy
 * the criteria for matching.
 *
 * @author J. Marrero
 */
class AmbiguousOptionException : public ParseException
{
    AMANDA_OBJECT(AmbiguousOptionException, ParseException)
    
public:

    AmbiguousOptionException(const core::String& option, std::list<core::String> matchingOptions);
    virtual ~AmbiguousOptionException() throw();

    const std::list<core::String>& getMatchingOptions() const;

private:

    static core::String createMessage(const core::String& option, std::list<core::String> matchingOptions);

    std::list<core::String> matchingOptions;
} ;

}
}

#endif /* AMBIGUOUSOPTIONEXCEPTION_H */

