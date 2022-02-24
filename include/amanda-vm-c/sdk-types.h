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
 * File:   sdk-types.h
 * Author: Javier Marrero
 *
 * Created on February 13, 2022, 2:14 PM
 */

#ifndef SDK_TYPES_H
#define SDK_TYPES_H
#ifdef __cplusplus
extern "C"
{
#endif


/* C */
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/* Alias for the standard C types. */
typedef bool            sdk_bool_t;

typedef char            sdk_char_t;
typedef short           sdk_short_t;
typedef int             sdk_int_t;
typedef long            sdk_long_t;

#ifdef __cplusplus
typedef long long       sdk_llong_t;
#else
typedef int64_t         sdk_llong_t;
#endif

typedef unsigned char   sdk_uchar_t;
typedef unsigned short  sdk_ushort_t;
typedef unsigned int    sdk_uint_t;
typedef unsigned long   sdk_ulong_t;

#ifdef __cplusplus
typedef unsigned long long  sdk_ullong_t;
#else
typedef uint64_t            sdk_ullong_t;
#endif

/* String & UNICODE character types */
typedef char*           sdk_cstring_t;

typedef int8_t          sdk_utf7_char_t;
typedef uint8_t         sdk_utf8_char_t;
typedef uint16_t        sdk_utf16_char_t;
typedef uint32_t        sdk_utf32_char_t;
typedef uint32_t        sdk_unicode_codepoint_t;

typedef sdk_utf8_char_t*    sdk_utf8_str_t;
typedef sdk_utf16_char_t*   sdk_utf16_str_t;
typedef sdk_utf32_char_t*   sdk_utf32_str_t;

#ifdef __cplusplus
}
#endif
#endif /* SDK_TYPES_H */

