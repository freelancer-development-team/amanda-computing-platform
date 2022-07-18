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
 * File:   NCompilationUnit.cpp
 * Author: Javier Marrero
 * 
 * Created on March 18, 2022, 1:32 AM
 */

#include <amanda-c/ast/NCompilationUnit.h>
#include <amanda-c/ast/NFunctionDeclaration.h>

// C++
#include <cstdio>
#include <algorithm>

using namespace amanda;
using namespace amanda::compiler::ast;

NCompilationUnit::NCompilationUnit(const core::String& name)
:
name(name)
{
}

NCompilationUnit::~NCompilationUnit()
{
}

il::Module* NCompilationUnit::performSSATransformationForModule(il::CodeGenContext& context)
{
    il::Module* result = new il::Module(getName());
    for (ConstIterator it = begin(), end = this->end(); it != end; ++it)
    {
        AstNodeBase* node = (*it);
        if (node->is<NNamespaceDeclaration>())
        {
            const std::vector<il::Value*>& values = performSSATransformationForNamespace(context, static_cast<NNamespaceDeclaration*> (node));
            for (std::vector<il::Value*>::const_iterator it = values.begin(),
                 end = values.end(); it != end; ++it)
            {
                if ((*it)->is<il::Function>())
                {
                    result->addFunction(static_cast<il::Function*> (*it));
                }
            }
        }
        else if (node->is<NFunctionDeclaration>())
        {
            result->addFunction(static_cast<il::Function*> (node->performSSATransformation(context)));
        }
    }
    return result;
}

const core::String& NCompilationUnit::getName() const
{
    return name;
}

NNamespaceDeclaration* NCompilationUnit::getCurrentNamespace() const
{
    return namespaces.top();
}

void NCompilationUnit::popNamespace()
{
    assert(namespaces.size() > 0 && "Stack underflow.");
    NNamespaceDeclaration* object = namespaces.top();
    object->release();
}

NNamespaceDeclaration& NCompilationUnit::pushNamespace(NNamespaceDeclaration* object)
{
    assert(object != NULL && "Null pointer exception.");

    object->grab();
    namespaces.push(object);

    return *object;
}

std::vector<il::Value*> NCompilationUnit::performSSATransformationForNamespace(il::CodeGenContext& context, NNamespaceDeclaration* current)
{
    // Create the result vector and reserve 64 slots
    // (512B memory in 64bit machines, 256B in 32bit machines)
    std::vector<il::Value*> result;
    result.reserve(64);

    // Build all the IL in-memory. For this process we will descend recursively
    // as long as there are name spaces with unprocessed symbols.
    for (ConstIterator it = current->begin(), end = current->end(); it != end; ++it)
    {
        if ((*it)->is<NNamespaceDeclaration>())
        {
            const std::vector<il::Value*>& partial = performSSATransformationForNamespace(context, static_cast<NNamespaceDeclaration*> (*it));
            std::copy(partial.begin(), partial.end(), std::back_inserter(result));
        }
        else
        {
            result.push_back((*it)->performSSATransformation(context));
        }
    }

    // Return the results of that
    return result;
}

