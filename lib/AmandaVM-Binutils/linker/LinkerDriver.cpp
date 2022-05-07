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
 * File:   LinkerDriver.cpp
 * Author: Javier Marrero
 * 
 * Created on May 2, 2022, 4:05 PM
 */

#include <amanda-vm/Binutils/LinkerDriver.h>
#include <amanda-vm/Binutils/Serializer.h>

using namespace amanda;
using namespace amanda::binutils;

LinkerDriver::LinkerDriver(Module* master)
{
    inputModules.reserve(5);
    libraries.reserve(10);
    outputStreams.reserve(5);

    // Add the master module
    addObjectFile(master);
}

LinkerDriver::~LinkerDriver()
{
    // Release the grabbed reference to the input modules
    for (unsigned i = 0; i < inputModules.size(); ++i)
        inputModules.at(i)->release();

    // Release the grabbed reference to the libraries
    for (unsigned i = 0; i < libraries.size(); ++i)
        libraries.at(i)->release();

    // Release a reference to the output streams
    for (unsigned i = 0; i < outputStreams.size(); ++i)
        outputStreams.at(i)->release();
}

void LinkerDriver::addLibraries(adt::Array<Module*> libs)
{
    libraries.reserve(libraries.size() + libs.length());
    for (size_t i = 0; i < libs.length(); ++i)
    {
        addLibrary(libs[i]);
    }
}

void LinkerDriver::addLibrary(Module* lib)
{
    lib->grab();
    libraries.push_back(lib);
}

void LinkerDriver::addObjectFile(Module* additional)
{
    additional->grab();
    inputModules.push_back(additional);
}

void LinkerDriver::addOutputStream(io::OutputStream* stream)
{
    // Grab a reference to the output stream
    stream->grab();

    // Add the stream to the list of streams
    outputStreams.push_back(stream);
}

void LinkerDriver::dump() const
{
    // Add the output handlers
    for (unsigned i = 0; i < outputStreams.size(); ++i)
    {
        getMasterModule().addSerializationHandler(new Serializer(outputStreams.at(i)));
    }

    // Output the linked module
    getMasterModule().marshall();
}

Symbol* LinkerDriver::findSymbolInLibraries(const core::String& name) const
{
    // The result value
    Symbol* result = NULL;

    bool found = false;
    for (std::vector<Module*>::const_iterator it = libraries.begin(),
         end = libraries.end(); it != end && !found; ++it)
    {
        result = (*it)->findSymbol(name);
        if (result != NULL)
            found = true;
    }

    return result;
}

Module& LinkerDriver::getMasterModule() const
{
    return *(inputModules.front());
}

void LinkerDriver::link()
{
    // If there is more than one input, merge the modules & resolve the local
    // symbols.
    Module* master = inputModules.at(0);
    if (inputModules.size() > 1)
    {
        //TODO: Merge the modules
        for (unsigned i = 1; i < inputModules.size(); ++i)
        {
            master->mergeExternalModule(*(inputModules.at(i)));
        }
    }

    // Link the local symbols of the merged module
    master->linkLocalSymbols();

    // Link against the libraries.

}



