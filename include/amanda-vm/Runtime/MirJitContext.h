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
 * File:   MirJitContext.h
 * Author: Javier Marrero
 *
 * Created on March 29, 2022, 9:55 AM
 */

#ifndef MIRJITCONTEXT_H
#define MIRJITCONTEXT_H

#include <amanda-vm-c/sdk-configuration.h>
#include <amanda-vm/Runtime/JitContext.h>

#ifdef SDK_BUILD_USING_MIR_JIT

#include <amanda-vm-c/sdk-jit-engine.h>

namespace amanda
{
namespace vm
{
namespace jit
{

/**
 * A template utilization for utilizing the lightweight MIR just-in-time compilation
 * framework.
 */
class MirJitContext : public JitContext
{
    AMANDA_OBJECT(MirJitContext, JitContext)
public:

    MirJitContext();
    virtual ~MirJitContext();

    virtual void lock() const;
    virtual void unlock() const;

} ;

}
}
}

#endif
#endif /* MIRJITCONTEXT_H */

