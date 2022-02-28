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
 * File:   Options.h
 * Author: Javier Marrero
 *
 * Created on February 27, 2022, 10:31 PM
 */

#ifndef OPTIONS_H
#define OPTIONS_H

#include <amanda-vm/Object.h>
#include <amanda-vm/Option/Option.h>

// STL
#include <map>
#include <list>
#include <vector>

namespace amanda
{
namespace cli
{

class Options : public core::Object
{
    AMANDA_OBJECT(Options, core::Object)

public:

    ~Options();

    Options&        addOption(const Option* option);
    Options&        getMatchingOptions(const core::String& option,
                                       std::vector<core::String>& matchingOptions);
    const Option*   getOption(const core::String& option);
    void            getOptions(std::list<const Option*>& list) const;
    bool            hasLongOption(const core::String& option);
    bool            hasOption(const core::String& option);
    bool            hasShortOption(const core::String& option);
    void            helpOptions(std::list<const Option*>& list) const;

private:

    std::map<core::String, const Option*> shortOptions;
    std::map<core::String, const Option*> longOptions;
} ;

}   // namespace 'cli'
}   // namespace 'amanda'

#endif /* OPTIONS_H */

