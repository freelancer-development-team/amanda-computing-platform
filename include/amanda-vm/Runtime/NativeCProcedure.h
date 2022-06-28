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
 * File:   NativeCProcedure.h
 * Author: Javier Marrero
 *
 * Created on May 25, 2022, 11:01 PM
 */

#ifndef NATIVECPROCEDURE_H
#define NATIVECPROCEDURE_H

#include <amanda-vm/Runtime/NativeProcedure.h>
#include <amanda-vm/Logging/Logger.h>

// C
#include <vector>
#include <ffi.h>
#include <ffitarget.h>

namespace amanda
{
namespace vm
{

class NativeCProcedure : public NativeProcedure
{
    AMANDA_OBJECT(NativeCProcedure, NativeProcedure)
public:

    NativeCProcedure(fpointer_t handle, const core::String& name,
                     const core::String& arguments, const core::String& returnType);
    virtual ~NativeCProcedure();

    virtual void call(Stack& stack);

private:

    static const logging::Logger& LOGGER;

    std::vector<ffi_type*>  argumentTypes;
    ffi_cif                 cif;
    bool                    prepared;
    ffi_type*               returnType;

    size_t      getArgumentSize(ffi_type* type) const;
    size_t      getArgumentsSize() const;
    size_t      getSizeForType(const core::String& type) const;
    size_t      getVirtualMachineSizeForNative(ffi_type* type) const;
    void        parseArgumentsString(const core::String& arguments);
    ffi_type*   parseSingleFfiType(const core::String& type) const;
    void        prepareArguments(std::vector<void*>& values, Stack& args);
    void        unprepareArguments(std::vector<void*>& values);

} ;

}
}

#endif /* NATIVECPROCEDURE_H */

