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
 * File:   HelpFormatter.cpp
 * Author: Javier Marrero
 * 
 * Created on February 26, 2022, 3:14 PM
 */

#include <amanda-vm/Option/HelpFormatter.h>
#include <amanda-vm/Types.h>
#include <amanda-vm-c/sdk-assert-helper.h>

#include <list>
#include <cctype>

using amanda::cli::HelpFormatter;
using amanda::core::String;

const String HelpFormatter::DEFAULT_SYNTAX_PREFIX = "usage: ";
const String HelpFormatter::DEFAULT_OPT_PREFIX = "-";
const String HelpFormatter::DEFAULT_LONG_OPT_PREFIX = "--";
const String HelpFormatter::DEFAULT_LONG_OPT_SEPARATOR = " ";
const String HelpFormatter::DEFAULT_ARG_NAME = "arg";

void HelpFormatter::printHelp(const unsigned width, const core::String& cmdLineSyntax,
                              const core::String& header, const Options& options,
                              const core::String& footer, const bool autoUsage,
                              const io::PrintStream& stream,
                              const unsigned descPad,
                              const unsigned leftPad) const
{
    assert(cmdLineSyntax.isEmpty() == false
           && ASSERT_MESSAGE("cmdLineSyntax not provided."));

    if (autoUsage)
    {
        printUsage(stream, width, cmdLineSyntax, options);
    }
    else
    {
        printUsage(stream, width, cmdLineSyntax);
    }

    if (!header.isEmpty())
    {
        printWrapped(stream, width, header);
    }

    printOptions(stream, width, options, leftPad, descPad);

    if (!footer.isEmpty())
    {
        printWrapped(stream, width, footer);
    }
}

void HelpFormatter::printOptions(const io::PrintStream& stream, const unsigned width,
                                 const Options& options, const unsigned leftPad,
                                 const unsigned descPad) const
{
    String buffer;
    renderOptions(buffer, width, options, leftPad, descPad);
    stream.println(buffer);
}

void HelpFormatter::printUsage(const io::PrintStream& stream, const unsigned width, const String& cmdLineSyntax) const
{
    const unsigned argumentPosition = cmdLineSyntax.find(' ') + 1;
    printWrapped(stream, width, DEFAULT_SYNTAX_PREFIX + cmdLineSyntax, DEFAULT_SYNTAX_PREFIX.length() + argumentPosition);
}

void HelpFormatter::printUsage(const io::PrintStream& stream, const unsigned width,
                               const core::String& app, const Options& options) const
{
    String buff("usage: ");
    buff.append(app).append(" ");

    std::list<const Option*> optionList;
    options.getOptions(optionList);

    std::list<const Option*>::iterator iter = optionList.begin();
    while (iter != optionList.end())
    {
        const Option* option = *iter;
        if (option)
        {
            appendOption(buff, *option, option->isRequired());
        }

        if (++iter != optionList.end())
        {
            buff.append(" ");
        }
    }

    printWrapped(stream, width, buff, buff.find(' ') + 1);
}

void HelpFormatter::printWrapped(const io::PrintStream& stream, const unsigned width,
                                 const core::String& text, const unsigned nextLineTabStop) const
{
    String sb;
    renderWrappedTextBlock(sb, width, nextLineTabStop, text);

    stream.println(sb);
}

