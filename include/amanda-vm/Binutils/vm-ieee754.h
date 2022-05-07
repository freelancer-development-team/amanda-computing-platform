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
 * File:   IEEE754.h
 * Author: Javier Marrero
 *
 * Created on March 25, 2022, 4:00 PM
 */

#ifndef _FLOATING_POINT_IEEE754_H
#define _FLOATING_POINT_IEEE754_H
#ifndef VIRTUALMACHINESPECS_H
#   error "This file should not be stand-alone included. Include <vm-types.h> first."
#endif

#include <float.h>
#include <amanda-vm-c/sdk-configuration.h>

#if defined(__i386__) || defined(__x86_64) && defined(__GNUC__)

typedef float vm_float32_t;
typedef double vm_float64_t;

#else
#   warning "no simple precission 32b floating point and no double precission 64b floating point detected. using software emulated fp instead."
#endif

#define VM_FLOAT32_SIZE     4
#define VM_FLOAT64_SIZE     8

#endif /* IEEE754_H */

