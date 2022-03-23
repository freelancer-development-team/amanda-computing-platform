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
 * File:   AstNodeBase.cpp
 * Author: Javier Marrero
 * 
 * Created on March 12, 2022, 4:48 PM
 */

#include <amanda-vm/IL/AstNodeBase.h>
#include <amanda-vm/IL/Value.h>

using namespace amanda;
using namespace amanda::il;

AstNodeBase::AstNodeBase()
:
parent(NULL)
{
    children.reserve(2); // Reserve enough space for a binary tree.
}

AstNodeBase::~AstNodeBase()
{
    for (Iterator it = children.begin(); it != children.end(); ++it)
    {
        assert(*it != NULL && "Null pointer exception.");
        (*it)->release();
    }
}

unsigned AstNodeBase::countChildren() const
{
    return children.size();
}

void AstNodeBase::doSemanticAnalysis()
{
}

bool AstNodeBase::hasChildren() const
{
    return !children.empty();
}

void AstNodeBase::addChild(AstNodeBase* child)
{
    assert(child != NULL && "Null pointer exception.");

    child->grab();
    child->parent = this;

    children.push_back(child);
}

AstNodeBase* AstNodeBase::getParent()
{
    return parent;
}

AstNodeBase& AstNodeBase::getRootNode()
{
    if (!hasParent())
    {
        return *this;
    }
    else
    {
        AstNodeBase* parent = getParent();
        while (parent->hasParent())
        {
            parent = parent->getParent();
        }
        assert(parent != NULL && "Null pointer exception.");

        return *parent;
    }
}

bool AstNodeBase::hasParent()
{
    return parent != NULL;
}

Value* AstNodeBase::generateCode(CodeGenContext& context)
{
    return NULL;
}

void AstNodeBase::printNode(unsigned indent, const io::PrintStream& stream)
{
    core::String indentedNewLines = core::String("\n").append(makePadding(indent));
    core::String str(makePadding(indent));

    str.append(toString());
    str.replace("\n", indentedNewLines);

    stream.println(str);
}

void AstNodeBase::printNodeAndChildren(unsigned indent, const io::PrintStream& stream)
{
    printNode(indent, stream);
    if (hasChildren())
    {
        for (std::vector<AstNodeBase*>::iterator it = children.begin(); it != children.end(); ++it)
        {
            if (*it != NULL)
                (*it)->printNodeAndChildren(indent + 1, stream);
        }
    }
    else
    {
        stream.println(core::String(makePadding(++indent)).append("--- no children ---"));
    }
}

core::String AstNodeBase::toString() const
{
    return buildHeaderString();
}

core::String AstNodeBase::buildHeaderString() const
{
    core::String buffer(getClassDynamically().getName());
    buffer.format(" (at 0x%p). Children: %u. ", this, countChildren());

    return buffer;
}

core::String AstNodeBase::makePadding(unsigned size)
{
    if (size > 0)
    {
        size *= 2; // Every indentation level reaches 2 spaces

        char array[size + 1] = {0};
        amanda::fill(array, ' ', size);

        return core::String(array);
    }
    else
    {
        return core::String::EMPTY;
    }
}
