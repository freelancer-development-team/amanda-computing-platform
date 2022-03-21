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
 * File:   AstNodeBase.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 4:48 PM
 */

#ifndef ASTNODEBASE_H
#define ASTNODEBASE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/Console.h>
#include <amanda-vm/IO/PrintStream.h>
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

    virtual Value*          generateCode(CodeGenContext& context);
    unsigned                countChildren() const;
    AstNodeBase&            getRootNode();
    bool                    hasChildren() const;
    virtual void            printNode(unsigned indent = 0, const io::PrintStream& stream = io::console().err);
    virtual void            printNodeAndChildren(unsigned indent = 0, const io::PrintStream& stream = io::console().err);
    virtual core::String    toString() const;

protected:

    void                    addChild(AstNodeBase* child);
    core::String            buildHeaderString() const;
    AstNodeBase*            getParent();
    bool                    hasParent();

private:

    core::String            makePadding(unsigned size);

    AstNodeBase*                parent;
    std::vector<AstNodeBase*>   children;
} ;

}
}

#endif /* ASTNODEBASE_H */

