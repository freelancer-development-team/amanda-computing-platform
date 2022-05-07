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
 * File:   ErrorManager.cpp
 * Author: Javier Marrero
 * 
 * Created on March 31, 2022, 9:10 AM
 */

#include <amanda-vm/Logging/ErrorManager.h>
#include <amanda-vm/IO/Console.h>

using namespace amanda;
using namespace amanda::logging;

ErrorManager::ErrorManager()
{
}

ErrorManager::~ErrorManager()
{
}

void ErrorManager::error(const core::String& message, core::Exception* ex, int errorCode) const
{
    if (!everUsed)
    {
        AMANDA_SYNCHRONIZED(lock);
        {
            if (everUsed)
                return;

            everUsed = true;
        }
        AMANDA_DESYNCHRONIZED(lock);

        core::String codeMsg;
        switch (errorCode)
        {
            case GENERIC_FAILURE:
                codeMsg = "GENERIC_FAILURE";
                break;
            case WRITE_FAILURE:
                codeMsg = "WRITE_FAILURE";
                break;
            case FLUSH_FAILURE:
                codeMsg = "FLUSH_FAILURE";
                break;
            case CLOSE_FAILURE:
                codeMsg = "CLOSE_FAILURE";
                break;
            case OPEN_FAILURE:
                codeMsg = "OPEN_FAILURE";
                break;
            case FORMAT_FAILURE:
                codeMsg = "FORMAT_FAILURE";
                break;
            default:
                codeMsg = "UNKNOWN_FAILURE";
                break;
        }

        io::console().err.println("Error upon logging: " + codeMsg);
        if (message != core::String::EMPTY)
        {
            io::console().err.println(message);
        }

        if (ex != NULL)
        {
            io::console().err.println(ex->toString());
        }
    }
}



