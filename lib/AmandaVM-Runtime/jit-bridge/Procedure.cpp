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
#include <amanda-vm/System.h>

// C/C++
#include <ck_spinlock.h>
#include <csignal>

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
returnValueSize(0),
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

void Procedure::applyStack(Stack * const stack)
{
    this->stack = stack;
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

void Procedure::execute()
{
    if (isOptimized())
    {
        /* Run the 'jitted' code. */
        executeOptimized();
    }
    else
    {
        /* Interpret the code */
        executeInterpreted();
    }

    // Check if needs optimization
    if (!isOptimized() && shouldOptimize())
    {
        optimize();
    }

    // Increment the count of executions
    ++executionCount;
}

void Procedure::executeInterpreted()
{
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

                stack->pop(&operand1, VM_BYTE_SIZE);
                stack->pop(&operand2, VM_BYTE_SIZE);
                result = operand1 + operand2;

                stack->push(&result, VM_BYTE_SIZE, false);
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

                    // Get the arguments and the result value

                    // Call the method
                }
                else
                {
                    LOGGER.error("attempted call to non-executable object, or non native function (%s).", symbolName.toCharArray());
                    throw IllegalStateException("attempted call to data object.");
                }
                break;
            }
            case I_LOAD:
            {
                ip += VM_QWORD_SIZE;
                break;
            }
            case I_PUSHA:
            {
                stack->push(pool + ip, VM_ADDRESS_SIZE);
                ip += VM_ADDRESS_SIZE;

                break;
            }
            case I_PUSHB:
            {
                stack->push(pool + ip, VM_BYTE_SIZE);
                ip += VM_BYTE_SIZE;

                break;
            }
            case I_PUSHW:
            {
                stack->push(pool + ip, VM_WORD_SIZE);
                ip += VM_WORD_SIZE;

                break;
            }
            case I_PUSHL:
            {
                stack->push(pool + ip, VM_DWORD_SIZE);
                ip += VM_DWORD_SIZE;

                break;
            }
            case I_PUSHQ:
            {
                stack->push(pool + ip, VM_QWORD_SIZE);
                ip += VM_QWORD_SIZE;

                break;
            }
            case I_RETB:
            {
                returnValueSize = VM_BYTE_SIZE;
                rflag = 1;
                break;
            }
            case I_RETL:
            {
                // Set the return value size
                returnValueSize = VM_DWORD_SIZE;

                // Set the return flag
                rflag = 1;
                break;
            }
                // Conversion operations
            case I_W2Q:
            {
                vm::vm_word_t   operand = 0;
                vm::vm_qword_t  result = 0;

                stack->pop((vm::vm_byte_t*) & operand, VM_WORD_SIZE);
                result = operand;
                stack->push(result);

                break;
            }
                // Comparison operators
            case I_CEQQ:
            {
                vm::vm_qword_t  operand1 = 0;
                vm::vm_qword_t  operand2 = 0;
                vm::vm_byte_t   result = 0;

                // Pop the two operands, compare and set the CPU flag
                operand1    = stack->pop<vm::vm_qword_t>();
                operand2    = stack->pop<vm::vm_qword_t>();
                result      = operand1 == operand2;

                break;
            }
                // Flow control
            case I_INVOKE:
            {


                break;
            }
            default:
            {
                LOGGER.error("the virtual machine attempted to execute an invalid operation <0x%x> (pc: 0x%llx)", opcode, ip);
                throw IllegalInstructionException("invalid execution", opcode);
            }
        }
    }
}

void Procedure::executeOptimized()
{
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

const size_t Procedure::getReturnValueSize() const
{
    return returnValueSize;
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
