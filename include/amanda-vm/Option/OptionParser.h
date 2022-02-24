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
 * File:   OptionParser.h
 * Author: Javier Marrero
 *
 * Created on February 23, 2022, 12:39 PM
 */

#ifndef OPTIONPARSER_H
#define OPTIONPARSER_H

#include <amanda-vm/Option/Option.h>
#include <amanda-vm/String.h>

#include <vector>

namespace amanda
{
namespace options
{

class OptionParser
{
public:

    OptionParser(const int argc, const char** argv, OptionList options);
    virtual ~OptionParser();

    virtual wchar_t getNextOption();

private:

    const int       argc;
    const char**    argv;
    OptionList*     options;
} ;

}
}

#endif /* OPTIONPARSER_H */

