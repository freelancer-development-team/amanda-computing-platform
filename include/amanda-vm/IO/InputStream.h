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
 * File:   InputStream.h
 * Author: Javier Marrero
 *
 * Created on March 1, 2022, 1:53 AM
 */

#ifndef INPUTSTREAM_H
#define INPUTSTREAM_H

#include <amanda-vm/Object.h>

namespace amanda
{
namespace io
{

/**
 * Input stream instances are, as its name indicates, streams used for reading
 * data. This class presents a generalized but well defined interface for
 * working with input streams. It does not specify the data types read, neither
 * it specifies the source. Therefore, it could easily be extended to work
 * with networks and other sources or data representations.
 *
 * @author J. Marrero
 */
class InputStream : public core::Object
{
    AMANDA_OBJECT(InputStream, core::Object)

public:

    InputStream();
    virtual ~InputStream();
} ;

}
}

#endif /* INPUTSTREAM_H */

