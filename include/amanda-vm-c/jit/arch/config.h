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
 * File:   config.h
 * Author: Javier Marrero
 *
 * Created on March 28, 2022, 10:38 AM
 */

#ifndef CONFIG_H
#define CONFIG_H
#ifdef __cplusplus
extern "C"
{
#endif

#if defined(__i386) || defined(__i386__) || defined(_M_IX86)
#	include "../jit-arch-x86.h"
#elif defined(__amd64) || defined(__amd64__) || defined(_x86_64) || defined(_x86_64__)
#	include "../jit-arch-x86-64.h"
#else
#	include "../jit-arch-generic.h"
#endif

#ifdef __cplusplus
}
#endif
#endif /* CONFIG_H */

