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
 * File:   ConsoleHandler.h
 * Author: Javier Marrero
 *
 * Created on April 1, 2022, 1:33 AM
 */

#ifndef CONSOLEHANDLER_H
#define CONSOLEHANDLER_H

#include <amanda-vm/Logging/StreamHandler.h>
#include <amanda-vm/Logging/SimpleFormatter.h>

namespace amanda
{
namespace logging
{

class ConsoleHandler : public StreamHandler
{
    AMANDA_OBJECT(ConsoleHandler, StreamHandler)
public:

    ConsoleHandler(Formatter* formatter = new SimpleFormatter());
    virtual ~ConsoleHandler();
    
    virtual void close() const;
    virtual void publish(const LogRecord& record) const;
    
} ;

}
}

#endif /* CONSOLEHANDLER_H */

