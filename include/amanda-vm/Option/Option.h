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
 * File:   Option.h
 * Author: Javier Marrero
 *
 * Created on February 26, 2022, 3:02 PM
 */

#ifndef OPTION_H
#define OPTION_H

#include <amanda-vm/Object.h>
#include <amanda-vm/String.h>

#include <vector>
#include <list>

namespace amanda
{
namespace cli
{

core::String stripLeadingAndTrailingQuotes(const core::String& str);
core::String stripLeadingHyphens(const core::String& str);

/**
 * This class represents a command line option.
 */
class Option : public core::Object
{
    AMANDA_OBJECT(Option, core::Object)

public:

    static const int            UNINITIALIZED = -1;
    static const int            UNLIMITED_VALUES = -2;
    static const core::String&  NO_OPTION;

    Option(const core::String& option, const core::String& longOption,
           const core::String& description, bool required, bool hasArguments);
    ~Option();

    bool                acceptsArguments() const;
    void                addValueForProcessing(const core::String& value);
    void                clear();
    const core::String& getArgumentName() const;
    int                 getArguments() const;
    const core::String& getDescription() const;
    int                 getId() const;
    const core::String& getKey() const;
    const core::String& getLongOption() const;
    const core::String& getOption() const;
    void                getValuesList(std::vector<core::String>& list) const;
    char                getValueSeparator() const;
    bool                hasArgument() const;
    bool                hasArguments() const;
    bool                hasLongOption() const;
    bool                hasNoValues() const;
    bool                hasOptionalArg() const;
    bool                hasShortOption() const;
    bool                hasValueSeparator() const;
    bool                isRequired() const;
    bool                requiresArgument() const;
    void                setArgumentName(const core::String& argumentName);
    void                setArgumentCount(const int count);
    void                setDescription(const core::String& description);
    void                setValueSeparator(const char separator);
    
    virtual core::String toString() const;

private:

    const core::String  option;
    core::String        longOption;
    core::String        argumentName;
    core::String        description;
    bool                required;
    bool                optionalArgument;
    int                 argumentCount;
    char                valueSeparator;

    std::vector<core::String> values;

    void                add(const core::String& value);
    void                processValue(core::String& value);

} ;

}
}

#endif /* OPTION_H */

