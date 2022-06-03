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

using namespace amanda;
using namespace amanda::concurrent;

#define PTHREAD_HANDLE(x)       ((pthread_t*)(x))
#define PTHREAD_ATTRIBUTE(x)    ((pthread_attr_t*) (x))
#define PTHREAD_ATTRIBUTE_NAME  "pthread-attribute"

/**
 * This block must be declared as extern C.
 */
extern "C"
{

static void* internalRun(void* args)
{
    assert(args != NULL && "Bad pointer");
    Thread* thread = reinterpret_cast<Thread*> (args);
    thread->run();

    return args;
}

}

Thread::Thread()
:
started(false)
{
    // Initialize common state
    initializeState();
}

Thread::Thread(Runnable& runnable)
:
started(false)
{
    // Initialize common state
    initializeState();

    // Set the runnable
    this->runnable = &runnable;
}

Thread::~Thread()
{
    free(nativeHandle);

    // Free all the handles.
    for (std::map<const char*, void*>::iterator it = handles.begin(), end = handles.end();
         it != end; ++it)
    {
        if (it->second != NULL)
        {
            free(it->second);
            it->second = NULL;
        }
    }
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

bool Thread::hasRunnable() const
{
    return runnable.isNotNull();
}

void Thread::initializeState()
{
    nativeHandle = malloc(sizeof (pthread_t));
    if (!nativeHandle)
    {
        throw ThreadingException("Not enough memory.");
    }

    handles[PTHREAD_ATTRIBUTE_NAME] = malloc(sizeof (pthread_attr_t));

    /* Initialize the attributes. */
    pthread_attr_init(PTHREAD_ATTRIBUTE(handles[PTHREAD_ATTRIBUTE_NAME]));
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

void Thread::join()
{
    if (!joinable || pthread_join(*(PTHREAD_HANDLE(nativeHandle)), NULL) != 0)
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

void Thread::start()
{
    id = pthread_create(PTHREAD_HANDLE(nativeHandle), PTHREAD_ATTRIBUTE(handles[PTHREAD_ATTRIBUTE_NAME]), &internalRun, this);
    if (id != 0)
    {
        throw ThreadingException("Unable to create thread (native threading API error).");
    }
    started = true;
    running = true;
}





