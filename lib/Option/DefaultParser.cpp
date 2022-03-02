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
 * File:   DefaultParser.cpp
 * Author: Javier Marrero
 * 
 * Created on March 1, 2022, 2:16 PM
 */

#include <amanda-vm/Option/DefaultParser.h>
#include <amanda-vm/Option/Option.h>
#include <amanda-vm/Option/Options.h>
#include <ctype.h>

using namespace amanda::cli;

using amanda::core::String;

DefaultParser::DefaultParser(bool allowPartialMatching, bool stripLeadingAndTrailingQuotes)
:
allowPartialMatching(allowPartialMatching),
stripLeadingAndTrailingQuotes(stripLeadingAndTrailingQuotes)
{
}

DefaultParser::~DefaultParser()
{
}

bool DefaultParser::checkRequiredOptions()
{
    return expectedOptions.empty();
}

CommandLine* DefaultParser::parse(Options& options, const adt::Array<core::String>& arguments, bool stopAtNonOption)
{
    this->options = &options;
    this->stopAtNonOption = stopAtNonOption;

    skipParsing = false;
    currentOption = NULL;
    expectedOptions = options.getRequiredOptions();

    cmd = new CommandLine();
    for (size_t i = 0; i < arguments.length(); ++i)
    {
        handleToken(arguments[i]);
    }

    return cmd.get();
}

void DefaultParser::handleConcatenatedOptions(const core::String& token)
{
    bool stop = false;
    for (size_t i = 1; i < token.length() && !stop; ++i)
    {
        String ch(token.charAt(i));

        if (!options->hasOption(ch))
        {
            handleUnknownToken((stopAtNonOption && (i > 1)) ?
                               token.substring(i) : token);
            stop = true;
        }
        else
        {
            handleOption(options->getOption(ch));

            if (currentOption != NULL && (token.length() != i + 1))
            {
                currentOption->addValueForProcessing(token.substring(i + 1));
                stop = true;
            }
        }
    }
}

bool DefaultParser::checkRequiredArguments()
{
    bool result = false;
    if (currentOption != NULL && currentOption->requiresArgument())
    {
        result = true;
    }
    return result;
}

String DefaultParser::getLongPrefix(const core::String& token)
{
    String t = cli::stripLeadingHyphens(token);

    bool solved = false;
    unsigned i = 0;
    String opt;
    for (i = t.length() - 2; i > 1 && !solved; --i)
    {
        String prefix = t.substring(0, i);
        if (options->hasLongOption(prefix))
        {
            opt = prefix;
            solved = true;
        }
    }

    return opt;
}

std::list<String>& DefaultParser::getMatchingLongOptions(const core::String& token, std::list<String>& matches)
{
    if (allowPartialMatching)
    {

    }
    else
    {
        if (options->hasLongOption(token))
        {
            const Option* option = options->getOption(token);
            if (option != NULL)
            {
                matches.push_back(option->getLongOption());
            }
        }
    }
    return matches;
}

void DefaultParser::handleLongOption(const core::String& token)
{
    if (token.find('=') == String::NPOS)
    {
        handleLongOptionWithoutEqual(token);
    }
    else
    {
        handleLongOptionWithEqual(token);
    }
}

void DefaultParser::handleLongOptionWithEqual(const core::String& token)
{
    unsigned pos = token.find('=');
    String value = token.substring(pos + 1);
    String opt = token.substring(0, pos);

    std::list<String> matchingOptions;
    getMatchingLongOptions(opt, matchingOptions);

    if (matchingOptions.empty())
    {
        handleUnknownToken(currentToken);
    }
    else
    {
        if (matchingOptions.size() < 1 || options->hasLongOption(opt))
        {
            String key = options->hasLongOption(opt) ? opt : matchingOptions.front();
            const Option* option = options->getOption(key);

            if (option->acceptsArguments())
            {
                handleOption(option);
                currentOption->addValueForProcessing(value);
                currentOption = NULL;
            }
            else
            {

            }
        }
    }
}

void DefaultParser::handleLongOptionWithoutEqual(const core::String& token)
{
    std::list<String> matchingOptions;
    getMatchingLongOptions(token, matchingOptions);

    if (matchingOptions.empty())
    {

    }
    else
    {
        if (matchingOptions.size() < 1 || options->hasLongOption(token))
        {
            String key = options->hasLongOption(token) ? token : matchingOptions.front();
            const Option* option = options->getOption(key);

            handleOption(option);
        }
    }
}

