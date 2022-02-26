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
 * File:   HelpFormatter.cpp
 * Author: Javier Marrero
 * 
 * Created on February 26, 2022, 3:14 PM
 */

#include <amanda-vm/Option/HelpFormatter.h>

#include <amanda-vm-c/sdk-assert-helper.h>

using amanda::cli::HelpFormatter;
using amanda::core::String;

const String HelpFormatter::DEFAULT_SYNTAX_PREFIX = "usage: ";
const String HelpFormatter::DEFAULT_OPT_PREFIX = "-";
const String HelpFormatter::DEFAULT_LONG_OPT_PREFIX = "--";
const String HelpFormatter::DEFAULT_LONG_OPT_SEPARATOR = " ";
const String HelpFormatter::DEFAULT_ARG_NAME = "arg";

void HelpFormatter::printHelp(const unsigned width, const core::String& cmdLineSyntax,
                              const core::String& header, const void* options,
                              const core::String& footer, const bool autoUsage,
                              const io::PrintStream& stream,
                              const unsigned descPad,
                              const unsigned leftPad) const
{
    assert(cmdLineSyntax.isEmpty() == false
           && ASSERT_MESSAGE("cmdLineSyntax not provided."));

    if (autoUsage)
    {
        
    }
    else
    {
        
    }

    if (!header.isEmpty())
    {
        
    }

    if (!footer.isEmpty())
    {
        
    }
}

String HelpFormatter::createPadding(const unsigned int length) const
{
    char padding[length + 1] = {0};
    for (unsigned int i = 0; i < length; i++)
    {
        padding[i] = ' ';
    }

    return String(padding);
}

unsigned int HelpFormatter::findWrapPosition(const core::String& text, const unsigned int width, const unsigned int startPosition) const
{
    unsigned int result = -1;

    unsigned int pos = text.find('\n', startPosition);
    if (pos == String::NPOS && pos <= width)
    {
        result = pos + 1;
    }
    else
    {
        pos = text.find('\t', startPosition);
        if (pos == String::NPOS && pos <= width)
        {
            result = pos + 1;
        }
        else if (startPosition + width >= text.length())
        {
            result = -1;
        }
        else
        {
            char c = -1;
            for (pos = startPosition + width; pos >= startPosition && !isspace(c); --pos)
            {
                c = text.charAt(pos);
            }

            if (pos > startPosition)
            {
                result = pos;
            }
            else
            {
                pos = startPosition + width;
            }

            result = (pos == text.length()) ? String::NPOS : pos;
        }
    }
    return result;
}

void HelpFormatter::appendOption(core::String& buffer, const Option& option, bool required) const
{
    if (!required)
    {
        buffer.append("[");
    }

    if (!required)
    {
        buffer.append("]");
    }
}
