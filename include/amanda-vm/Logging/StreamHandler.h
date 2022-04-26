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
 * File:   StreamHandler.h
 * Author: Javier Marrero
 *
 * Created on March 31, 2022, 1:19 PM
 */

#ifndef STREAMHANDLER_H
#define STREAMHANDLER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/OutputStream.h>
#include <amanda-vm/Logging/Handler.h>
#include <amanda-vm/Logging/Formatter.h>

namespace amanda
{
namespace logging
{

class StreamHandler : public Handler
{
    AMANDA_OBJECT(StreamHandler, Handler)
    
public:

    StreamHandler(io::OutputStream* stream, Formatter* formatter);
    virtual ~StreamHandler();

    virtual void close() const;
    virtual void flush() const;
    virtual bool isLoggable(const LogRecord& record) const;
    virtual void publish(const LogRecord& record) const;

protected:

    const io::OutputStream* getOutputStream() const;
    void                    setOutputStream(io::OutputStream* out);
    
private:

    enum
    {
        STATE_FRESH,
        STATE_PUBLISHED,
        STATE_CLOSED
    };

    mutable int                             streamState;
    core::StrongReference<io::OutputStream> outputStream;

    void changeWriter(io::OutputStream* outputStream);
} ;

}
}

#endif /* STREAMHANDLER_H */

