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
 * File:   NativeCProcedure.cpp
 * Author: Javier Marrero
 * 
 * Created on May 25, 2022, 11:01 PM
 */

#include <amanda-vm/Runtime/NativeCProcedure.h>
#include <amanda-vm/Runtime/FfiException.h>

// C++
#include <ffi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ffitarget.h>

// Define syntactic-sugar for comparing strings
#define SWITCH_CASE(s)  if (type == (s))
#define CASE(s)         else if (type == (s))
#define DEFAULT()       else

// Utility macros
#define DECL_VALUE(t)       t value = 0
#define BYTEBUFFER(x)       ((vm::vm_byte_t*) (x))
#define DIRECTCOPY(x)       stack.pop(BYTEBUFFER(&(x)), sizeof((x)))
#define FINAL_COPY(x, t)    do { \
                                t* _t = (t*) memory; \
                                *_t = (t) (x); \
                               } \
                            while (0)
#define DO_COPIES(t, t1)    do \
                            { \
                                DECL_VALUE(t); \
                                DIRECTCOPY(value); \
                                FINAL_COPY(value, t1); \
                            } while (0)

using namespace amanda;
using namespace amanda::vm;

const logging::Logger& NativeCProcedure::LOGGER = logging::Logger::getLogger("amanda.vm.NativeCProcedure")->getConstReference();

NativeCProcedure::NativeCProcedure(fpointer_t handle, const core::String& name, const core::String& arguments, const core::String& returnType)
:
NativeProcedure(handle, name),
prepared(false)
{
    // Parse the arguments
    parseArgumentsString(arguments);

    // Parse the return type
    this->returnType = parseSingleFfiType(returnType);

    // Log the results of the function creation
    LOGGER.info("created native procedure handle to process at 0x%p, with name '%s', and with %llu arguments.",
                handle, name.toCharArray(), argumentTypes.size());
}

NativeCProcedure::~NativeCProcedure()
{
}

void NativeCProcedure::call(Stack& stack)
{
    // If the function is not prepared, prepare it. This section is critical
    // and a synchronization point
    AMANDA_SYNCHRONIZED(lock);
    {
        if (!prepared)
        {
            if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argumentTypes.size(), returnType, argumentTypes.data()) != FFI_OK)
            {
                LOGGER.error("error on ffi-function preparation (on symbol '%s').", name.toCharArray());
                throw FfiException("error preparing native function.");
            }
            prepared = true;
        }
    }
    AMANDA_DESYNCHRONIZED(lock);

    // Prepare the arguments
    std::vector<void*> values;
    values.reserve(argumentTypes.size());
    prepareArguments(values, stack);

    // Prepare the return-value pointer
    size_t rsize = getArgumentSize(returnType);
    if (rsize < sizeof (uintptr_t))
    {
        rsize = sizeof (uintptr_t);
    }
    LOGGER.debug("allocated %llu bytes for return value (register size %llu bytes, 'ffi_arg' size %llu).",
                 rsize, sizeof (uintptr_t), sizeof (ffi_arg));

    void*   rc = std::calloc(1, rsize);
    assert(rc != NULL && "Null pointer exception");

    // Call
    LOGGER.debug("transferring control to native-defined procedure <%s>.", name.toCharArray());
    ffi_call(&cif, FFI_FN(functionHandle), rc, values.empty() ? NULL : values.data());

    // Delete the values
    unprepareArguments(values);

    // Push the return value on the stack
    // and clean the allocated resource
    stack.push((vm::vm_byte_t*) rc, getArgumentSize(returnType), false);

    // Return
    LOGGER.debug("success on native call (last quad-word of return value 0x%llx)", *((vm::vm_qword_t*) (rc)));
    std::free(rc);
}

size_t NativeCProcedure::getArgumentSize(ffi_type* type) const
{
    size_t result = 0;
    if (type == &ffi_type_schar || type == &ffi_type_uchar)
    {
        result = sizeof (char);
    }
    else if (type == &ffi_type_sint || type == &ffi_type_uint)
    {
        result = sizeof (int);
    }
    else if (type == &ffi_type_slong || type == &ffi_type_ulong)
    {
        result = sizeof (long);
    }
    else if (type == &ffi_type_pointer)
    {
        result = sizeof (void*);
    }
    else if (type == &ffi_type_void)
    {
        result = 0;
    }
    return result;
}

