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
 * File:   vm-initialization.h
 * Author: Javier Marrero
 *
 * Created on March 26, 2022, 3:52 PM
 */

#ifndef VM_INITIALIZATION_H
#define VM_INITIALIZATION_H

#include <amanda-vm/Option/package.hxx>
#include <amanda-vm/ADT/Array.h>

namespace amanda
{
namespace vm
{

cli::CommandLine*   parseCommandLineArguments(adt::Array<core::String>& args, cli::Options& options);
void                printFormattedHelpMessage(cli::Options& options);
void                printVersionInformation();

}
}

#endif /* VM_INITIALIZATION_H */
