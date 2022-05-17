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
 * File:   sdk-definitions.h
 * Author: Javier Marrero
 *
 * Created on February 10, 2022, 10:15 AM
 */

#ifndef SDK_DEFINITIONS_H
#define SDK_DEFINITIONS_H
#ifdef __cplusplus
extern "C"
{
#endif

/* Windows should be referred by this macro instead of _WIN32.
 * The Free Software Foundation doesn't like it and me neither.
 */
#ifdef _WIN32
#define _W32 1
#endif

// Different architecture macros
#define ARCH_i386   0
#define ARCH_AMD64  1
#define ARCH_PPC    2
#define ARCH_ARM    3
#define ARCH_RASBPI 4

// Architecture detection macros
#if defined(__x86__) || defined(__i386)
#define  SDK_CPU_ARCHITECTURE    ARCH_i386
#elif defined(__x86_64) || defined(__x86_64__)
#define  SDK_CPU_ARCHITECTURE    ARCH_AMD64
#else
#error "Unsupported or unknown architecture."
#endif

#ifdef __cplusplus
}
#endif
#endif /* SDK_DEFINITIONS_H */

