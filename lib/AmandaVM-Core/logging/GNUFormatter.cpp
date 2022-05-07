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
 * File:   GNUFormatter.cpp
 * Author: Javier Marrero
 * 
 * Created on April 2, 2022, 12:27 AM
 */

#include <amanda-vm/Logging/GNUFormatter.h>
#include <amanda-vm/Logging/Logger.h>

using namespace amanda;
using namespace amanda::logging;

GNUFormatter::GNUFormatter(const core::String& executableName, bool useAnsiEscapes)
:
executableName(executableName),
useAnsiEscapes(useAnsiEscapes)
{
}

core::String GNUFormatter::format(const LogRecord& record) const
{
    core::String buffer(executableName);
    buffer.append(": ").append(levelToString(record.getLevel())).append(": ");
    buffer.append(record.getMessage());

    return buffer;
}

core::String GNUFormatter::levelToString(int level) const
{
    core::String result;

    if (useAnsiEscapes)
    {
        if (level >= Logger::INFO)
        {
            result = "\033[37;1m";
        }
        else if (level == Logger::WARN)
        {
            result = "\033[33;1m";
        }
        else
        {
            result = "\033[31;1m";
        }
    }

    switch (level)
    {
        case Logger::TRACE:
            result.append("trace");
            break;
        case Logger::DEBUG:
            result.append("debug");
            break;
        case Logger::INFO:
            result.append("info");
            break;
        case Logger::WARN:
            result.append("warning");
            break;
        case Logger::ERROR:
            result.append("error");
            break;
        case Logger::FATAL:
            result.append("fatal error");
            break;
        default:
            result.append("?");
            break;
    }

    if (useAnsiEscapes)
    {
        result.append("\033[0m");
    }
    return result;
}




