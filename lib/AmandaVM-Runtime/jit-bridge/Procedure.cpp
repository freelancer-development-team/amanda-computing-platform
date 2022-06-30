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
 * File:   Procedure.cpp
 * Author: Javier Marrero
 * 
 * Created on June 3, 2022, 2:48 AM
 */

#include <amanda-vm/Runtime/Procedure.h>
#include <amanda-vm/Runtime/Context.h>
#include <amanda-vm/Runtime/IllegalInstructionException.h>
#include <amanda-vm/Runtime/IllegalStateException.h>
#include <amanda-vm/IO/Utility.h>
#include <amanda-vm/Threading/Runnable.h>
#include <amanda-vm/Threading/Thread.h>
#include <amanda-vm/Binutils/vm-opcodes.h>
#include <amanda-vm/Threading/Thread.h>
#include <amanda-vm/System.h>

// C/C++
#include <ck_spinlock.h>
#include <csignal>

// Foreign function interface
#include <ffi.h>
#include <ffitarget.h>

using namespace amanda;
using namespace amanda::vm;

logging::Logger& Procedure::LOGGER = logging::Logger::getLogger("amanda.vm.Procedure")->getReference();

Procedure::Procedure(const Context& context, const core::String& name,
                     const binutils::Symbol::SymbolTableEntry* symbol)
:
context(context),
executionCount(0),
ip(0),
name(name),
optimized(false),
symbol(symbol)
{
}

Procedure::~Procedure()
{
    for (std::deque<const AdaptiveOptimizationCondition*>::const_iterator it = optimizationCritera.begin(),
         end = optimizationCritera.end(); it != end; ++it)
    {
        // Release the previously grabbed reference
        (*it)->release();
    }
}

void Procedure::addOptimizationCriteria(const AdaptiveOptimizationCondition* criteria)
{
    // Grab a reference to the object
    criteria->grab();

    // Push it into the list
    optimizationCritera.push_back(criteria);
}

bool Procedure::equals(const Object* object)
{
    bool result = false;
    if (object->is<Procedure>())
    {
        if (static_cast<const Procedure*> (object)->getName() == getName())
        {
            result = true;
        }
    }
    return result;
}

vm::vm_qword_t Procedure::execute(Stack& stack)
{
    LOGGER.debug("executing subroutine at 0x%llx, with stack depth %llu (on thread %llu).",
                 symbol->value, stack.getDepth(),
                 concurrent::Thread::currentThreadId());

    // Push a new stack frame
    stack.pushFrame();

    // Initial variables
    vm::vm_qword_t rvsize = 0;

    // Optimization conditions
    if (isOptimized())
    {
        /* Run the 'jitted' code. */
        rvsize = executeOptimized();
    }
    else
    {
        /* Interpret the code */
        rvsize = executeInterpreted(stack);
    }

    //
    vm_qword_t result = 0;
    stack.peek((vm_byte_t*) &result, rvsize);
    LOGGER.info("function returned %llu bytes (most significant quad word 0x%llx)",
                rvsize, result);

    // Pop the frame
    stack.popFrame(rvsize);

    // Check if needs optimization
    if (!isOptimized() && shouldOptimize())
    {
        optimize();
    }

    // Increment the count of executions
    AMANDA_SYNCHRONIZED(lock);
    {
        ++executionCount;
    }
    AMANDA_DESYNCHRONIZED(lock);

    return rvsize;
}

