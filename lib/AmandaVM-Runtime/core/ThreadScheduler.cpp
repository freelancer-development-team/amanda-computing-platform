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
 * File:   ThreadScheduler.cpp
 * Author: Javier Marrero
 * 
 * Created on May 21, 2022, 11:58 PM
 */

#include <amanda-vm/Runtime/ThreadScheduler.h>
#include <amanda-vm/System.h>
#include <amanda-vm/Runtime/Context.h>

// C++
#include <cmath>

using namespace amanda;
using namespace amanda::vm;

ThreadScheduler::ThreadScheduler(const Context& context)
:
context(context),
maxThreads(std::pow(core::getNumberOfAvailableCores(), 2))
{
}

unsigned ThreadScheduler::getMaximunThreadCount() const
{
    return maxThreads;
}

void ThreadScheduler::setMaximumThreadCount(unsigned count)
{
    maxThreads = count;
}


