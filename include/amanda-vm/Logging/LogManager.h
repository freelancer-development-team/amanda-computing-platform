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
 * File:   LogManager.h
 * Author: Javier Marrero
 *
 * Created on March 30, 2022, 1:36 AM
 */

#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Logging/Logger.h>

// C++ STL
#include <map>

namespace amanda
{
namespace logging
{

class LogManager : public core::Object
{

    AMANDA_OBJECT(LogManager, core::Object)
public:

    static LogManager& getLogManager();

    virtual bool    addLogger(Logger* logger);
    virtual Logger* getLogger(const core::String& name);

protected:

    LogManager();

private:

    /**
     * This structure orders the members of the map that keeps registered loggers.
     * It keeps the map in alphabetical order.
     * 
     * @param s1
     * @param s2
     * @return
     */
    struct LoggerComparator
    {
        bool operator()(const core::String& s1, const core::String& s2) const;
    } ;
    typedef std::map<core::String, Logger*, LoggerComparator> LoggerMap;

    static LogManager logManager;

    bool        initialized;
    LoggerMap   loggers;

    Logger* findAncestor(Logger* child) const;
    void    initializeLogManager();

} ;

}
}

#endif /* LOGMANAGER_H */

