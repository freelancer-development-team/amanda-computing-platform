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
 * File:   DefaultParser.h
 * Author: Javier Marrero
 *
 * Created on March 1, 2022, 2:16 PM
 */

#ifndef DEFAULTPARSER_H
#define DEFAULTPARSER_H

#include <amanda-vm/Pointer.h>
#include <amanda-vm/Option/CommandLineParser.h>
#include <amanda-vm/Option/CommandLine.h>
#include <amanda-vm/Option/Option.h>
#include <amanda-vm/Option/Options.h>

#include <list>

namespace amanda
{
namespace cli
{

class DefaultParser : extends CommandLineParser
{
    AMANDA_OBJECT(DefaultParser, CommandLineParser)

public:

    DefaultParser(bool allowPartialMatching, bool stripLeadingAndTrailingQuotes);
    virtual ~DefaultParser();

    virtual CommandLine* parse(Options& options, adt::Array<core::String>& arguments, bool stopAtNonOption);

protected:
        
    bool                                allowPartialMatching;
    core::StrongReference<CommandLine>  cmd;
    core::String                        currentToken;
    Option*                             currentOption;
    std::list<const Option*>            expectedOptions;
    core::StrongReference<Options>      options;
    bool                                skipParsing;
    bool                                stopAtNonOption;
    bool                                stripLeadingAndTrailingQuotes;

    bool                        checkRequiredOptions();
    void                        handleConcatenatedOptions(const core::String& token);

private:

    bool                        checkRequiredArguments();
    core::String                getLongPrefix(const core::String& token);
    std::list<core::String>&    getMatchingLongOptions(const core::String& token, std::list<core::String>& matches);
    void                        handleLongOption(const core::String& token);
    void                        handleLongOptionWithEqual(const core::String& token);
    void                        handleLongOptionWithoutEqual(const core::String& token);
    void                        handleOption(const Option* option);
    void                        handleShortAndLongOption(const core::String& token);
    void                        handleToken(const core::String& token);
    void                        handleUnknownToken(const core::String& token);
    bool                        isArgument(const core::String& token);
    bool                        isJavaProperty(const core::String& token);
    bool                        isLongOption(const core::String& token);
    bool                        isNegativeNumber(const core::String& token);
    bool                        isOption(const core::String& token);
    bool                        isShortOption(const core::String& token);

} ;

}
}

#endif /* DEFAULTPARSER_H */

