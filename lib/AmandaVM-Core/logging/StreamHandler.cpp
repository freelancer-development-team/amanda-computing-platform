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
 * File:   StreamHandler.cpp
 * Author: Javier Marrero
 * 
 * Created on March 31, 2022, 1:19 PM
 */

#include <amanda-vm/Logging/StreamHandler.h>
#include <amanda-vm/Logging/SimpleFormatter.h>

using namespace amanda;
using namespace amanda::logging;

StreamHandler::StreamHandler(io::OutputStream* stream, Formatter* formatter)
:
Handler(NULL, formatter),
outputStream(stream)
{
}

void StreamHandler::close() const
{
    flush();

    if (!outputStream.isNull())
    {
        if (!formatter.isNull())
        {
            if (streamState == STATE_FRESH)
            {
                outputStream->write(formatter->getHead().toCharArray());
            }
            if (streamState == STATE_CLOSED)
            {
                outputStream->write(formatter->getTail().toCharArray());
            }
        }
        streamState = STATE_CLOSED;
        outputStream->close();
    }
}

void StreamHandler::flush() const
{
    ///TODO: Make error handling secure
    if (!outputStream.isNull())
    {
        outputStream->flush();
    }
}

bool StreamHandler::isLoggable(const LogRecord& record) const
{
    return (!outputStream.isNull()) && super::isLoggable(record);
}

void StreamHandler::publish(const LogRecord& record) const
{
    assert(!formatter.isNull() && "Null pointer exception");
    core::String formattedMessage;

    if (isLoggable(record))
    {
        if (streamState == STATE_FRESH)
        {
            if (formatter->getHead() != core::String::EMPTY)
                outputStream->write(formatter->getHead().append('\n').toCharArray());
            streamState = STATE_PUBLISHED;
        }

        ///TODO: Add try-catch
        formattedMessage = formatter->format(record).append('\n');

        ///TODO: Add try-catch
        outputStream->write(formattedMessage.toCharArray());
    }
}

void StreamHandler::setOutputStream(io::OutputStream* out)
{
    changeWriter(out);
}

void StreamHandler::changeWriter(io::OutputStream* outputStream)
{
    if ((streamState != STATE_FRESH) || !(this->outputStream.isNull()))
    {
        close();
    }

    this->outputStream = outputStream;
    streamState = STATE_FRESH;
}
