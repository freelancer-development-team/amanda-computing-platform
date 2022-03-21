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
 * File:   OptionBuilder.h
 * Author: Javier Marrero
 *
 * Created on March 10, 2022, 10:42 AM
 */

#ifndef OPTIONBUILDER_H
#define OPTIONBUILDER_H

#include <amanda-vm/Option/Option.h>

namespace amanda
{
namespace cli
{

/**
 * This is an static utility class used to create options in a fluent interface
 * style.
 */
class OptionBuilder : public core::Object
{
    AMANDA_OBJECT(OptionBuilder, core::Object)

public:

    /**
     * Creates a new instance of this class, designed to create option objects.
     */
    static OptionBuilder build();

    Option*         get() const;
    OptionBuilder&  hasRequiredArgument(bool required);
    OptionBuilder&  isRequired(bool required);
    OptionBuilder&  withDescription(const core::String& description);
    OptionBuilder&  withLongOption(const core::String& longOption);
    OptionBuilder&  withShortOption(const core::String& shortOption);
    
protected:

    /**
     * The class cannot be constructed explicitly. Use the <code>build</code>
     * static method instead.
     */
    OptionBuilder();

    core::String    shortOption;
    core::String    longOption;
    core::String    argumentName;
    core::String    description;
    bool            required;
    bool            requiresArguments;
    int             argumentCount;
    char            valueSeparator;
    
} ;

}
}

#endif /* OPTIONBUILDER_H */

