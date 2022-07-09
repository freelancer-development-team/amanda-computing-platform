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
 * File:   NullOptimizationCriteria.h
 * Author: Javier Marrero
 *
 * Created on July 9, 2022, 9:42 AM
 */

#ifndef NULLOPTIMIZATIONCRITERIA_H
#define NULLOPTIMIZATIONCRITERIA_H

#include <amanda-vm/Runtime/AdaptiveOptimizationCondition.h>

namespace amanda
{
namespace vm
{

/**
 * This criteria forces the virtual machine to never ´perform jit compilation
 * of a piece of code. This inhibits all previous or further optimizations to
 * the code. It essentially turns the virtual machine into a big-interpreter.
 *
 * @return
 */
class NullOptimizationCriteria : public AdaptiveOptimizationCondition
{
    AMANDA_OBJECT(NullOptimizationCriteria, AdaptiveOptimizationCondition)
public:

    virtual bool eval() const;

} ;

}
}

#endif /* NULLOPTIMIZATIONCRITERIA_H */

