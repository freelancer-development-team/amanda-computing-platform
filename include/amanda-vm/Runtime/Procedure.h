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
 * File:   Procedure.h
 * Author: Javier Marrero
 *
 * Created on June 3, 2022, 2:48 AM
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Logging/Logger.h>
#include <amanda-vm/Runtime/Stack.h>
#include <amanda-vm/Runtime/AdaptiveOptimizationCondition.h>
#include <amanda-vm/Binutils/Symbol.h>
#include <amanda-vm/Threading/Runnable.h>

// C++
#include <deque>

namespace amanda
{
namespace vm
{

class ExecutableModule;
class Context;

/**
 * Procedure objects encapsulate the information needed by the virtual machine
 * execution engine in order to apply the adaptive optimizations (heuristics
 * that attempt to balance the cost of just in time compilation vs. the cost
 * of interpretation).
 * <p>
 *
 * @author J. Marrero
 */
class Procedure : public core::Object
{
    AMANDA_OBJECT(Procedure, core::Object)
public:

    static const int ZERO = 0;
    static const int ONE = 1;

    /**
     * Represents a set of processor flags used to control the execution of
     * a procedure within the virtual machine.
     */
    struct ProcessorFlags
    {
        vm::vm_byte_t   m_zf : 1;
    } __attribute__((packed));
    typedef struct ProcessorFlags ProcessorFlags;

    Procedure(const Context& context, const core::String& name, const binutils::Symbol::SymbolTableEntry* symbol);
    virtual ~Procedure();

    void                addOptimizationCriteria(const AdaptiveOptimizationCondition* criteria);
    virtual bool        equals(const Object* object);
    vm::vm_qword_t      execute(Stack& stack, ProcessorFlags& eflags);
    vm::vm_qword_t      executeInterpreted(Stack& stack, ProcessorFlags& eflags);
    vm::vm_qword_t      executeOptimized();
    const core::String& getName() const;
    logging::Logger&    getLoggerInstance() const;
    bool                isOptimized() const;
    const bool          isZeroFlagSet(ProcessorFlags& eflags) const;
    void                jumpToLocalAddress(const vm::vm_address_t offset) const;
    void                optimize();
    void                setExecutableModule(ExecutableModule& module);
    bool                shouldOptimize() const;

protected:

    /**
     * This is the code that optimizes (just-in-time compiles and applies
     * peephole optimizations) the procedure.
     */
    class OptimizationRunnable : public concurrent::Runnable
    {
        AMANDA_OBJECT(OptimizationRunnable, concurrent::Runnable)
    public:

        OptimizationRunnable(Procedure& procedure);

        virtual void run();

    private:

        Procedure& procedure;
    } ;

    static logging::Logger& LOGGER;

    const Context&                                      context;
    sdk_ullong_t                                        executionCount;
    core::WeakReference<ExecutableModule>               executableModule;
    mutable vm::vm_qword_t                              ip;
    core::String                                        name;
    std::deque<const AdaptiveOptimizationCondition*>    optimizationCritera;
    volatile bool                                       optimized;
    const binutils::Symbol::SymbolTableEntry*           symbol;

    vm::vm_byte_t   fetch() const;
    void            setOptimized(bool optimized);

} ;

}
}

#endif /* PROCEDURE_H */

