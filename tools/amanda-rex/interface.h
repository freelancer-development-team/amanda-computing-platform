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
 * File:   interface.h
 * Author: Javier Marrero
 *
 * Created on April 17, 2022, 12:29 PM
 */

#ifndef AMANDA_READEX_INTERFACE_H
#define AMANDA_READEX_INTERFACE_H

#include <AmandaSDK.h>
#include <amanda-vm/Option/package.hxx>

namespace amanda
{
namespace rdx
{

void buildOptionsObject(cli::Options& options);
void displayFormattedHelp(const cli::Options& options);
void displayObjectFileInformation(const core::String& fileName);
void displayVersionInfo();

}
}

#endif /* INTERFACE_H */

