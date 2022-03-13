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
 * File:   sdk-configuration.h
 * Author: Javier Marrero
 *
 * Created on March 13, 2022, 12:53 AM
 */

#ifndef SDK_CONFIGURATION_H
#define SDK_CONFIGURATION_H
#ifdef __cplusplus
extern "C"
{
#endif

#include <amanda-vm-c/sdk-definitions.h>
#include <amanda-vm-c/sdk-toolchains.h>

/// Build flags
#define SDK_BUILD_USE_FLAG      1
#define SDK_BUILD_NO_USE_FLAG   0

/// This must be set to 1 when using POSIX threads
#ifndef SDK_BUILD_USING_PTHREADS
#ifdef _W32
#   if AMANDA_ARCH_TOOLCHAIN == AMANDA_ARCH_TOOLCHAIN_GCC
#       define SDK_BUILD_USING_PTHREADS SDK_BUILD_USE_FLAG          // Using POSIX threads
#   else
#       define SDK_BUILD_USING_PTHREADS SDK_BUILD_NO_USE_FLAG       // Not using POSIX threads
#   endif
#else
#   define SDK_BUILD_USING_PTHREADS SDK_BUILD_USE_FLAG              // Using POSIX threads
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif /* SDK_CONFIGURATION_H */

