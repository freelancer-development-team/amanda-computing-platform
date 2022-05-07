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
 * File:   PassManager.h
 * Author: Javier Marrero
 *
 * Created on March 23, 2022, 9:17 AM
 */

#ifndef PASSMANAGER_H
#define PASSMANAGER_H

#include <amanda-vm/Object.h>
#include <amanda-vm/IL/AbstractPass.h>
#include <amanda-vm/IL/Module.h>

#include <set>

namespace amanda
{
namespace il
{

/**
 * Instances of this class schedules the different optimization & code generation
 * passes. Different instances of the <code>AbstractPass</code> class may be
 * added to objects of this class to perform different transformation to the
 * IL tree represented by a <code>Module</code>. Pass managers can be recycled,
 * and that is why it is provided a method to override the current module; but
 * please, notice that switching modules in the middle of a run is unspecified
 * behavior (looking at you, multi-threading).
 * 
 */
class PassManager : public core::Object
{
    AMANDA_OBJECT(PassManager, core::Object)

public:

    PassManager(Module& module);
    virtual ~PassManager();
    
    bool addPassForScheduling(AbstractPass* pass);
    void run();
    void setModule(Module& module);

protected:

    typedef std::set<AbstractPass*> PassList;
    
private:

    Module&                 module;
    PassList                passes;
} ;

}
}

#endif /* PASSMANAGER_H */

