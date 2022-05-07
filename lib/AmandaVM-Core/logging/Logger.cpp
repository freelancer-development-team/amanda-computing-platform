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
 * File:   Logger.cpp
 * Author: Javier Marrero
 * 
 * Created on March 29, 2022, 10:56 AM
 */

#include <amanda-vm/Logging/Logger.h>
#include <amanda-vm/Logging/LogManager.h>
#include <amanda-vm/Logging/Handler.h>
#include <amanda-vm/ADT/Collections.h>

using namespace amanda;
using namespace amanda::logging;

Logger Logger::global("global");
Logger Logger::root(amanda::core::String::EMPTY);

Logger* Logger::getLogger(const core::String& name)
{
    LogManager& lm = LogManager::getLogManager();
    Logger* result = NULL;

    AMANDA_SYNCHRONIZED(lock);
    {
        result = lm.getLogger(name);
        if (result == NULL)
        {
            bool couldBeAdded = false;

            result = new Logger(name);
            couldBeAdded = lm.addLogger(result);
            
            assert(couldBeAdded == true && "Couldn't add logger to the logging manager!");
        }
    }
    AMANDA_DESYNCHRONIZED(lock);
    return result;
}

#define DECLARE_SHORTCUT(name, l) \
    void Logger::name(const core::String& fmt, ...) const \
    { \
        va_list va; \
        va_start(va, fmt); \
        logp(l, fmt, va); \
        va_end(va); \
    }

#define DECLARE_SHORTCUTS \
    DECLARE_SHORTCUT(debug, DEBUG) \
    DECLARE_SHORTCUT(error, ERROR) \
    DECLARE_SHORTCUT(fatal, FATAL) \
    DECLARE_SHORTCUT(info, INFO) \
    DECLARE_SHORTCUT(trace, TRACE) \
    DECLARE_SHORTCUT(warn, WARN)

// Declare

DECLARE_SHORTCUTS

Logger::Logger(const core::String& name)
:
filter(NULL),
name(name)
{
    level = NONE;
    parent = (this == &root) ? NULL : amanda::eliminateConstness(&root);
    useParentHandlers = (parent != NULL);
}

Logger::~Logger()
{
    if (filter)
        filter->release();

    for (std::deque<Handler*>::iterator it = handlerList.begin(), end = handlerList.end();
         it != end; ++it)
    {
        if (*it)
            (*it)->release();
    }
}

void Logger::addHandler(Handler& handler)
{
    AMANDA_SYNCHRONIZED(lock);
    {
        if (!adt::contains(handlerList, &handler))
        {
            handler.grab();
            handlerList.push_back(&handler);
        }
    }
    AMANDA_DESYNCHRONIZED(lock);
}

const std::deque<Handler*>& Logger::getHandlers()
{
    return handlerList;
}

int Logger::getLevel() const
{
    return level;
}

const core::String& Logger::getName() const
{
    return name;
}

Logger* Logger::getParent() const
{
    return parent;
}

bool Logger::getUseParentHandlers() const
{
    return useParentHandlers;
}

bool Logger::isLoggable(int level) const
{
    AMANDA_SYNCHRONIZED(lock);
    {
        if (level != NONE)
        {
            return this->level >= level;
        }
        else
        {
            if (parent != NULL)
            {
                return parent->isLoggable(level);
            }
            else
            {
                return false;
            }
        }
    }
    AMANDA_DESYNCHRONIZED(lock);

    return false;
}

void Logger::log(Level level, const core::String& fmt, ...) const
{
    va_list va;
    va_start(va, fmt);

    logp(level, fmt, va);

    va_end(va);
}

void Logger::log(const LogRecord& record) const
{
    AMANDA_SYNCHRONIZED(lock);
    {
        if (isLoggable(record.getLevel()) && (filter != NULL ? filter->isLoggable(record) : true))
        {
            if (record.getLoggerName() == core::String::EMPTY)
            {
                record.setLoggerName(name);
            }

            AMANDA_SYNCHRONIZED(lm);
            {
                const Logger* currentLogger = this;

                do
                {
                    for (unsigned i = 0; i < currentLogger->handlerList.size(); ++i)
                    {
                        currentLogger->handlerList.at(i)->publish(record);
                    }

                    if (currentLogger->useParentHandlers == false)
                    {
                        break;
                    }

                    currentLogger = currentLogger->getParent();
                }
                while (currentLogger != NULL);
            }
            AMANDA_DESYNCHRONIZED(lm);
        }
    }
    AMANDA_DESYNCHRONIZED(lock);
}

void Logger::setFilter(Filter* filter)
{
    filter->grab();
    this->filter = filter;
}

void Logger::setLevel(int level)
{
    this->level = level;
}

void Logger::setParent(Logger& parent)
{
    this->parent = &parent;
}

void Logger::setUseParentHandlers(bool useParentHandlers)
{
    this->useParentHandlers = useParentHandlers;
}

void Logger::logp(int level, const core::String& fmt, va_list va) const
{
    LogRecord record(level, fmt, va, getName());
    log(record);
}
