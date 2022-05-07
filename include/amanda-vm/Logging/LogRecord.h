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
 * File:   LogRecord.h
 * Author: Javier Marrero
 *
 * Created on March 29, 2022, 11:37 PM
 */

#ifndef LOGRECORD_H
#define LOGRECORD_H

#include <amanda-vm/TypeSystem.h>

// Time API
#include <ctime>
#include <cstdarg>

namespace amanda
{
namespace logging
{

/**
 * <code>LogRecord</code> instances holds state information for a particular
 * logging event.
 */
class LogRecord : public core::Object
{
    AMANDA_OBJECT(LogRecord, core::Object)
public:

    LogRecord(int level, const core::String& message, va_list va, const core::String& logger = core::String::EMPTY);
    virtual ~LogRecord();
    
    int                 getThreadId() const ;
    unsigned long       getSequenceNumber() const ;
    time_t              getSeconds() const ;
    const core::String& getMessage() const ;
    const core::String& getLoggerName() const ;
    int                 getLevel() const ;
    void                setLoggerName(const core::String& loggerName) const;

private:

    static unsigned long     idGenerator;

    mutable int             level;
    mutable core::String    loggerName;
    mutable core::String    message;
    time_t                  seconds;
    unsigned long           sequenceNumber;
    mutable int             threadId;

    unsigned long   allocateSequenceNumber();
} ;

}
}

#endif /* LOGRECORD_H */

