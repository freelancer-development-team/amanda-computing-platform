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
 * File:   AmandaVM.h
 * Author: Javier Marrero
 *
 * Created on March 25, 2022, 4:18 PM
 */

#ifndef AMANDAVM_H
#define AMANDAVM_H

// Runtime Library
#include <amanda-vm/Runtime/AdaptiveOptimizationCondition.h>
#include <amanda-vm/Runtime/Context.h>
#include <amanda-vm/Runtime/DefaultPoolAllocator.h>
#include <amanda-vm/Runtime/ExecutableModule.h>
#include <amanda-vm/Runtime/FfiException.h>
#include <amanda-vm/Runtime/FileSystem.h>
#include <amanda-vm/Runtime/IllegalInstructionException.h>
#include <amanda-vm/Runtime/IllegalStateException.h>
#include <amanda-vm/Runtime/InvalidAllocationError.h>
#include <amanda-vm/Runtime/InvalidResourceIdentifierException.h>
#include <amanda-vm/Runtime/JitContext.h>
#include <amanda-vm/Runtime/LinkageError.h>
#include <amanda-vm/Runtime/LocklessDefaultAllocator.h>
#include <amanda-vm/Runtime/MemoryAllocator.h>
#include <amanda-vm/Runtime/MemoryManager.h>
#include <amanda-vm/Runtime/MirJitContext.h>
#include <amanda-vm/Runtime/ModuleLoader.h>
#include <amanda-vm/Runtime/NativeCProcedure.h>
#include <amanda-vm/Runtime/NativeProcedure.h>
#include <amanda-vm/Runtime/NativeThreadScheduler.h>
#include <amanda-vm/Runtime/NullJitContext.h>
#include <amanda-vm/Runtime/OutOfMemoryError.h>
#include <amanda-vm/Runtime/Procedure.h>
#include <amanda-vm/Runtime/ResourceIdentifier.h>
#include <amanda-vm/Runtime/Schedulable.h>
#include <amanda-vm/Runtime/SegmentationFault.h>
#include <amanda-vm/Runtime/Stack.h>
#include <amanda-vm/Runtime/ThreadScheduler.h>
#include <amanda-vm/Runtime/UnschedulableException.h>

#include <amanda-vm/Runtime/Optimization/NullOptimizationCriteria.h>

#include <amanda-vm/Runtime/Types/Object.h>

// The Amanda Core Libraries
#include <AmandaSDK.h>

#endif /* AMANDAVM_H */

