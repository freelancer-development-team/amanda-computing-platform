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
 * File:   AdaptiveOptimizationCondition.h
 * Author: Javier Marrero
 *
 * Created on June 3, 2022, 2:57 AM
 */

#ifndef ADAPTIVEOPTIMIZATIONCONDITION_H
#define ADAPTIVEOPTIMIZATIONCONDITION_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace vm
{

/**
 * Allows to judge when a procedure must be just-in-time compiled based on
 * arbitrary conditions.
 *
 * @author J. Marrero
 */
class AdaptiveOptimizationCondition : public core::Object
{
    AMANDA_OBJECT(AdaptiveOptimizationCondition, core::Object)

public:

    /**
     * If eval returns true, the function has a criteria for being just-in-time
     * compiled.
     * 
     * @return true if the function must be optimized, false otherwise
     */
    virtual bool eval() const = 0;
} ;

}
}

#endif /* ADAPTIVEOPTIMIZATIONCONDITION_H */

