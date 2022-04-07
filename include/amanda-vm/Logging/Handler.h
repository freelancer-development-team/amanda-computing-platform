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
 * File:   Handler.h
 * Author: Javier Marrero
 *
 * Created on March 29, 2022, 11:24 PM
 */

#ifndef LOGGING_HANDLER_H
#define LOGGING_HANDLER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Logging/Formatter.h>
#include <amanda-vm/Logging/Filter.h>
#include <amanda-vm/Logging/LogRecord.h>

namespace amanda
{
namespace logging
{

/**
 * Logging handlers allow to redirect the output to several format including but
 * not limited to files in the file system, network, serial devices, console,
 * etc. Each logger instance inherits or gets a series of handlers. Handlers
 * can be individually deactivated or added to any logger. Two instances of the
 * same handler class may refer to different resources so we do not impose any
 * restriction when adding or deleting loggers.
 *
 * The management of the logging resources is left to the inheriting classes but
 * we recommend the use of the RAII pattern. Classes inside the framework
 * guarantees exception safety and resource deallocation once the destructor get
 * called.
 */
class Handler : public core::Object
{
    AMANDA_OBJECT(Handler, core::Object)
    
public:

    virtual void    close() const = 0;
    virtual void    flush() const = 0;
    Filter*         getFilter() const;
    Formatter*      getFormatter() const;
    int             getLevel() const;
    bool            isLoggable(const LogRecord& record) const;
    virtual void    publish(const LogRecord& record) const = 0;
    void            setFormatter(Formatter& formatter);
    void            setLevel(const int level);

protected:

    core::StrongReference<Filter>       filter;
    core::StrongReference<Formatter>    formatter;
    int                                 level;

    Handler(Filter* filter, Formatter* formatter);
} ;

}
}

#endif /* HANDLER_H */

