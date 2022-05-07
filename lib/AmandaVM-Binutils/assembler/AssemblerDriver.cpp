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
 * File:   AssemblerDriver.cpp
 * Author: Javier Marrero
 * 
 * Created on April 12, 2022, 11:01 AM
 */

#include <amanda-vm/Binutils/AssemblerDriver.h>
#include <amanda-vm/Binutils/Serializer.h>

using namespace amanda;
using namespace amanda::binutils;
using namespace amanda::binutils::as;

AssemblerDriver::AssemblerDriver(const AssemblerInputStream& input)
:
input(input),
parser(input)
{
    // Reserve space for 2 output handlers.
    outputList.reserve(2);
}

AssemblerDriver::~AssemblerDriver()
{
    for (std::vector<io::OutputStream*>::const_iterator it = outputList.begin(),
         end = outputList.end(); it != end; ++it)
    {
        (*it)->releaseWeakReference();
    }
}

void AssemblerDriver::addOutputHandler(io::OutputStream* output)
{
    assert(output != NULL && "Null pointer exception.");

    // Does not own the reference. Grab a weak reference instead.
    output->grabWeakReference();
    outputList.push_back(output);
}

const core::String& AssemblerDriver::getInputStreamName() const
{
    return input.first;
}

Module* AssemblerDriver::performAssemblerPass()
{
    Module* module = parser.parse();
    assert(module != NULL && "How module gets to be null without an exception being thrown?");

    // Generate the code for every selected output handler.
    for (std::vector<io::OutputStream*>::const_iterator it = outputList.begin(),
         end = outputList.end(); it != end; ++it)
    {
        core::StrongReference<Serializer> serializerObject = new Serializer(*it);
        module->addSerializationHandler(serializerObject);
    }

    // Marshall & serialize the output.
    module->marshall();

    // Return a reference to the module (without link)
    return module;
}

