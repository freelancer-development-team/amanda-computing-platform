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
 * File:   Option.cpp
 * Author: Javier Marrero
 * 
 * Created on February 26, 2022, 3:02 PM
 */

#include <amanda-vm/Option/Option.h>

#include <amanda-vm/Types.h>
#include <amanda-vm-c/sdk-assert-helper.h>

using amanda::cli::Option;

using amanda::core::String;

const String& Option::NO_OPTION = String::EMPTY;

Option::Option(const core::String& option, const core::String& longOption,
               const core::String& description,
               bool required, bool hasArguments)
:
option(option),
longOption(longOption),
description(description),
required(required),
argumentCount(UNINITIALIZED)
{
    if (hasArguments)
    {
        this->argumentCount = 1;
    }
}

Option::~Option()
{
}

bool Option::acceptsArguments() const
{
    return (hasArgument() ||
            hasArguments() ||
            hasOptionalArg()) &&
            (argumentCount <= 0 || (int) values.size() < argumentCount);
}

void Option::addValueForProcessing(const core::String& value)
{
    assert(argumentCount != UNINITIALIZED
           && ASSERT_MESSAGE("NO_ARGS_ALLOWED"));
    processValue(amanda::eliminateConstness(value));
}

void Option::clear()
{
    values.clear();
}

const String& Option::getArgumentName() const
{
    return argumentName;
}

int Option::getArguments() const
{
    return argumentCount;
}

const String& Option::getDescription() const
{
    return description;
}

int Option::getId() const
{
    return getKey().charAt(0);
}

const String& Option::getKey() const
{
    return (option.isEmpty()) ? longOption : option;
}

const String& Option::getLongOption() const
{
    return longOption;
}

const String& Option::getOption() const
{
    return option;
}

char Option::getValueSeparator() const
{
    return valueSeparator;
}

bool Option::hasArgument() const
{
    return (argumentCount > 0) || (argumentCount == UNLIMITED_VALUES);
}

bool Option::hasArguments() const
{
    return (argumentCount > 1) || (argumentCount == UNLIMITED_VALUES);
}

bool Option::hasLongOption() const
{
    return !longOption.isEmpty();
}

bool Option::hasNoValues() const
{
    return values.empty();
}

bool Option::hasOptionalArg() const
{
    return optionalArgument;
}

bool Option::hasShortOption() const
{
    return !option.isEmpty();
}

bool Option::hasValueSeparator() const
{
    return valueSeparator > 0;
}

bool Option::isRequired() const
{
    return required;
}

bool Option::requiresArgument() const
{
    bool result = acceptsArguments();
    if (optionalArgument)
    {
        result = false;
    }
    else if (argumentCount == UNLIMITED_VALUES)
    {
        result = values.empty();
    }
    return result;
}

void Option::setArgumentName(const core::String& argumentName)
{
    this->argumentName = argumentName;
}

void Option::setArgumentCount(const int count)
{
    this->argumentCount = count;
}

void Option::setDescription(const core::String& description)
{
    this->description = description;
}

void Option::setValueSeparator(const char separator)
{
    this->valueSeparator = separator;
}

String Option::toString()
{
    String result("[ option: ");
    result.append(option);

    if (!longOption.isEmpty())
    {
        result.appendWithFormat(" %s", longOption.toCharArray());
    }

    result.append(" ]");
    return result;
}

void Option::add(const core::String& value)
{
    if (acceptsArguments())
    {
        values.push_back(value);
    }
}

void Option::processValue(core::String& value)
{
    if (hasValueSeparator())
    {
        const char separator = getValueSeparator();
        unsigned index = value.find(separator);

        while (index != String::NPOS
               && ((int) values.size() == (argumentCount - 1)))
        {
            value = value.substring(index + 1);
            index = value.find(separator);
        }
    }

    // Store the last value of the actual value being parsed
}
