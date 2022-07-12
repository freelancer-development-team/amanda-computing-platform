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
 * File:   Logger.h
 * Author: Javier Marrero
 *
 * Created on March 29, 2022, 10:56 AM
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Logging/Filter.h>
#include <amanda-vm/Logging/Handler.h>

// C++
#include <cstdarg>
#include <climits>
#include <deque>

namespace amanda
{
namespace logging
{

class Handler;

/**
 * Objects of this class constitutes the logging interface of the Amanda project.
 * This logging API is designed to be configurable and simple, while keeping a
 * set of powerful abstractions to support any logging needs a user may have.
 *
 * @author J. Marrero
 */
class Logger : public core::Object
{

    AMANDA_OBJECT(Logger, core::Object)

public:

    /**
     * This is a enumerated list of logging levels.
     */
    typedef enum Level
    {
        L_NONE = INT_MIN,
        L_OFF = INT_MIN + 1,
        L_FATAL = -1000,
        L_ERROR = -500,
        L_WARN = -250,
        L_INFO = 0,
        L_FINE = 25,
        L_FINER = 100,
        L_FINEST = 200,
        L_DEBUG = 250,
        L_TRACE = 500,
        L_ALL = INT_MAX
    } Level;

    static Logger root;
    static Logger global;

    static Logger*      getLogger(const core::String& name);

    /// The virtual destructor must be public
    virtual ~Logger();

    void                        addHandler(Handler& handler);
    void                        debug(const core::String& fmt, ...) const;
    void                        error(const core::String& fmt, ...) const;
    void                        fine(const core::String& fmt, ...) const;
    void                        finer(const core::String& fmt, ...) const;
    void                        finest(const core::String& fmt, ...) const;
    void                        fatal(const core::String& fmt, ...) const;
    const std::deque<Handler*>& getHandlers() const;
    int                         getLevel() const;
    const core::String&         getName() const;
    Logger*                     getParent() const;
    bool                        getUseParentHandlers() const;
    void                        info(const core::String& fmt, ...) const;
    bool                        isLoggable(int level) const;
    void                        log(const LogRecord& record) const;
    void                        log(Level level, const core::String& fmt, ...) const;
    void                        setFilter(Filter* filter);
    void                        setLevel(int level);
    void                        setParent(Logger& parent);
    void                        setUseParentHandlers(bool useParentHandlers);
    void                        trace(const core::String& fmt, ...) const;
    void                        warn(const core::String& fmt, ...) const;

protected:

    Logger(const core::String& name);

    void                        logp(int level, const core::String& fmt, va_list& va) const;

private:

    Filter*                 filter;
    std::deque<Handler*>    handlerList;
    int                     level;
    core::String            name;
    Logger*                 parent;
    bool                    useParentHandlers;

} ;

}
}

#endif /* LOGGER_H */

