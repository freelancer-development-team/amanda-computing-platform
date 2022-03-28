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
 * File:   sdk-version.h
 * Author: Javier Marrero
 *
 * Created on February 28, 2022, 11:48 AM
 */

#ifndef SDK_VERSION_H
#define SDK_VERSION_H
#ifdef __cplusplus
extern "C"
{
#endif

#define __private_stringify1(x) #x
#define __private_stringify(x)  __private_stringify1(x)

#define SDK_VERSION_MAJOR       0
#define SDK_VERSION_MINOR       1
#define SDK_VERSION_REVISION    2

#define SDK_FULLVERSION_STRING  __private_stringify(SDK_VERSION_MAJOR) "." \
                                __private_stringify(SDK_VERSION_MINOR) "." \
                                __private_stringify(SDK_VERSION_REVISION)
#define SDK_FULLVERSION_RC_STRING   SDK_FULLVERSION_STRING ".0\0"

#ifdef __STDC__

/**
 * This enumeration type should be preferred to the macros to get all version
 * numbers.
 */
typedef enum _SDK_VERSION_ENUMERATOR
{
    SDK_VER_MAJOR       = SDK_VERSION_MAJOR,
    SDK_VER_MINOR       = SDK_VERSION_MINOR,
    SDK_VER_REVISION    = SDK_VERSION_REVISION
} SDK_VERSION_ENUMERATOR;

#endif
#ifdef __cplusplus
}
#endif
#endif /* SDK_VERSION_H */

