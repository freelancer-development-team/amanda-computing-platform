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
 * File:   LinkError.cpp
 * Author: Javier Marrero
 * 
 * Created on April 28, 2022, 12:18 AM
 */

#include <amanda-vm/Binutils/LinkException.h>

using namespace amanda;
using namespace amanda::binutils;

LinkException::LinkException(const core::String& message, const Symbol& symbol)
:
core::Exception(message),
module(symbol.getModule()),
section(symbol.getSection()),
symbol(symbol)
{
    // Grab some data for message formatting
    core::String sectionName = (section == NULL) ? "unknown" : section->getName();

    // Append the message
    this->message.append(core::String::makeFormattedString("<%s> (%s)",
                                                           sectionName.toCharArray(),
                                                           symbol.getName().toCharArray()));
}

LinkException::~LinkException() throw ()
{
}

const Symbol& LinkException::getSymbol() const
{
    return symbol;
}

////////////////////////////////////////////////////////////////////////////////

UndefinedSymbolError::UndefinedSymbolError(const core::String& sectionName, const core::String& symbolName)
:
core::Exception("undefined symbol @ section <" + sectionName + "> (" + symbolName + ")"),
sectionName(sectionName),
symbolName(symbolName)
{
}

UndefinedSymbolError::~UndefinedSymbolError() throw ()
{
}

const core::String& UndefinedSymbolError::getSectionName() const
{
    return sectionName;
}

const core::String& UndefinedSymbolError::getSymbolName() const
{
    return symbolName;
}

