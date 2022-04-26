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
 * File:   Handler.cpp
 * Author: Javier Marrero
 * 
 * Created on March 29, 2022, 11:24 PM
 */

#include <amanda-vm/Logging/Handler.h>
#include <amanda-vm/Logging/Logger.h>

using namespace amanda;
using namespace amanda::logging;

Handler::Handler(Filter* filter, Formatter* formatter)
:
filter(filter),
formatter(formatter),
level(Logger::ALL)
{
}

Handler::~Handler()
{
}

Filter* Handler::getFilter() const
{
    return filter;
}

Formatter* Handler::getFormatter() const
{
    return formatter;
}

int Handler::getLevel() const
{
    return level;
}

bool Handler::isLoggable(const LogRecord& record) const
{
    bool result = false;
    if (record.getLevel() <= level)
    {
        if (!filter.isNull())
        {
            result = filter->isLoggable(record);
        }
        else
        {
            result = true;
        }
    }
    return result;
}

void Handler::setFormatter(Formatter& formatter)
{
    this->formatter = &formatter;
}

void Handler::setLevel(const int level)
{
    this->level = level;
}
