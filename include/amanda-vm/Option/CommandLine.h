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
 * File:   CommandLine.h
 * Author: Javier Marrero
 *
 * Created on March 1, 2022, 12:41 PM
 */

#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <amanda-vm/Object.h>
#include <amanda-vm/Interface.h>
#include <amanda-vm/Option/Option.h>

#include <amanda-vm/ADT/Array.h>

// STL
#include <list>
#include <vector>

namespace amanda
{
namespace cli
{

class CommandLine : extends core::Object
{
public:

    CommandLine();
    virtual ~CommandLine();

    void                        addArgument(const core::String& argument);
    void                        addOption(const Option* option);
    std::vector<core::String>&  getArgumentList();
    void                        getArguments(core::String arguments[], size_t size);
    std::vector<const Option*>& getOptionsList();
    void                        getOptions(const Option* options[], size_t size);
    core::String                getOptionValue(const char opt);
    core::String                getOptionValue(const core::String& opt);
    core::String                getOptionValue(const Option* option);
    adt::Array<core::String>    getOptionValues(const char opt);
    adt::Array<core::String>    getOptionValues(const core::String& opt);
    adt::Array<core::String>    getOptionValues(const Option* option);
    bool                        hasOption(const char opt);
    bool                        hasOption(const Option* opt);
    bool                        hasOption(const core::String& opt);

private:

    std::vector<core::String>     arguments;
    std::vector<const Option*>    options;

    const Option*   resolveOption(const core::String& option);
} ;

}
}

#endif /* COMMANDLINE_H */

