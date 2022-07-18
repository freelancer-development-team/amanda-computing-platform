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
 * File:   Module.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 3:06 PM
 */

#ifndef MODULE_H
#define MODULE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IL/Function.h>

namespace amanda
{
namespace il
{

/**
 * A <code>Module</code> is the main container class for the Intermediate
 * Language representation. A <code>Module</code> instance is used to store
 * all the information related to a IL-module. They are top level containers
 * of other IL objects.
 * <p>
 * Each module directly contains a list of functions and libraries (or modules)
 * a module depends on, a global symbol table and various data about the
 * target´s characteristics.
 *
 * @author J. Marrero
 */
class Module : public core::Object
{
    AMANDA_OBJECT(Module, core::Object)

public:

    typedef std::vector<Function*>  FunctionList;

    Module(const core::String& id);
    virtual ~Module();

    void                            addFunction(Function* f);
    const std::vector<Function*>&   getFunctions() const;
    const core::String&             getIdentifier() const;

protected:

    std::vector<Function*>  functions;
    core::String            identifier;
} ;

}
}

#endif /* MODULE_H */

