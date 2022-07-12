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
 * File:   LogManager.cpp
 * Author: Javier Marrero
 * 
 * Created on March 30, 2022, 1:36 AM
 */

#include <amanda-vm/Logging/LogManager.h>
#include <amanda-vm/Logging/ConsoleHandler.h>
#include <amanda-vm/Logging/SimpleFormatter.h>

#include <utility>

using namespace amanda;
using namespace amanda::logging;

LogManager LogManager::logManager;

LogManager& LogManager::getLogManager()
{
    AMANDA_SYNCHRONIZED(lock);
    {
        if (!logManager.initialized)
            logManager.initializeLogManager();
    }
    AMANDA_DESYNCHRONIZED(lock);
    return logManager;
}

LogManager::LogManager()
:
initialized(false)
{
}

LogManager::~LogManager()
{
    for (LoggerMap::const_iterator it = loggers.begin(), end = loggers.end();
         it != end; ++it)
    {
        it->second->release();
    }
}

bool LogManager::addLogger(Logger* logger)
{
    bool result = false;

    // Synchronize here!
    AMANDA_SYNCHRONIZED(lock);

    if (logger)
    {
        // Own a reference to the logger!
        logger->grab();

        core::String name(logger->getName());
        Logger* parent = findAncestor(logger);
        loggers.insert(std::make_pair(name, logger));

        if (parent != logger->getParent())
        {
            logger->setParent(*parent);
        }

        /* Add some default properties. */
        logger->setLevel(parent->getLevel());

        for (LoggerMap::iterator iter = loggers.begin(); iter != loggers.end(); ++iter)
        {
            Logger* possibleChild = iter->second;
            if (possibleChild == NULL || possibleChild == logger || possibleChild->getParent() != parent)
            {
                continue;
            }
            if (!possibleChild->getName().startsWith(name))
            {
                continue;
            }
            if (possibleChild->getName().charAt(name.length()) != '.')
            {
                continue;
            }

            possibleChild->setParent(*logger);
        }
        result = true;
    }

    AMANDA_DESYNCHRONIZED(lock);
    return result;
}

Logger* LogManager::findAncestor(Logger* child) const
{
    assert(child != NULL && "Null pointer exception");
    AMANDA_SYNCHRONIZED(lock);

    const core::String& childName = child->getName();
    unsigned childNameLength = childName.length();

    Logger* best = (Logger*) & Logger::root;    ///TODO: Complete this
    unsigned bestNameLength = 0;

    Logger* cand = NULL;
    unsigned candNameLength = 0;

    if (child == &Logger::root)
        return NULL;

    for (LoggerMap::const_iterator it = loggers.begin(), end = loggers.end(); it != end; ++it)
    {
        const core::String& candName = it->first;
        candNameLength = candName.length();

        if (candNameLength > bestNameLength
            && childNameLength > candNameLength
            && childName.startsWith(candName)
            && childName.charAt(candNameLength) == '.')
        {
            try
            {
                cand = loggers.at(candName);
            }
            catch (std::out_of_range& ex)
            {
                cand = NULL;
            }

            if ((cand != NULL) || (cand == child))
            {
                continue;
            }

            bestNameLength = candNameLength;
            best = cand;
        }
    }

    AMANDA_DESYNCHRONIZED(lock);
    return best;
}

Logger* LogManager::getLogger(const core::String& name) const
{
    Logger* result = NULL;
    AMANDA_SYNCHRONIZED(lock);
    {
        try
        {
            result = loggers.at(name);
        }
        catch (std::out_of_range& ex)
        {
            result = NULL;
        }
    }
    AMANDA_DESYNCHRONIZED(lock);

    return result;
}

bool LogManager::LoggerComparator::operator ()(const core::String& s1, const core::String& s2) const
{
    return s1.compare(s1) < 0;
}

void LogManager::initializeLogManager()
{
    /* Set the default level for the root logger. */
    Logger::root.setLevel(Logger::L_ALL);
    Logger::global.setLevel(Logger::L_ALL);

    /* Initialize the default console handler. */
    Handler* consoleHandler = new ConsoleHandler();

    /* Add the handlers to the root logger. */
    Logger::root.addHandler(*consoleHandler);
    Logger::global.addHandler(*consoleHandler);
}
