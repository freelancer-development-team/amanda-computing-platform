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
 * File:   LinkError.h
 * Author: Javier Marrero
 *
 * Created on April 28, 2022, 12:18 AM
 */

#ifndef LINKERROR_H
#define LINKERROR_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/Module.h>
#include <amanda-vm/Binutils/Section.h>
#include <amanda-vm/Binutils/Symbol.h>

namespace amanda
{
namespace binutils
{

/**
 * <code>LinkException</code> are exceptions thrown every time we encounter
 * an unresolved symbol or another (perhaps more explicit) linker error. These
 * exceptions receive a <code>Symbol</code> instance for informative purposes.
 * The reference is 'const' and cannot be modified, only inspected.
 *
 * @author J. Marrero
 */
class LinkException : public core::Exception
{
    AMANDA_OBJECT(LinkException, core::Exception)
public:

    LinkException(const core::String& message, const Symbol& symbol);
    virtual ~LinkException() throw();

    const Symbol& getSymbol() const;

protected:

    const Module*   module;
    const Section*  section;
    const Symbol&   symbol;
} ;

class UndefinedSymbolError : public core::Exception
{
    AMANDA_OBJECT(UndefinedSymbolError, core::Exception)

public:

    UndefinedSymbolError(const core::String& sectionName, const core::String& symbolName);
    virtual ~UndefinedSymbolError() throw();

    const core::String& getSectionName() const;
    const core::String& getSymbolName() const;

protected:

    core::String sectionName;
    core::String symbolName;
};

}
}

#endif /* LINKERROR_H */

