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
 * File:   sdk-toolchains.h
 * Author: Javier Marrero
 *
 * Created on February 24, 2022, 11:15 PM
 */

#ifndef SDK_TOOLCHAINS_H
#define SDK_TOOLCHAINS_H
#ifdef __cplusplus
extern "C"
{
#endif

#ifndef HAS_SDK_TOOLCHAINS_INCLUDED
#   define HAS_SDK_TOOLCHAINS_INCLUDED  1
#endif

/**
 * State all the supported tool-chains.
 */
#define AMANDA_ARCH_TOOLCHAIN_GCC   1
#define AMANDA_ARCH_TOOLCHAIN_CLANG 2

#if defined(__GNUC__)
#   define AMANDA_ARCH_TOOLCHAIN    AMANDA_ARCH_TOOLCHAIN_GCC
#   include <amanda-vm-c/sdk-gcc.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* SDK_TOOLCHAINS_H */

