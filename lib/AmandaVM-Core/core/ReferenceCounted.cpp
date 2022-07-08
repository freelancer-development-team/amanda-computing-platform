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
 * File:   ReferenceCounted.cpp
 * Author: Javier Marrero
 * 
 * Created on February 13, 2022, 2:34 PM
 */

#include <amanda-vm/ReferenceCounted.h>
#include <amanda-vm/Threading/Synchronization.h>

#include <assert.h>
#include <stdint.h>
#include <cstdlib>
#include <cstdio>
#include <float.h>

/* =========================== CONCURRENCY API ============================== */
/*
 * This is a private concurrent API for the use by the reference counting
 * mechanism. It provide concurrent primitives for access to the different
 * variables regulating heap allocations (needed by smart pointers and reference
 * counting strategies).
 *
 * Written by J. Marrero
 */

// SDK configuration & API
#include <amanda-vm-c/sdk-configuration.h>

// C/C++
#include <cstdlib>

// Windows API
#if defined(_W32)
#    include <windows.h>
#endif

// If using pthreads already, why just not use it here?
#if SDK_BUILD_USING_PTHREADS == SDK_BUILD_USE_FLAG
#    define PTHREAD_SPINLOCKS 1
#    include <unistd.h>
#    include <pthread.h>
#endif

namespace amanda
{
namespace core
{

// Obscure data type for spin-locks
#if PTHREAD_SPINLOCKS

#    define SPINLOCK_INITIALIZER    PTHREAD_SPINLOCK_INITIALIZER
typedef pthread_spinlock_t      spinlock_t;

#endif

int spinlock_init(spinlock_t* spinlock)
{
    int result = 0;
#if PTHREAD_SPINLOCKS
    result = pthread_spin_init(spinlock, PTHREAD_PROCESS_PRIVATE);
    assert(result != ENOMEM && "Out of memory inside critical section.");

#endif
    return result;
}

int spinlock_free(spinlock_t* spinlock)
{
    int result = 0;
#if PTHREAD_SPINLOCKS
    assert(spinlock != NULL && "Null pointer exception");
    result = pthread_spin_destroy(spinlock);

#endif
    return result;
}

int spinlock_lock(spinlock_t* spinlock)
{
    int result = 0;
#if PTHREAD_SPINLOCKS
    result = pthread_spin_lock(spinlock);

#endif
    return result;
}

int spinlock_unlock(spinlock_t* spinlock)
{
    int result = 0;
#if PTHREAD_SPINLOCKS
    result = pthread_spin_unlock(spinlock);

#endif
    return result;
}

#define SPINLOCK_BEGIN(name) \
    { \
        amanda::core::spinlock_t name = SPINLOCK_INITIALIZER; \
        amanda::core::spinlock_init(&name); \
        amanda::core::spinlock_lock(&name)

#define SPINLOCK_END(name) \
        amanda::core::spinlock_unlock(&name); \
        amanda::core::spinlock_free(&name); \
    } do {} while (0)

}
}

/* ========================================================================== */
// ========================== HEAP ALLOCATION TRACKER =======================

static bool lastAllocationOnHeap = false;

static inline bool isLastAllocationOnHeap()
{
    bool result;
    SPINLOCK_BEGIN(lock);
    {
        result = lastAllocationOnHeap;
    }
    SPINLOCK_END(lock);

    return result;
}

static inline void setLastAllocationOnHeap(bool allocated)
{
    SPINLOCK_BEGIN(lock);
    {
        lastAllocationOnHeap = allocated;
    }
    SPINLOCK_END(lock);
}

// ==========================================================================

using namespace amanda;
using namespace amanda::core;

ReferenceCounted::ReferenceCounted()
:
heapAllocated(isLastAllocationOnHeap()),
strongReferenceCount(0),
weakReferenceCount(0)
{
}

ReferenceCounted::~ReferenceCounted()
{
}

long long ReferenceCounted::getReferenceCount() const
{
    return strongReferenceCount;
}

long long ReferenceCounted::getWeakReferenceCount() const
{
    return weakReferenceCount;
}

size_t ReferenceCounted::getClassSize() const
{
    return sizeof (*this);
}

void ReferenceCounted::grab() const
{
    if (isHeapAllocated())
    {
        ++strongReferenceCount;
    }
}

void ReferenceCounted::grabWeakReference() const
{
    if (isHeapAllocated())
    {
        ++weakReferenceCount;
    }
}

bool ReferenceCounted::isHeapAllocated() const
{
    return heapAllocated;
}

void ReferenceCounted::release() const
{
    if (isHeapAllocated())
    {
        assert(strongReferenceCount >= 0);
        if (--strongReferenceCount <= 0)
        {
            delete this;
        }
    }
}

void ReferenceCounted::releaseWeakReference() const
{
    if (isHeapAllocated())
    {
        assert(weakReferenceCount >= 0);
        if (--weakReferenceCount <= 0)
        {
            if (strongReferenceCount == 0)
            {
                delete this;
            }
        }
    }
}

void ReferenceCounted::operator delete(void* pointer)
{
    // Delete the object
    ::operator delete(pointer);
}


void* ReferenceCounted::operator new(size_t size) {
   // Allocate & set properties
   void* result = ::operator new(size);

   // Set the allocation flag
   setLastAllocationOnHeap(true);

   // Return the resulting object
   return result;
}
