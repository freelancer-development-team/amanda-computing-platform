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
 * File:   ModuleReader.h
 * Author: Javier Marrero
 *
 * Created on April 17, 2022, 2:36 PM
 */

#ifndef MODULEREADER_H
#define MODULEREADER_H

#include <amanda-vm/IO/ConsistentInputStream.h>
#include <amanda-vm/Binutils/Module.h>
#include <amanda-vm/Logging/Logger.h>

// C/C++
#include <stack>

namespace amanda
{
namespace binutils
{

/**
 * A module reader is a special input stream class that is able to produce
 * <code>Module</code> objects from an input stream of bytes. The bytes can be
 * transferred across a network or may be stored in the local file system. This
 * reader should not care about these implementation details.
 *
 * @author J. Marrero
 */
class ModuleReader : public io::ConsistentInputStream
{
    AMANDA_OBJECT(ModuleReader, io::ConsistentInputStream)
public:

    ModuleReader(const core::String& name, io::InputStream& stream);
    virtual ~ModuleReader();

    const core::String& getName() const;
    virtual Module*     read() const;

protected:

    static const logging::Logger& LOGGER;

    core::String                    name;
    mutable std::stack<uint64_t>    records;

    void                            mark() const;
    uint64_t                        retrieve() const;

} ;

}
}

#endif /* MODULEREADER_H */

