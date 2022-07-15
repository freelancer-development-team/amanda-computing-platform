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
 * File:   ValueReferrer.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 3:57 PM
 */

#ifndef VALUEREFERRER_H
#define VALUEREFERRER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IL/Value.h>
#include <amanda-vm/IL/Use.h>

#include <vector>

namespace amanda
{
namespace il
{

/**
 * <code>ValueReferrer</code> objects are values that can take other values
 * as operands.
 */
class ValueReferrer : public Value
{
    AMANDA_OBJECT(ValueReferrer, Value)

public:

    static UseList buildOperandList(unsigned numOperands, ...);

    virtual ~ValueReferrer();

    unsigned        getNumberOfOperands() const;
    Value*          getOperand(unsigned i) const;
    const UseList&  getOperandList() const;
    Use&            getOperandUse(unsigned i);
    const Use&      getOperandUse(unsigned i) const;
    void            setOperand(unsigned i, Value* v);
    void            replaceUsesOfWith(Value* from, Value* to);

protected:

    UseList operandList;

    ValueReferrer(const Type* type, unsigned vty);
    ValueReferrer(const Type* type, unsigned vty, const UseList& operandList);

} ;

}
}

#endif /* VALUEREFERRER_H */

