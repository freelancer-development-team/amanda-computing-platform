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
 * File:   CommandLine.cpp
 * Author: Javier Marrero
 * 
 * Created on March 1, 2022, 12:42 PM
 */

#include <amanda-vm/Option/CommandLine.h>
#include <amanda-vm/ADT/Iterators.h>
#include <amanda-vm/ADT/Collections.h>

using amanda::cli::CommandLine;
using amanda::cli::Option;
using amanda::core::String;

CommandLine::CommandLine()
{
}

CommandLine::~CommandLine()
{
    std::list<const Option*>::iterator iter;
    for (iter = options.begin(); iter != options.end(); ++iter)
    {
        const Option* option = *iter;
        option->release(); // Release the previously grabbed reference.
    }
}

void CommandLine::addArgument(const core::String& argument)
{
    arguments.push_back(argument);
}

void CommandLine::addOption(const Option* option)
{
    // Increases the reference counter as this grabs a reference.
    option->grab();
    options.push_back(option);
}

std::list<String>& CommandLine::getArgumentList()
{
    return arguments;
}

void CommandLine::getArguments(core::String arguments[], size_t size)
{
    size_t i = 0;

    std::list<String>::iterator iter;
    for (iter = this->arguments.begin();
         iter != this->arguments.end() && (i < size); ++iter)
    {
        arguments[i++] = *iter;
    }
}

std::list<const Option*>& CommandLine::getOptionsList()
{
    return options;
}

void CommandLine::getOptions(const Option* options[], size_t size)
{
    size_t i = 0;

    STL_ITERATOR(list, const Option*, iter);
    for (iter = adt::begin(this->options);
         iter != adt::end(this->options) && (i < size); ++iter)
    {
        options[i++] = *iter;
    }
}

bool CommandLine::hasOption(const char opt)
{
    return hasOption(String(opt));
}

bool CommandLine::hasOption(const Option* opt)
{
    return adt::contains(options, opt);
}

bool CommandLine::hasOption(const core::String& opt)
{
    return hasOption(resolveOption(opt));
}

const Option* CommandLine::resolveOption(const core::String& option)
{
    const Option* result = NULL;
    String opt = cli::stripLeadingHyphens(option);

    for (std::list<const Option*>::const_iterator iter = options.begin();
         iter != options.end() && result == NULL; ++iter)
    {
        const Option* optionObject = *iter;
        assert(optionObject != NULL && "Got a null option object.");

        if (opt.equals(optionObject->getOption()) || opt.equals(optionObject->getLongOption()))
        {
            result = optionObject;
        }
    }

    return result;
}