vm::vm_qword_t Procedure::executeInterpreted(Stack& stack)
{
#define BYTEPOINTER(x)  ((vm::vm_byte_t*) (&(x)))

    vm::vm_size_t   rvsize = 0;
    vm::vm_byte_t   rflag = 0;
    
    while ((ip < symbol->size) && (rflag == 0))
    {
        vm::vm_byte_t*  pool = (vm::vm_byte_t*) (executableModule->findSection(CODE_SECTION_NAME).address + symbol->value);
        vm::vm_byte_t   opcode = fetch();

        switch (opcode)
        {
            case I_ADDB:
            {
                vm::vm_byte_t operand1 = 0;
                vm::vm_byte_t operand2 = 0;
                vm::vm_byte_t result = 0;

                stack.pop(&operand1, VM_BYTE_SIZE);
                stack.pop(&operand2, VM_BYTE_SIZE);
                result = operand1 + operand2;

                stack.push(&result, VM_BYTE_SIZE, false);
                break;
            }
            case I_ADDW:
            {
                vm::vm_word_t operand1 = 0;
                vm::vm_word_t operand2 = 0;
                vm::vm_word_t result = 0;

                stack.pop(BYTEPOINTER(operand1), VM_WORD_SIZE);
                stack.pop(BYTEPOINTER(operand2), VM_WORD_SIZE);
                result = operand1 + operand2;

                stack.push(BYTEPOINTER(result), VM_WORD_SIZE);
                break;
            }
            case I_ADDL:
            {
                vm::vm_dword_t operand1 = 0;
                vm::vm_dword_t operand2 = 0;
                vm::vm_dword_t result = 0;

                stack.pop(BYTEPOINTER(operand1), VM_DWORD_SIZE);
                stack.pop(BYTEPOINTER(operand2), VM_DWORD_SIZE);
                result = operand1 + operand2;

                stack.push(BYTEPOINTER(result), VM_DWORD_SIZE);
                break;
            }
            case I_ADDQ:
            {
                vm::vm_qword_t operand1 = 0;
                vm::vm_qword_t operand2 = 0;
                vm::vm_qword_t result = 0;

                stack.pop(BYTEPOINTER(operand1), VM_QWORD_SIZE);
                stack.pop(BYTEPOINTER(operand2), VM_QWORD_SIZE);
                result = operand1 + operand2;

                stack.push(BYTEPOINTER(result), VM_QWORD_SIZE);
                break;
            }
            case I_CCALL:
            {
                vm::vm_address_t jumpTarget = 0;
                std::memmove(&jumpTarget, (pool + ip), VM_ADDRESS_SIZE);
                if (!io::isMachineBigEndian())
                {
                    io::swapEndianness(&jumpTarget, VM_ADDRESS_SIZE);
                }
                ip += VM_ADDRESS_SIZE;

                // Trace the request for jump
                LOGGER.debug("requesting native call to symbol with index 0x%llx.", jumpTarget);
                if (jumpTarget > executableModule->getSymbolCount())
                {
                    LOGGER.error("illegal call to native method, index out of bounds (%llu)", jumpTarget);
                    throw IllegalStateException("illegal native call, symbol index out of bounds.");
                }
                const binutils::Symbol::SymbolTableEntry* symbol = executableModule->findSymbol(jumpTarget);
                core::String symbolName = executableModule->findSymbolName(symbol->name);

                if (symbol->bind == binutils::Symbol::Bind_Native)
                {
                    LOGGER.debug("identified target of native call (function '%s')",
                                 symbolName.toCharArray());

                    // Allocate enough space for containing the arguments and
                    // the return value

                    // Call the method
                    if (context.callNative(symbolName, stack.getReference()) != FFI_OK)
                    {
                        throw IllegalStateException("invalid native call result.");
                    }
                }
                else
                {
                    LOGGER.error("attempted call to non-executable object, or non native function (%s).", symbolName.toCharArray());
                    throw IllegalStateException("attempted call to data object.");
                }
                break;
            }
            case I_INVOKE:
            {
                vm::vm_address_t jumpTarget = 0;
                std::memmove(&jumpTarget, (pool + ip), VM_ADDRESS_SIZE);
                if (!io::isMachineBigEndian())
                {
                    io::swapEndianness(&jumpTarget, VM_ADDRESS_SIZE);
                }
                ip += VM_ADDRESS_SIZE;

                // Trace the request for local invocation
                LOGGER.debug("requesting local call to symbol with index 0x%llx.", jumpTarget);
                if (jumpTarget > executableModule->getSymbolCount())
                {
                    LOGGER.error("illegal call to local method, index out of bounds (%llu)", jumpTarget);
                    throw IllegalStateException("illegal local call, symbol index out of bounds");
                }
                const binutils::Symbol::SymbolTableEntry* symbol = executableModule->findSymbol(jumpTarget);
                const core::String symbolName = executableModule->findSymbolName(symbol->name);

                if ((symbol->type == binutils::Symbol::Type_Function)
                     || (symbol->bind == binutils::Symbol::Bind_Extern))
                {
                    LOGGER.debug("identified target of local call (function '%s')", symbolName.toCharArray());

                    if (context.callLocal(symbolName, stack) != Context::ENOERR)
                    {
                        throw IllegalStateException("invalid local call result.");
                    }
                }
                else
                {
                    LOGGER.error("attempted call to non-executable object (%s).", symbolName.toCharArray());
                    throw IllegalStateException("attempted call to data object.");
                }
                break;
            }
            case I_JF:
            {
                vm::vm_qword_t address = *((vm::vm_qword_t*) pool + ip);
                ip += VM_ADDRESS_SIZE;

                if (!isZeroFlagSet())
                {
                    jumpToLocalAddress(address);
                }
                break;
            }
            case I_JMP:
            {
                vm::vm_qword_t address = *((vm::vm_qword_t*) pool + ip);
                ip += VM_ADDRESS_SIZE;

                jumpToLocalAddress(address);
                break;
            }
            case I_JT:
            {
                vm::vm_qword_t address = *((vm::vm_qword_t*) pool + ip);
                ip += VM_ADDRESS_SIZE;

                if (isZeroFlagSet())
                {
                    jumpToLocalAddress(address);
                }
                break;
            }
            case I_LOAD:
            {
                vm::vm_address_t address = *((vm::vm_qword_t*) pool + ip);
                ip += VM_QWORD_SIZE;

                // Switch endianness
                if (!io::isMachineBigEndian())
                {
                    io::swapEndianness(&address, VM_QWORD_SIZE);
                }

                LOGGER.debug("requesting load from address 0x%llx", address);
                break;
            }
            case I_PUSHA:
            {
                stack.push(pool + ip, VM_ADDRESS_SIZE);
                ip += VM_ADDRESS_SIZE;

                break;
            }
            case I_PUSHB:
            {
                stack.push(pool + ip, VM_BYTE_SIZE);
                ip += VM_BYTE_SIZE;

                break;
            }
            case I_PUSHW:
            {
                stack.push(pool + ip, VM_WORD_SIZE);
                ip += VM_WORD_SIZE;

                break;
            }
            case I_PUSHL:
            {
                stack.push(pool + ip, VM_DWORD_SIZE);
                ip += VM_DWORD_SIZE;

                break;
            }
            case I_PUSHQ:
            {
                stack.push(pool + ip, VM_QWORD_SIZE);
                ip += VM_QWORD_SIZE;

                break;
            }
            case I_RETB:
            {
                rvsize = VM_BYTE_SIZE;
                rflag = 1;
                break;
            }
            case I_RETW:
            {
                rvsize = VM_WORD_SIZE;
                rflag = 1;
                break;
            }
            case I_RETL:
            {
                // Set the return value size
                rvsize = VM_DWORD_SIZE;

                // Set the return flag
                rflag = 1;
                break;
            }
            case I_RETQ:
            {
                rvsize = VM_QWORD_SIZE;
                rflag = 1;
                break;
            }
#define SUBSTRACTION(type, size) \
            type substractor = 0; \
            type substrahend = 0; \
            type result = 0; \
            \
            stack.pop(BYTEPOINTER(substractor), size); \
            stack.pop(BYTEPOINTER(substrahend), size); \
            result = substrahend - substractor; \
            \
            stack.push(BYTEPOINTER(result), size); \
            break

            case I_SUBB:
            {
                SUBSTRACTION(vm::vm_byte_t, VM_BYTE_SIZE);
            }
            case I_SUBW:
            {
                SUBSTRACTION(vm::vm_word_t, VM_WORD_SIZE);
            }
            case I_SUBL:
            {
                vm::vm_dword_t substractor = 0;
                vm::vm_dword_t substrahend = 0;
                vm::vm_dword_t result = 0;

                stack.pop((vm::vm_byte_t*) (&substractor), VM_DWORD_SIZE);
                stack.pop((vm::vm_byte_t*) (&substrahend), VM_DWORD_SIZE);
                result = substrahend - substractor;

                stack.push((vm::vm_byte_t*) (&result), VM_DWORD_SIZE, false);
                break;
            }
            case I_SUBQ:
            {
                SUBSTRACTION(vm::vm_qword_t, VM_QWORD_SIZE);
            }
#undef SUBSTRACTION
                // Conversion operations
            case I_W2Q:
            {
                vm::vm_word_t   operand = 0;
                vm::vm_qword_t  result = 0;

                stack.pop((vm::vm_byte_t*) & operand, VM_WORD_SIZE);
                result = operand;
                stack.push(result);

                break;
            }
                // Comparison operators
#define COMPARE_EQUALS(type) \
            type operand1 = 0; \
            type operand2 = 0; \
            \
            operand1 = stack.pop<type>(); \
            operand2 = stack.pop<type>(); \
            eflags.m_zf = (operand1 == operand2) ? ONE : ZERO; \
            \
            break

            case I_CEQB:
            {
                COMPARE_EQUALS(vm::vm_byte_t);
            }
            case I_CEQW:
            {
                COMPARE_EQUALS(vm::vm_word_t);
            }
            case I_CEQL:
            {
                COMPARE_EQUALS(vm::vm_dword_t);
            }
            case I_CEQQ:
            {
                vm::vm_qword_t  operand1 = 0;
                vm::vm_qword_t  operand2 = 0;

                // Pop the two operands, compare and set the CPU flag
                operand1    = stack.pop<vm::vm_qword_t>();
                operand2    = stack.pop<vm::vm_qword_t>();
                eflags.m_zf = (operand1 == operand2) ? ONE : ZERO;

                break;
            }
#undef COMPARE_EQUALS
            default:
            {
                LOGGER.error("the virtual machine attempted to execute an invalid operation <0x%x> (pc: 0x%llx)", opcode, ip);
                throw IllegalInstructionException("invalid execution", opcode);
            }
        }
    }

    LOGGER.trace("function returning %llu bytes.", rvsize);
    return rvsize;

#undef BYTEPOINTER
}

