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
 * File:   AstNodeBase.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 4:48 PM
 */

#ifndef ASTNODEBASE_H
#define ASTNODEBASE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IL/CodeGenContext.h>

#include <vector>

namespace amanda
{
namespace il
{

class Value;

class AstNodeBase : public core::Object
{
    AMANDA_OBJECT(AstNodeBase, core::Object)
    
public:

    typedef std::vector<AstNodeBase*>::iterator         Iterator;
    typedef std::vector<AstNodeBase*>::const_iterator   ConstIterator;

    AstNodeBase();
    virtual ~AstNodeBase();

    virtual Value*  generateCode(CodeGenContext& context) = 0;
    bool            hasChildren() const;

protected:

    void addChild(AstNodeBase* child);

private:

    std::vector<AstNodeBase*> children;
} ;

}
}

#endif /* ASTNODEBASE_H */

