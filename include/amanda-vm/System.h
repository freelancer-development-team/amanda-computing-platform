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
 * File:   System.h
 * Author: Javier Marrero
 *
 * Created on April 16, 2022, 6:07 PM
 */

#ifndef _AMANDA_SYSTEM_H
#define _AMANDA_SYSTEM_H

#include <amanda-vm-c/sdk-types.h>

namespace amanda
{
namespace core
{

/**
 * Returns the number of logical processors available to the process.
 * 
 * @return an unsigned long long with the count of available cores.
 */
sdk_ullong_t getNumberOfAvailableCores();

}
}

#endif /* SYSTEM_H */

