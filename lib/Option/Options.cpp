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
 * File:   Options.cpp
 * Author: Javier Marrero
 * 
 * Created on February 27, 2022, 10:31 PM
 */

#include <amanda-vm/Option/Options.h>
#include <amanda-vm/ADT/Collections.h>
#include <amanda-vm-c/sdk-assert-helper.h>

using amanda::cli::Options;
using amanda::cli::Option;
using amanda::core::String;

Options::~Options()
{
    std::map<String, const Option*>::iterator iter;
    for (iter = shortOptions.begin(); iter != shortOptions.end(); ++iter)
    {
        if (iter->second)
        {
            static_cast<const Option*> (iter->second)->release();
        }
    }

    for (iter = longOptions.begin(); iter != longOptions.end(); ++iter)
    {
        if (iter->second)
        {
            static_cast<const Option*> (iter->second)->release();
        }
    }
}

Options& Options::addOption(const Option* option)
{
    assert(option != NULL
           && ASSERT_MESSAGE("Passed a NULL pointer to an Option instance."));
    option->grab(); // Increase reference counting!

    const String& key = option->getKey();
    if (option->hasLongOption())
    {
        longOptions.insert(std::make_pair(option->getLongOption(), option));
        option->grab(); // Now the object has two strong references.
    }

    shortOptions.insert(std::make_pair(key, option));
    return *this;
}

Options& Options::getMatchingOptions(const core::String& option, std::vector<core::String>& matchingOptions)
{
    String strippedOption = stripLeadingHyphens(option);
    if (adt::contains(longOptions, strippedOption))
    {
        matchingOptions.push_back(option);
    }

    std::map<String, const Option*>::iterator iter;
    for (iter = longOptions.begin(); iter != longOptions.end(); ++iter)
    {
        const String& longOption = iter->first;
        if (longOption.startsWith(option))
        {
            matchingOptions.push_back(longOption);
        }
    }

    return *this;
}

const Option* Options::getOption(const core::String& option)
{
    const Option* result = NULL;

    String strippedOption = cli::stripLeadingHyphens(option);
    if (adt::contains(shortOptions, strippedOption))
    {
        result = shortOptions[strippedOption];
    }
    else if (adt::contains(longOptions, strippedOption))
    {
        result = longOptions[strippedOption];
    }
    return result;
}

void Options::getOptions(std::list<const Option*>& list) const
{
    helpOptions(list);
}

bool Options::hasLongOption(const core::String& option)
{
    String strippedOption = cli::stripLeadingHyphens(option);
    return adt::contains(longOptions, option);
}

bool Options::hasOption(const core::String& option)
{
    String strippedOption = cli::stripLeadingHyphens(option);
    return adt::contains(longOptions, option) || adt::contains(shortOptions, option);
}

bool Options::hasShortOption(const core::String& option)
{
    String strippedOption = cli::stripLeadingHyphens(option);
    return adt::contains(shortOptions, option);
}

void Options::helpOptions(std::list<const Option*>& list) const
{
    std::map<String, const Option*>::const_iterator iter;
    for (iter = shortOptions.begin(); iter != shortOptions.end(); ++iter)
    {
        list.push_back(iter->second);
    }
}
