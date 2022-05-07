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
 * File:   sdk-jit-engine.h
 * Author: Javier Marrero
 *
 * Created on March 28, 2022, 7:14 PM
 */

#ifndef SDK_JIT_ENGINE_H
#define SDK_JIT_ENGINE_H
#ifdef __cplusplus
extern "C"
{
#endif

// Include the configuration header
#include "sdk-configuration.h"

#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif

#include <stdint.h>
#include <limits.h>

/* Limits for the JIT engine */
#if defined(__cplusplus) && defined(__STDC_CONSTANT_MACROS)

/* 7.18.2.1  Limits of exact-width integer types */
#define INT8_MIN (-128)
#define INT16_MIN (-32768)
#define INT32_MIN (-2147483647 - 1)
#define INT64_MIN  (-9223372036854775807LL - 1)

#define INT8_MAX 127
#define INT16_MAX 32767
#define INT32_MAX 2147483647
#define INT64_MAX 9223372036854775807LL

#define UINT8_MAX 255
#define UINT16_MAX 65535
#define UINT32_MAX 0xffffffffU  /* 4294967295U */
#define UINT64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

/* 7.18.2.4  Limits of integer types capable of holding
object pointers */
#ifdef _WIN64
#define INTPTR_MIN INT64_MIN
#define INTPTR_MAX INT64_MAX
#define UINTPTR_MAX UINT64_MAX
#else
#define INTPTR_MIN INT32_MIN
#define INTPTR_MAX INT32_MAX
#define UINTPTR_MAX UINT32_MAX
#endif

#endif

/* Include the JIT engine */
#if SDK_BUILD_USING_MIR_JIT
#   include "../../third-party/mir/mir.h"
#else
#   error   "I need a JIT engine :("
#endif

#ifdef __cplusplus
}
#endif
#endif /* SDK_JIT_ENGINE_H */

