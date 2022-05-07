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
 * File:   AssemblerDriver.h
 * Author: Javier Marrero
 *
 * Created on April 12, 2022, 11:01 AM
 */

#ifndef ASSEMBLERDRIVER_H
#define ASSEMBLERDRIVER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/AssemblerLexer.h>
#include <amanda-vm/Binutils/AssemblerParser.h>

#include <vector>

namespace amanda
{
namespace binutils
{
namespace as
{

/**
 * The <code>AssemblerDriver</code> class handles all the assembly process given
 * a input and and output stream. It doesn't call the linker driver though, since
 * its responsibility is to generate an object file (be it in an actual persistent
 * system file, or in memory).
 * <p>
 * One can add to this driver several output handlers that will be passed to the
 * corresponding <code>Serializer</code> objects. This object does not manages
 * the life time of the passed output streams. It grabs and releases weak
 * references instead.
 *
 * @author J. Marrero
 */
class AssemblerDriver : public core::Object
{
    AMANDA_OBJECT(AssemblerDriver, core::Object)
public:

    AssemblerDriver(const AssemblerInputStream& input);
    virtual ~AssemblerDriver();

    void                addOutputHandler(io::OutputStream* output);
    const core::String& getInputStreamName() const;
    Module*             performAssemblerPass();

private:

    const AssemblerInputStream      input;
    std::vector<io::OutputStream*>  outputList;
    AssemblerParser                 parser;

} ;

}
}
}

#endif /* ASSEMBLERDRIVER_H */

