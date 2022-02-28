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
 * File:   HelpFormatter.h
 * Author: Javier Marrero
 *
 * Created on February 26, 2022, 3:14 PM
 */

#ifndef HELPFORMATTER_H
#define HELPFORMATTER_H

#include <amanda-vm/Object.h>
#include <amanda-vm/Option/Option.h>
#include <amanda-vm/Option/Options.h>
#include <amanda-vm/IO/PrintStream.h>
#include <amanda-vm/IO/Console.h>

namespace amanda
{
namespace cli
{

class HelpFormatter : public core::Object
{
    AMANDA_OBJECT(HelpFormatter, core::Object)

public:

    static const unsigned int   DEFAULT_WIDTH =         74;
    static const unsigned int   DEFAULT_LEFT_PAD =      1;
    static const unsigned int   DEFAULT_DESC_PAD =      3;
    static const core::String   DEFAULT_SYNTAX_PREFIX;
    static const core::String   DEFAULT_OPT_PREFIX;
    static const core::String   DEFAULT_LONG_OPT_PREFIX;
    static const core::String   DEFAULT_LONG_OPT_SEPARATOR;
    static const core::String   DEFAULT_ARG_NAME;

    virtual void printHelp(const unsigned width, const core::String& cmdLineSyntax,
                           const core::String& header, const Options& options,
                           const core::String& footer, const bool autoUsage = false,
                           const io::PrintStream& stream = io::console().out,
                           const unsigned descPad = DEFAULT_DESC_PAD,
                           const unsigned leftPad = DEFAULT_LEFT_PAD) const;
    virtual void printOptions(const io::PrintStream& stream, const unsigned width,
                              const Options& options, const unsigned leftPad,
                              const unsigned descPad) const;
    virtual void printUsage(const io::PrintStream& stream, const unsigned width,
                            const core::String& cmdLineSyntax) const;
    virtual void printUsage(const io::PrintStream& stream, const unsigned width,
                            const core::String& app, const Options& options) const;
    virtual void printWrapped(const io::PrintStream& stream, const unsigned width,
                              const core::String& text, const unsigned nextLineTabStop = 0) const;

protected:

    virtual core::String    createPadding(const unsigned int length) const;
    virtual unsigned int    findWrapPosition(const core::String& text,
                                             const unsigned int width,
                                             const unsigned int startPosition) const;
    virtual core::String&   renderOptions(core::String& sb, const unsigned width, const Options& options,
                                          const unsigned leftPad, const unsigned descPad) const;
    virtual core::String&   renderWrappedText(core::String& sb, const unsigned width,
                                              unsigned nextTabLineStop,
                                              core::String& text) const;
    virtual core::String    rtrim(const core::String& s) const;

private:

    void                    appendOption(core::String& buffer, const Option& option, bool required) const;
    core::String&           renderWrappedTextBlock(core::String& buffer, const unsigned width,
                                                   const unsigned nextLineTabStop,
                                                   const core::String& text) const;

} ;

}
}

#endif /* HELPFORMATTER_H */

