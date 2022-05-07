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
 * File:   Thread.h
 * Author: Javier Marrero
 *
 * Created on March 24, 2022, 11:38 PM
 */

#ifndef THREAD_H
#define THREAD_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Threading/Runnable.h>

#include <map>

namespace amanda
{
namespace concurrent
{

class Thread : public Runnable
{
    AMANDA_OBJECT(Thread, Runnable)
    
public:

    /**
     * Enumerates all the possible thread priorities.
     */
    typedef enum ThreadPriority
    {
        TP_Idle
    } ThreadPriority;

    Thread();
    virtual ~Thread();

    void            exit();
    bool            isJoinable() const;
    bool            isRunning() const;
    bool            isStarted() const;
    virtual void    join();
    void            setJoinable(bool joinable);
    virtual void    start();

private:

    void*                           nativeHandle;
    std::map<const char*, void*>    handles;
    volatile unsigned long long     id;
    volatile bool                   joinable;
    volatile bool                   running;
    volatile bool                   started;
    
} ;

}
}

#endif /* THREAD_H */

