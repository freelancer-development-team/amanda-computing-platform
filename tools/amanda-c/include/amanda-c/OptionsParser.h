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
 * File:   Options.h
 * Author: Javier Marrero
 *
 * Created on March 10, 2022, 9:15 AM
 */

#ifndef AMANDA_C_OPTIONS_H
#define AMANDA_C_OPTIONS_H

#include <amanda-vm/ADT/Array.h>
#include <amanda-vm/Option/package.hxx>

namespace amanda
{
namespace compiler
{

cli::CommandLine*   parseCommandLineArguments(adt::Array<core::String>& args, cli::Options* options);
void                displayHelpMessage(cli::Options& options);

}
}

#endif /* OPTIONS_H */

