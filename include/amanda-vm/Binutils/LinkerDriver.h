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
 * File:   LinkerDriver.h
 * Author: Javier Marrero
 *
 * Created on May 2, 2022, 4:05 PM
 */

#ifndef LINKERDRIVER_H
#define LINKERDRIVER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/OutputStream.h>
#include <amanda-vm/ADT/Array.h>
#include <amanda-vm/Binutils/Module.h>
#include <amanda-vm/Binutils/Symbol.h>

// C++
#include <vector>

namespace amanda
{
namespace binutils
{

/**
 * <code>LinkerDriver</code> are objects that manage the linking stage of the
 * module building process. This object has the ability to merge different
 * object files into a single deployment unit (the true concept of module in
 * this context). 
 *
 * @author J. Marrero
 */
class LinkerDriver : public core::Object
{
    AMANDA_OBJECT(LinkerDriver, core::Object)
public:

    LinkerDriver(Module* master);
    virtual ~LinkerDriver();

    void    addLibraries(adt::Array<Module*> libs);
    void    addLibrary(Module* lib);
    void    addObjectFile(Module* additional);
    void    addOutputStream(io::OutputStream* stream);
    void    dump() const;
    Symbol* findSymbolInLibraries(const core::String& name) const;
    Module& getMasterModule() const;
    void    link();

protected:

    std::vector<Module*>            inputModules;
    std::vector<Module*>            libraries;
    std::vector<io::OutputStream*>  outputStreams;

} ;

}
}

#endif /* LINKERDRIVER_H */

