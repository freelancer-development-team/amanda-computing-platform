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
 * File:   ErrorManager.h
 * Author: Javier Marrero
 *
 * Created on March 31, 2022, 9:10 AM
 */

#ifndef ERRORMANAGER_H
#define ERRORMANAGER_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace logging
{

class ErrorManager : public core::Object
{
    AMANDA_OBJECT(ErrorManager, core::Object)
    
public:

    static const int GENERIC_FAILURE = 0;
    static const int WRITE_FAILURE = 1;
    static const int FLUSH_FAILURE = 2;
    static const int CLOSE_FAILURE = 3;
    static const int OPEN_FAILURE = 4;
    static const int FORMAT_FAILURE = 5;

    ErrorManager();
    virtual ~ErrorManager();

    void error(const core::String& message, core::Exception* ex, int errorCode) const;

private:

    volatile mutable bool everUsed;
} ;

}
}

#endif /* ERRORMANAGER_H */

