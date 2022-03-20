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
 * File:   NDeclaration.h
 * Author: Javier Marrero
 *
 * Created on March 19, 2022, 1:26 PM
 */

#ifndef NDECLARATION_H
#define NDECLARATION_H

#include <amanda-vm/IL/AstNodeBase.h>
#include <amanda-c/ast/Lists.h>

#include <vector>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NDeclarationBlock;

class NDeclaration : public il::AstNodeBase
{
    AMANDA_OBJECT(NDeclaration, il::AstNodeBase)

public:

    NDeclaration();
    virtual ~NDeclaration();

    void addDeclarations(NDeclarationBlock* declarations);

} ;

/**
 * The declaration block class is a container class for multiple declaration
 * objects. It does not contains encapsulated data in order to keep the code
 * simple.
 *
 * @author J. Marrero
 */
class NDeclarationBlock : public il::AstNodeBase
{
    AMANDA_OBJECT(NDeclarationBlock, il::AstNodeBase);

public:

    NDeclarationBlock();
    virtual ~NDeclarationBlock();

    void                    addDeclaration(NDeclaration* declaration);
    const DeclarationList&  getDeclarations() const ;

protected:

    DeclarationList declarations;
};

}
}
}

#endif /* NDECLARATION_H */