size_t NativeCProcedure::getArgumentsSize() const
{
    size_t result = 0;
    for (std::vector<ffi_type*>::const_iterator it = argumentTypes.begin(),
         end = argumentTypes.end(); it != end; ++it)
    {
        result += getArgumentSize((*it));
    }
    return result;
}

size_t NativeCProcedure::getSizeForType(const core::String& type) const
{
    size_t result = 0;


    return result;
}

size_t NativeCProcedure::getVirtualMachineSizeForNative(ffi_type* type) const
{
    size_t result = 0;
    if (type == &ffi_type_void)
    {
        result = 0;
    }
    else if (type == &ffi_type_pointer)
    {
        result = VM_ADDRESS_SIZE;
    }
    else if (type == &ffi_type_sint || type == &ffi_type_uint)
    {
        result = VM_DWORD_SIZE;
    }
    return result;
}

void NativeCProcedure::parseArgumentsString(const core::String& arguments)
{
    std::vector<core::String> argumentsList = arguments.split(":");
    for (std::vector<core::String>::const_iterator it = argumentsList.begin(),
         end = argumentsList.end(); it != end; ++it)
    {
        ffi_type* type = parseSingleFfiType((*it));
        if (type != &ffi_type_void)
        {
            this->argumentTypes.push_back(type);
        }
    }
}

ffi_type* NativeCProcedure::parseSingleFfiType(const core::String& type) const
{

    ffi_type* result = NULL;

    SWITCH_CASE(FFI_TYPE_INT8)
    {
        result = &ffi_type_schar;
    }

    CASE(FFI_TYPE_INT32)
    {
        result = &ffi_type_sint;
    }

    CASE(FFI_TYPE_NATIVE_POINTER)
    {
        result = &ffi_type_pointer;
    }

    CASE(FFI_TYPE_NONE)
    {
        result = &ffi_type_void;
    }

    DEFAULT()
    {
        LOGGER.error("invalid parameter passed to ffi-type argument function: %s.", type.toCharArray());
        throw FfiException("invalid type passed to parsing function.");
    }

    return result;
}

void NativeCProcedure::prepareArguments(std::vector<void*>& values, Stack& stack)
{
    for (std::vector<ffi_type*>::const_reverse_iterator it = argumentTypes.rbegin(),
         end = argumentTypes.rend(); it != end; ++it)
    {
        size_t      argumentIndex = argumentTypes.size();
        ffi_type*   argumentPointer = *it;
        size_t      argumentSize  = getArgumentSize(argumentPointer);

        void* memory = NULL;
        if (argumentSize > 0)
        {
            memory = std::calloc(1, argumentSize);
            if (!memory)
            {
                LOGGER.error("unable to allocate memory for argument retrieval.");
                throw FfiException("error while preparing function arguments.");
            }
        }

        LOGGER.trace("allocated %lluB-sized block of memory (argument %u of %u)", argumentSize, argumentIndex, argumentTypes.size());
        size_t  vmTypeSize = getVirtualMachineSizeForNative(argumentPointer);
        switch (vmTypeSize)
        {
            case VM_ADDRESS_SIZE:
            {
                DECL_VALUE(vm::vm_address_t);
                DIRECTCOPY(value);
                FINAL_COPY(value, uintptr_t);
                break;
            }
            case VM_DWORD_SIZE:
            {
                DECL_VALUE(vm::vm_dword_t);
                DIRECTCOPY(value);
                FINAL_COPY(value, unsigned int);
                break;
            }
            default:
            {
                if (vmTypeSize != 0)
                {
                    LOGGER.error("invalid argument size, unable to pop argument from stack.");
                    throw FfiException("invalid argument size.");
                }
            }
        }

        // Push the pointer into the vector
        values.push_back(memory);

        // Decrease the argument index
        --argumentIndex;
    }
}

void NativeCProcedure::unprepareArguments(std::vector<void*>& values)
{
    for (unsigned i = 0; i < values.size(); ++i)
    {
        std::free(values.at(i));
    }
}

// Undefine the macros for comparing strings
#undef SWITCH_CASE
#undef CASE
#undef DEFAULT

// Undefine utility macros
#undef DECL_VALUE
#undef BYTEBUFFER
#undef DIRECTCOPY
#undef FINAL_COPY
