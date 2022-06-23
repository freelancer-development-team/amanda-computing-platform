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
 * File:   Thread.cpp
 * Author: Javier Marrero
 * 
 * Created on March 24, 2022, 11:38 PM
 */

#include <amanda-vm/Threading/Thread.h>
#include <amanda-vm/Threading/ThreadingException.h>

// POSIX Threads now added as a dependency
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#include <queue>

using namespace amanda;
using namespace amanda::concurrent;

#define PTHREAD_HANDLE(x)       ((pthread_t*)(x))
#define PTHREAD_ATTRIBUTE(x)    ((pthread_attr_t*) (x))
#define PTHREAD_ATTRIBUTE_NAME  "pthread-attribute"

static std::queue<core::Exception*>     exceptionQueue;
static std::deque<concurrent::Thread*>  actives;

static void internalThrow()
{
    AMANDA_SYNCHRONIZED(lock);
    {
        if (!exceptionQueue.empty())
        {
            core::Exception* ex = exceptionQueue.front();
            exceptionQueue.pop();

            assert(ex != NULL && "Null pointer dereference in exception handling.");
            throw *ex;
        }
    }
    AMANDA_DESYNCHRONIZED(lock);
}

void* internalRun(void* args)
{
    assert(args != NULL && "Bad pointer");
    Thread* thread = static_cast<Thread*> (args);

    try
    {
        thread->run();
    }
    catch (core::Exception& ex)
    {
        core::Exception* clone = (core::Exception*) ex.clone();
        AMANDA_SYNCHRONIZED(lock);
        {
            exceptionQueue.push(clone);
        }
        AMANDA_DESYNCHRONIZED(lock);
    }

    thread->setDead(true);
    return args;
}

void Thread::sleep(unsigned long milliseconds)
{
    usleep(milliseconds);
}

void Thread::wait(unsigned long long id)
{
    AMANDA_SYNCHRONIZED(lock);
    {
        int result = pthread_join((pthread_t) id, NULL);
        if (result != 0)
        {
            core::String cause = "unknown";
            switch (result)
            {
                case EDEADLK:
                    cause = "a deadlock was detected";
                    break;
                case EINVAL:
                    cause = "thread is not a joinable thread or another thread is waiting to join";
                    break;
                case ESRCH:
                    cause = "no thread with that ID could be found";
                    break;
            }
            throw ThreadingException("unable to join threads: " + cause);
        }
    }
    AMANDA_DESYNCHRONIZED(lock);
}

Thread::Thread()
:
dead(false),
nativeHandle(NULL),
id(0),
joinable(true),
running(false),
started(false)
{
    // Initialize common state
    initializeState();
}

Thread::Thread(Runnable & runnable)
:
dead(false),
nativeHandle(NULL),
id(0),
joinable(true),
running(false),
started(false)
{
    // Initialize common state
    initializeState();

    // Set the runnable
    this->runnable = &runnable;
}

Thread::~Thread()
{
    std::free(nativeHandle);

    // Free all the handles.
    for (std::map<const char*, void*>::iterator it = handles.begin(), end = handles.end();
         it != end; ++it)
    {
        if (it->second != NULL)
        {
            std::free(it->second);
            it->second = NULL;
        }
    }

    // Throw any exception
    internalThrow();
}

void Thread::exit()
{
    if (!started)
    {
        throw ThreadingException("Attempted to exit from a non-started thread.");
    }

    void* retval = NULL;
    pthread_exit(retval);
}

unsigned long long Thread::getThreadId() const
{
    return id;
}

bool Thread::hasRunnable() const
{
    return runnable.isNotNull();
}

void Thread::initializeState()
{
    nativeHandle = std::calloc(1, sizeof (pthread_t));
    if (!nativeHandle)
    {
        throw ThreadingException("Not enough memory.");
    }

    handles[PTHREAD_ATTRIBUTE_NAME] = std::calloc(1, sizeof (pthread_attr_t));

    /* Initialize the attributes. */
    pthread_attr_init(PTHREAD_ATTRIBUTE(handles[PTHREAD_ATTRIBUTE_NAME]));
}

bool Thread::isDead() const
{
    return dead;
}

bool Thread::isJoinable() const
{
    return joinable;
}

bool Thread::isRunning() const
{
    return running;
}

bool Thread::isStarted() const
{
    return started;
}

void Thread::join(unsigned long long id)
{
    if (!joinable || pthread_join((pthread_t) id, NULL) != 0)
    {
        throw ThreadingException("Unable to join thread (native threading API error).");
    }
    running = false;
}

void Thread::run()
{
    if (hasRunnable())
    {
        runnable->run();
    }
}

void Thread::setJoinable(bool joinable)
{
    if (started)
    {
        throw ThreadingException("Attempted to set 'joinable' attribute to already started thread");
    }

    PTHREAD_ATTRIBUTE(handles[PTHREAD_ATTRIBUTE_NAME])->p_state = joinable ? PTHREAD_CREATE_JOINABLE : PTHREAD_CREATE_DETACHED;
    this->joinable = joinable;
}

void Thread::setDead(bool dead)
{
    this->dead = dead;
    if (dead)
    {
        AMANDA_SYNCHRONIZED(lock);
        {
            for (unsigned i = 0; i < actives.size(); ++i)
            {
                if (actives.at(i) == this)
                {
                    actives.erase(actives.begin() + i);
                    release();
                }
            }
        }
        AMANDA_DESYNCHRONIZED(lock);
        exit();
    }
}

void Thread::start()
{
    int result = pthread_create(PTHREAD_HANDLE(nativeHandle), PTHREAD_ATTRIBUTE(handles[PTHREAD_ATTRIBUTE_NAME]), &internalRun, static_cast<void*> (this));
    if (result != 0)
    {
        core::String cause = "unknown error";
        switch (result)
        {
            case EAGAIN:
                cause = "insufficient resources to spawn thread";
                break;
            case EINVAL:
                cause = "invalid settings in attributes parameter";
                break;
            case EPERM:
                cause = "insufficient permissions.";
                break;
        }
        throw ThreadingException("Unable to create thread (native threading API error: " + cause + ").");
    }
    started = true;
    running = true;
    id = *PTHREAD_HANDLE(nativeHandle);

    // Add this to the list of active threads
    AMANDA_SYNCHRONIZED(lock);
    {
        grab();
        actives.push_back(this);
    }
    AMANDA_DESYNCHRONIZED(lock);
}





