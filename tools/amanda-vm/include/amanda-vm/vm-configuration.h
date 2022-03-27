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
 * File:   vm-configuration.h
 * Author: Javier Marrero
 *
 * Created on March 26, 2022, 10:38 PM
 */

#ifndef VM_CONFIGURATION_H
#define VM_CONFIGURATION_H

#include <amanda-vm/Runtime/VMContext.h>

namespace amanda
{
namespace vm
{
namespace configuration
{

void loadVirtualMachineConfiguration(VMContext& context);

}
}
}

#endif /* VM_CONFIGURATION_H */
