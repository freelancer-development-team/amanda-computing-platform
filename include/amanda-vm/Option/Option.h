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
 * File:   Option.h
 * Author: Javier Marrero
 *
 * Created on February 23, 2022, 6:41 PM
 */

#ifndef OPTION_H
#define OPTION_H

#include <cwchar>

namespace amanda
{
namespace options
{

/*
 * This structure represents an option from the command line. These are
 * initialized in an array.
 */
typedef struct
{
    const wchar_t   shortOption;
    const wchar_t*  longOption;
    const wchar_t*  description;

    unsigned int    arity;
    unsigned int    flags;
} Option;

typedef Option OptionList[];

#define OPTION_INIITIALIZER(s, l, d, a, f)  { s, l, d, a, f }
#define OPTION_LIST_END()                   { 0, NULL, NULL, 0, 0 }

}
}

#endif /* OPTION_H */

