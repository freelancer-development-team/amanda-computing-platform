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
 * File:   LogRecord.cpp
 * Author: Javier Marrero
 * 
 * Created on March 29, 2022, 11:37 PM
 */

#include <amanda-vm/Logging/LogRecord.h>
#include <cstdarg>

using namespace amanda;
using namespace amanda::logging;

unsigned long LogRecord::idGenerator = LONG_MIN;

LogRecord::LogRecord(int level, const core::String& message, va_list va, const core::String& logger)
:
level(level),
loggerName(logger),
message(message)
{
    seconds = time(NULL);
    sequenceNumber = allocateSequenceNumber();

    // Format the message arguments.
    this->message = core::String::makeFormattedStringWithArguments(message, va);
}

LogRecord::~LogRecord()
{
}

int LogRecord::getThreadId() const
{
    return threadId;
}

unsigned long LogRecord::getSequenceNumber() const
{
    return sequenceNumber;
}

time_t LogRecord::getSeconds() const
{
    return seconds;
}

const core::String& LogRecord::getMessage() const
{
    return message;
}

const core::String& LogRecord::getLoggerName() const
{
    return loggerName;
}

int LogRecord::getLevel() const
{
    return level;
}

unsigned long LogRecord::allocateSequenceNumber()
{
    return idGenerator++ % UINT_MAX;
}

void LogRecord::setLoggerName(const core::String& loggerName) const
{
    this->loggerName = loggerName;
}