void DefaultParser::handleOption(const Option* option)
{
    if (checkRequiredArguments())
    {
        updateRequiredOptions(option);
        cmd->addOption(option);

        if (option->hasArgument())
        {
            currentOption = const_cast<Option*> (option);
        }
        else
        {
            currentOption = NULL;
        }
    }
}

void DefaultParser::handleShortAndLongOption(const core::String& token)
{
    String t = cli::stripLeadingHyphens(token);
    unsigned pos = t.find('=');

    if (t.length() == 1)
    {
        if (options->hasShortOption(t))
        {
            handleOption(options->getOption(t));
        }
        else
        {
            handleUnknownToken(token);
        }
    }
    else if (pos == String::NPOS)
    {
        std::list<String> matchingLongOptions;

        if (options->hasShortOption(t))
        {
            handleOption(options->getOption(t));
        }
        else if (!getMatchingLongOptions(t, matchingLongOptions).empty())
        {
            handleLongOptionWithoutEqual(token);
        }
        else
        {
            String opt = getLongPrefix(t);

            if (options->getOption(opt)->acceptsArguments())
            {
                handleOption(options->getOption(opt));
                currentOption->addValueForProcessing(t.substring(opt.length()));
                currentOption = NULL;
            }
            else
            {
                handleConcatenatedOptions(token);
            }
        }
    }
    else
    {
        String opt = t.substring(0, pos);
        String value = t.substring(pos + 1);

        if (opt.length() == 1)
        {
            const Option* option = options->getOption(opt);
            if (option != NULL && option->acceptsArguments())
            {
                handleOption(option);
                currentOption->addValueForProcessing(value);
                currentOption = NULL;
            }
            else
            {
                handleUnknownToken(token);
            }
        }
        else
        {
            handleLongOptionWithEqual(token);
        }
    }
}

void DefaultParser::handleToken(const core::String& token)
{
    currentToken = token;

    if (skipParsing)
    {
        cmd->addArgument(token);
    }
    else if (currentToken.equals("--"))
    {
        skipParsing = true;
    }
    else if (currentOption != NULL && currentOption->acceptsArguments())
    {
        currentOption->addValueForProcessing(token);
    }
    else if (currentToken.startsWith("-") && !(currentToken.equals("-")))
    {
        handleShortAndLongOption(token);
    }
    else
    {
        handleUnknownToken(token);
    }

    if (currentOption != NULL && !currentOption->acceptsArguments())
    {
        currentOption = NULL;
    }
}

void DefaultParser::handleUnknownToken(const core::String& token)
{
    if (!token.startsWith("-") || !(token.length() > 1) || stopAtNonOption)
    {
        cmd->addArgument(token);
        if (stopAtNonOption)
        {
            skipParsing = true;
        }
    }
}

bool DefaultParser::isArgument(const core::String& token)
{
    return !isOption(token) || isNegativeNumber(token);
}

bool DefaultParser::isJavaProperty(const core::String& token)
{
    String opt = token.substring(0, 1);
    const Option* option = options->getOption(opt);

    return option == NULL && (option->getArguments() >= 2 || option->getArguments() == Option::UNLIMITED_VALUES);
}

bool DefaultParser::isLongOption(const core::String& token)
{
    bool result = false;
    if (token.startsWith("-") && token.length() != 1)
    {
        unsigned pos = token.find('=');
        String t = pos == String::NPOS ? token : token.substring(0, pos);

        std::list<String> matchingLongOptions;
        if (!getMatchingLongOptions(t, matchingLongOptions).empty())
        {
            result = true;
        }
        else if (token.startsWith("--"))
        {
            result = true;
        }
    }
    return result;
}

bool DefaultParser::isNegativeNumber(const core::String& token)
{
    bool result = false;
    if (token.startsWith("-"))
    {
        result = true;
        for (size_t i = 0; i < token.length() && result; i++)
        {
            if (!isdigit(token.charAt(i)))
            {
                result = false;
            }
        }
    }
    return result;
}

bool DefaultParser::isOption(const core::String& token)
{
    return isLongOption(token) || isShortOption(token);
}

bool DefaultParser::isShortOption(const core::String& token)
{
    bool result = false;
    if (token.startsWith("-") && token.length() != 1)
    {
        unsigned pos = token.find(token);
        String optName = pos == String::NPOS ? token.substring(1) : token.substring(1, pos);
        if (options->hasShortOption(optName))
        {
            result = true;
        }
        else
        {
            result = !(optName.isEmpty()) && options->hasShortOption(String(optName.charAt(0)));
        }
    }
    return result;
}

void DefaultParser::updateRequiredOptions(const Option* option)
{
    if (!option->isRequired())
    {
        expectedOptions.remove(option);
    }


}
