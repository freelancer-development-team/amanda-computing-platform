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
 * File:   Version.h
 * Author: Javier Marrero
 *
 * Created on March 10, 2022, 4:05 PM
 */

#ifndef AMANDA_C_VERSION_H
#define AMANDA_C_VERSION_H
#ifdef __cplusplus
extern "C"
{
#endif

#include <amanda-vm-c/sdk-version.h>

#define __private_stringify1(x) #x
#define __private_stringify(x)  __private_stringify1(x)

#define AMANDA_C_VERSION_MAJOR       0
#define AMANDA_C_VERSION_MINOR       18
#define AMANDA_C_VERSION_REVISION    9

#define AMANDA_C_FULLVERSION_STRING  __private_stringify(AMANDA_C_VERSION_MAJOR) "." \
                                __private_stringify(AMANDA_C_VERSION_MINOR) "." \
                                __private_stringify(AMANDA_C_VERSION_REVISION)

#ifdef __STDC__

/**
 * This enumeration type should be preferred to the macros to get all version
 * numbers.
 */
typedef enum _AMANDA_C_VERSION_ENUMERATOR
{
    AMANDA_C_VER_MAJOR       = AMANDA_C_VERSION_MAJOR,
    AMANDA_C_VER_MINOR       = AMANDA_C_VERSION_MINOR,
    AMANDA_C_VER_REVISION    = AMANDA_C_VERSION_REVISION
} AMANDA_C_VERSION_ENUMERATOR;

#endif
#ifdef __cplusplus
}
#endif
#endif /* VERSION_H */

