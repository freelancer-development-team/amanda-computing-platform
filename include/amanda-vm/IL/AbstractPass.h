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
 * File:   AbstractPass.h
 * Author: Javier Marrero
 *
 * Created on March 23, 2022, 9:20 AM
 */

#ifndef ABSTRACTPASS_H
#define ABSTRACTPASS_H

#include <amanda-vm/Object.h>
#include <amanda-vm/IL/Module.h>

namespace amanda
{
namespace il
{

/**
 * This is the base class for passes that perform transformations over IL
 * components. Implementors of this class must provide the method <code>
 * runTransformation</code> in order to be useful.
 * 
 */
class AbstractPass : public core::Object
{
    AMANDA_OBJECT(AbstractPass, core::Object)

public:

    AbstractPass();
    AbstractPass(const core::String& name);
    virtual ~AbstractPass();
    
    void                setName(core::String name);
    Module&             getModule() const ;
    const core::String& getName() const ;
    virtual void        runTransformation();
    void                setModule(Module& module);

private:

    core::StrongReference<Module>   module;
    core::String                    name;
} ;

}
}

#endif /* ABSTRACTPASS_H */