String HelpFormatter::createPadding(const unsigned int length) const
{
    char padding[length + 1] = {0};
#if 0
    for (unsigned int i = 0; i < length; i++)
    {
        padding[i] = ' ';
    }
#endif
    amanda::fill(padding, ' ', length);

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

String& HelpFormatter::renderOptions(core::String& sb, const unsigned width,
                                     const Options& options, const unsigned leftPad,
                                     const unsigned descPad) const
{
    const String lpad = createPadding(leftPad);
    const String dpad = createPadding(descPad);

    unsigned max = 0;
    std::list<String> prefixList;
    std::list<const Option*> optionList;

    options.helpOptions(optionList);

    // TODO: Sort the list of options.

    for (std::list<const Option*>::iterator iter = optionList.begin();
         iter != optionList.end(); ++iter)
    {
        const Option* option = *iter;
        if (!option) continue;

        String optionBuffer;
        if (option->getOption() == Option::NO_OPTION)
        {
            optionBuffer.append(lpad).append("   ").append(DEFAULT_LONG_OPT_PREFIX).append(option->getLongOption());
        }
        else
        {
            optionBuffer.append(lpad).append(DEFAULT_OPT_PREFIX).append(option->getOption());

        }

        if (option->hasArgument())
        {
            String argumentName = option->getArgumentName();
            if (argumentName == String::EMPTY)
            {
                optionBuffer.append(' ');
            }
            else
            {
                optionBuffer.append(option->hasLongOption() ? DEFAULT_LONG_OPT_SEPARATOR : " ");
                optionBuffer.append('<').append(argumentName.isEmpty() ? option->getArgumentName() : DEFAULT_ARG_NAME).append('>');
            }
        }

        prefixList.push_back(optionBuffer);
        max = optionBuffer.length() > max ? optionBuffer.length() : max;
    }

    std::list<const Option*>::iterator iter = optionList.begin();
    while (iter != optionList.end())
    {
        const Option* option = *iter;
        if (!option) continue;

        String optionBuffer = prefixList.front();
        prefixList.pop_front();

        if (optionBuffer.length() < max)
        {
            optionBuffer.append(createPadding(max - optionBuffer.length()));
        }
        optionBuffer.append(dpad);

        unsigned nextLineTabStop = max + descPad;
        if (option->getDescription() != String::EMPTY)
        {
            optionBuffer.append(option->getDescription());
        }

        renderWrappedText(sb, width, nextLineTabStop, optionBuffer);

        if (++iter != optionList.end())
        {
            sb.append('\n');
        }
    }

    return sb;
}

String& HelpFormatter::renderWrappedText(core::String& sb, const unsigned width,
                                         unsigned nextTabLineStop, core::String& text) const
{
    unsigned pos = findWrapPosition(text, width, 0);

    if (pos == String::NPOS)
    {
        sb.append(rtrim(text));
    }
    else
    {
        sb.append(text.substring(0, pos).trimmed()).append('\n');

        if (nextTabLineStop >= width)
        {
            nextTabLineStop = 1;
        }

        String padding = createPadding(nextTabLineStop);
        while (pos != String::NPOS)
        {
            text = padding + text.substring(pos).trimmed();
            pos = findWrapPosition(text, width, 0);

            if (pos == String::NPOS)
            {
                sb.append(text);
            }
            else
            {
                if (text.length() > width && (pos == nextTabLineStop - 1))
                {
                    pos = width;
                }
                sb.append(rtrim(text.substring(0, pos))).append('\n');
            }
        }
    }
    return sb;
}

String HelpFormatter::rtrim(const core::String& s) const
{
    String result;
    if (s.isEmpty())
    {
        result = s;
    }
    else
    {
        unsigned pos = s.length();
        while (pos > 0 && isspace(s.charAt(pos - 1)))
        {
            --pos;
        }

        result = s.substring(0, pos);
    }
    return result;
}

void HelpFormatter::appendOption(core::String& buffer, const Option& option, bool required) const
{
    if (!required)
    {
        buffer.append("[");
    }

    if (option.getOption() != Option::NO_OPTION)
    {
        buffer.append("-").append(option.getOption());
    }
    else
    {
        buffer.append("--").append(option.getLongOption());
    }

    if (option.hasArgument() && (option.getArgumentName() == String::EMPTY ||
                                 !option.getArgumentName().isEmpty()))
    {
        buffer.append(option.getOption() == Option::NO_OPTION ? DEFAULT_LONG_OPT_SEPARATOR : " ");
        buffer.append("<").append(option.getArgumentName() != String::EMPTY ? option.getArgumentName() : DEFAULT_ARG_NAME).append(">");
    }

    if (!required)
    {
        buffer.append("]");
    }
}

String& HelpFormatter::renderWrappedTextBlock(core::String& buffer, const unsigned width,
                                              const unsigned nextLineTabStop, const core::String& text) const
{
    unsigned start = 0;
    unsigned end = text.find('\n') != String::NPOS ? text.find('\n') : text.length();
    bool firstLine = true;
    String line(text.substring(start, end - start));

    while (end != String::NPOS)
    {
        if (!firstLine)
        {
            buffer.append(line);
        }
        else
        {
            firstLine = false;
        }
        renderWrappedText(buffer, width, nextLineTabStop, eliminateConstness(text));

        // Update the markers. At this point we should be iterating over all
        // the lines of text.
        start = end + 1;
        end = text.find('\n');

        if (end != String::NPOS)
        {
            line = text.substring(start, end);
        }
    }

    return buffer;
}
