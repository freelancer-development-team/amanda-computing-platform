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
 * File:   CodeGenContext.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 5:59 PM
 */

#ifndef CODEGENCONTEXT_H
#define CODEGENCONTEXT_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IL/Type.h>

// C++
#include <vector>

namespace amanda
{
namespace il
{

class Module;

class CodeGenContext : public core::Object
{
    AMANDA_OBJECT(CodeGenContext, core::Object)

public:

    CodeGenContext();
    virtual ~CodeGenContext();

    unsigned    allocateValueIdentifier();
    Module*     getModule() const;
    const Type* getPrimitiveType(Type::TypeID idNumber);
    void        setModule(Module* module);

protected:

    core::StrongReference<Module>   module;
    std::vector<Type*>              types;
    unsigned                        vid;
} ;

}
}

#endif /* CODEGENCONTEXT_H */

