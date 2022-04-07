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
 * File:   jit-defs.h
 * Author: Javier Marrero
 *
 * Common definitions for the JIT runtime back-end.
 *
 * Created on March 28, 2022, 10:06 AM
 */

#ifndef JIT_DEFS_H
#define JIT_DEFS_H

#include <stdint.h>
#include <stddef.h>
#include <malloc.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef _MSC_VER
#define JIT_EXPORT_DATA extern __declspec(dllimport)
#else
#define JIT_EXPORT_DATA extern
#endif

///TODO: Move this to an architecture dependent library.
typedef int8_t jit_sbyte;
typedef uint8_t jit_ubyte;
typedef int16_t jit_short;
typedef uint16_t jit_ushort;
typedef int32_t jit_int;
typedef uint32_t jit_uint;
typedef intptr_t jit_nint;
typedef uintptr_t jit_nuint;

typedef int64_t jit_long;
typedef uint64_t jit_ulong;

typedef float jit_float32;
typedef double jit_float64;
typedef long double jit_nfloat;
typedef void *jit_ptr;

#define JIT_NATIVE_INT32 1

#if defined(__cplusplus) && defined(__GNUC__)
#define JIT_NOTHROW  throw()
#else
#define JIT_NOTHROW
#endif

#define jit_min_int  (((jit_int)1) << (sizeof(jit_int) * 8 - 1))
#define jit_max_int  ((jit_int)(~jit_min_int))
#define jit_max_uint ((jit_uint)(~((jit_uint)0)))
#define jit_min_long (((jit_long)1) << (sizeof(jit_long) * 8 - 1))
#define jit_max_long ((jit_long)(~jit_min_long))
#define jit_max_ulong ((jit_ulong)(~((jit_ulong)0)))

typedef size_t jit_size_t;

#ifdef __cplusplus
}
#endif
#endif /* JIT_DEFS_H */

