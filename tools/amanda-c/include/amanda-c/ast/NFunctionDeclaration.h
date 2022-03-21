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
 * File:   NFunctionDeclaration.h
 * Author: Javier Marrero
 *
 * Created on March 18, 2022, 2:02 AM
 */

#ifndef NFUNCTIONDECLARATION_H
#define NFUNCTIONDECLARATION_H

#include <amanda-c/ast/NDeclaration.h>
#include <amanda-c/ast/NBlock.h>

#include <vector>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NFunctionDeclaration : public NDeclaration
{
    AMANDA_OBJECT(NFunctionDeclaration, NDeclaration)

public:

    NFunctionDeclaration(const core::String& identifier, NBlock* statements);
    virtual ~NFunctionDeclaration();
    
    virtual core::String toString() const;

protected:

    core::String                    identifier;
    core::StrongReference<NBlock>   statements;
} ;

}
}
}

#endif /* NFUNCTIONDECLARATION_H */

