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
 * File:   SimpleFormatter.cpp
 * Author: Javier Marrero
 * 
 * Created on April 1, 2022, 7:04 PM
 */

#include <amanda-vm/Logging/SimpleFormatter.h>
#include <amanda-vm/Logging/Logger.h>

using namespace amanda;
using namespace amanda::logging;

SimpleFormatter::SimpleFormatter()
{
}

SimpleFormatter::~SimpleFormatter()
{
}

core::String SimpleFormatter::format(const LogRecord& record) const
{
    core::String buf(levelToString(record.getLevel()));
    buf.append(": ");
    buf.append(record.getMessage());

    return buf;
}

core::String SimpleFormatter::levelToString(int level) const
{
    core::String result;
    switch (level)
    {
        case Logger::L_TRACE:
            result = "TRACE";
            break;
        case Logger::L_DEBUG:
            result = "DEBUG";
            break;
        case Logger::L_FINEST:
            result.append("FINEST");
            break;
        case Logger::L_FINER:
            result.append("FINER");
            break;
        case Logger::L_FINE:
            result.append("FINE");
            break;
        case Logger::L_INFO:
            result = "INFO";
            break;
        case Logger::L_WARN:
            result = "WARN";
            break;
        case Logger::L_ERROR:
            result = "ERROR";
            break;
        case Logger::L_FATAL:
            result = "FATAL";
            break;
        default:
            result = "UNKNOWN";
            break;
    }
    return result;
}

