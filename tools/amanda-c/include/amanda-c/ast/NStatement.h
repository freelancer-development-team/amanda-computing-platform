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
 * File:   NStatement.h
 * Author: Javier Marrero
 *
 * Created on March 13, 2022, 12:48 AM
 */

#ifndef NSTATEMENT_H
#define NSTATEMENT_H

#include <amanda-vm/IL/AstNodeBase.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NStatement : public il::AstNodeBase
{
    AMANDA_OBJECT(NStatement, il::AstNodeBase)

public:

    NStatement();
    virtual ~NStatement();
    
} ;

}
}
}

#endif /* NSTATEMENT_H */

