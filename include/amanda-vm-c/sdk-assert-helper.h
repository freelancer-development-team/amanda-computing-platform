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
 * File:   sdk-assert-helper.h
 * Author: Javier Marrero
 *
 * Created on February 26, 2022, 9:26 AM
 */

#ifndef SDK_ASSERT_HELPER_H
#define SDK_ASSERT_HELPER_H
#ifdef __cplusplus
extern "C"
{
#endif

#include <assert.h>

#define ASSERT_MESSAGE(message) __FILE__ ": " message

#ifdef __cplusplus
}
#endif
#endif /* SDK_ASSERT_HELPER_H */

