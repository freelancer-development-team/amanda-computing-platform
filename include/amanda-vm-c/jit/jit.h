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
 * File:   jit.h
 * Author: Javier Marrero
 *
 * Created on March 28, 2022, 10:07 AM
 */

#ifndef JIT_H
#define JIT_H
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * This file is a meta-include that eases the use of the JIT library. The JIT
 * library is programmed in pure C due to its inheritance of the GNU 'libjit'
 * code base.
 */
#include <amanda-vm-c/jit/jit-apply.h>
#include <amanda-vm-c/jit/jit-block.h>
#include <amanda-vm-c/jit/jit-common.h>
#include <amanda-vm-c/jit/jit-context.h>
#include <amanda-vm-c/jit/jit-debugger.h>
#include <amanda-vm-c/jit/jit-defs.h>
#include <amanda-vm-c/jit/jit-elf.h>
#include <amanda-vm-c/jit/jit-except.h>
#include <amanda-vm-c/jit/jit-function.h>
#include <amanda-vm-c/jit/jit-init.h>
#include <amanda-vm-c/jit/jit-insn.h>
#include <amanda-vm-c/jit/jit-intrinsic.h>
#include <amanda-vm-c/jit/jit-memory.h>
#include <amanda-vm-c/jit/jit-meta.h>
#include <amanda-vm-c/jit/jit-objmodel.h>
#include <amanda-vm-c/jit/jit-opcode.h>
#include <amanda-vm-c/jit/jit-type.h>
#include <amanda-vm-c/jit/jit-unwind.h>
#include <amanda-vm-c/jit/jit-util.h>
#include <amanda-vm-c/jit/jit-value.h>
#include <amanda-vm-c/jit/jit-vmem.h>
#include <amanda-vm-c/jit/jit-walk.h>

#ifdef __cplusplus
}
#endif
#endif /* JIT_H */