vm::vm_qword_t Procedure::executeOptimized()
{
    return 0;
}

vm::vm_byte_t Procedure::fetch() const
{
    volatile vm::vm_byte_t* instructions = (vm::vm_byte_t*) (executableModule->findSection(CODE_SECTION_NAME).address + symbol->value);
    return instructions[ip++];
}

const core::String& Procedure::getName() const
{
    return name;
}

logging::Logger& Procedure::getLoggerInstance() const
{
    return LOGGER;
}

bool Procedure::isOptimized() const
{
    bool result = false;
    AMANDA_SYNCHRONIZED(lock);
    {
        result = optimized;
    }
    AMANDA_DESYNCHRONIZED(lock);

    return result;
}

const bool Procedure::isZeroFlagSet() const
{
    return eflags.m_zf == ONE;
}

void Procedure::jumpToLocalAddress(const vm::vm_address_t offset) const
{
    ip = offset;
}

void Procedure::optimize()
{
    /*
     * The optimization process is run in parallel in order to not to stop the
     * execution of the program. In uniprocessor machines this can increase the
     * overhead of building a function, so make it run in parallel only if we
     * may take advantage of true parallelism.
     */
    OptimizationRunnable runnable(this->getReference());
    if (core::getNumberOfAvailableCores() > 1)
    {
        concurrent::Thread thread(runnable);
        thread.start();
    }
    else
    {
        runnable.run();
    }
}

void Procedure::setExecutableModule(ExecutableModule& module)
{
    this->executableModule = &module;
}

void Procedure::setOptimized(bool optimized)
{
    AMANDA_SYNCHRONIZED(lock);
    {
        this->optimized = optimized;
    }
    AMANDA_DESYNCHRONIZED(lock);
}

bool Procedure::shouldOptimize() const
{
    bool result = true;
    for (std::deque<const AdaptiveOptimizationCondition*>::const_iterator it = optimizationCritera.begin(),
         end = optimizationCritera.end(); it != end; ++it)
    {
        result = result && (*it)->eval();
    }
    return result && (executionCount > 2);
}

// ======================= OPTIMIZATION RUNNABLE ===============================

Procedure::OptimizationRunnable::OptimizationRunnable(Procedure& procedure)
:
procedure(procedure)
{
}

void Procedure::OptimizationRunnable::run()
{

    // Set the optimization flag as true
    procedure.setOptimized(true);
}
