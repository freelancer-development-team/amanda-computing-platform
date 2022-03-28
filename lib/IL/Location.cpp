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
 * File:   Location.cpp
 * Author: Javier Marrero
 * 
 * Created on March 23, 2022, 2:04 AM
 */

#include <amanda-vm/IL/Location.h>

using namespace amanda;
using namespace amanda::il;

Location::Location(unsigned long long il, unsigned long long ic, unsigned long long fl, unsigned long long fc)
:
initialLine(il),
initialColumn(ic),
finalLine(fl),
finalColumn(fc)
{
}

Location::~Location()
{
}

unsigned long long Location::getFinalColumn() const
{
    return finalColumn;
}

unsigned long long Location::getFinalLine() const
{
    return finalLine;
}

unsigned long long Location::getInitialColumn() const
{
    return initialColumn;
}

unsigned long long Location::getInitialLine() const
{
    return initialLine;
}

void Location::setFinalColumn(unsigned long long finalColumn)
{
    this->finalColumn = finalColumn;
}

void Location::setFinalLine(unsigned long long finalLine)
{
    this->finalLine = finalLine;
}

void Location::setInitialColumn(unsigned long long initialColumn)
{
    this->initialColumn = initialColumn;
}

void Location::setInitialLine(unsigned long long initialLine)
{
    this->initialLine = initialLine;
}


