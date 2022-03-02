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
 * File:   CommandLineParser.h
 * Author: Javier Marrero
 *
 * Created on March 1, 2022, 1:43 PM
 */

#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include <amanda-vm/Interface.h>
#include <amanda-vm/ADT/Array.h>
#include <amanda-vm/Option/CommandLine.h>
#include <amanda-vm/Option/Options.h>

namespace amanda
{
namespace cli
{

adt::Array<core::String> makeArgumentsArray(int argc, char* argv[]);

/**
 * Implementors of this interface obtain a method to parse a string array and
 * return a command line object.
 */
class CommandLineParser : extends core::Interface
{
    AMANDA_OBJECT(CommandLineParser, core::Interface)

public:

    virtual CommandLine* parse(Options& options, adt::Array<core::String>& arguments, bool stopAtNonOption) = 0;
    
} ;

}
}

#endif /* COMMANDLINEPARSER_H */

