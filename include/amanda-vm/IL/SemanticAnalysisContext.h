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
 * File:   SemanticAnalysisContext.h
 * Author: Javier Marrero
 *
 * Created on March 23, 2022, 1:18 AM
 */

#ifndef SEMANTICANALYSISCONTEXT_H
#define SEMANTICANALYSISCONTEXT_H

#include <amanda-vm/Object.h>

namespace amanda
{
namespace il
{

/**
 * This class holds up the semantic analysis context for a particular compilation
 * unit.
 *
 * @author J. Marrero
 */
class SemanticAnalysisContext : public core::Object
{
    AMANDA_OBJECT(SemanticAnalysisContext, core::Object)

public:

    
} ;

}
}

#endif /* SEMANTICANALYSISCONTEXT_H */

