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
 * File:   Driver.cpp
 * Author: Javier Marrero
 * 
 * Created on March 10, 2022, 9:22 AM
 */

#include <amanda-c/Driver.h>

using namespace amanda::compiler;

Driver::Driver()
:
statistics(false),
verbose(false)
{
}

Driver::~Driver()
{
}

bool Driver::isShowStatistics() const
{
    return statistics;
}

bool Driver::isVerbose() const
{
    return verbose;
}

void Driver::setShowStatistics(bool show)
{
    this->statistics = show;
}

void Driver::setVerbose(bool verbose)
{
    this->verbose = verbose;
}
