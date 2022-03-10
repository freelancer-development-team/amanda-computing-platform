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
 * File:   OptionBuilder.cpp
 * Author: Javier Marrero
 * 
 * Created on March 10, 2022, 10:42 AM
 */

#include <amanda-vm/Option/OptionBuilder.h>
#include <amanda-vm/Option/Option.h>

using namespace amanda::cli;

OptionBuilder::OptionBuilder()
{
    description = "no description";
    longOption = Option::NO_OPTION;
    optionalArgument = true;
    required = false;
    shortOption = Option::NO_OPTION;
}

OptionBuilder OptionBuilder::build()
{
    return OptionBuilder();
}

Option* OptionBuilder::get() const
{
    Option* option = new Option(shortOption, longOption, description, required, !optionalArgument);
    assert(option != NULL && "could not create Option object. Possible future segmentation failure.");

    return option;
}

OptionBuilder& OptionBuilder::hasRequiredArgument(bool required)
{
    this->optionalArgument = !required;
    return *this;
}

OptionBuilder& OptionBuilder::isRequired(bool required)
{
    this->required = required;
    return *this;
}

OptionBuilder& OptionBuilder::withDescription(const core::String& description)
{
    this->description = description;
    return *this;
}

OptionBuilder& OptionBuilder::withLongOption(const core::String& longOption)
{
    this->longOption = longOption;
    return *this;
}

OptionBuilder& OptionBuilder::withShortOption(const core::String& shortOption)
{
    this->shortOption = shortOption;
    return *this;
}
