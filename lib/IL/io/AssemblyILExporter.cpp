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
 * File:   AssemblyILExporter.cpp
 * Author: Javier Marrero
 * 
 * Created on July 13, 2022, 6:29 PM
 */

#include <amanda-vm/IL/AssemblyILExporter.h>
#include <amanda-vm-c/sdk-definitions.h>
#include <amanda-vm-c/sdk-version.h>

// C++
#include <ctime>

using namespace amanda;
using namespace amanda::il;

AssemblyILExporter::AssemblyILExporter(Module* module)
:
ILExporter(module)
{
}

AssemblyILExporter::~AssemblyILExporter()
{
}

void AssemblyILExporter::exportData(io::OutputStream& stream)
{
    stream.write("# Generated by the Amanda Language Compiler (SDK v" SDK_FULLVERSION_STRING ")\n"
                 "# Copyright (C) 2022, FreeLancer Development Team\n"
                 "# \n"
                 "# Exported via AssemblyILExporter class\n"
                 "# Export date & time: ");
    // Print the date & time
    {
        time_t dateTime = std::time(NULL);
        char dateTimeBuffer[256] = {0};
        std::strftime(dateTimeBuffer, 256, "%A %c\n", std::localtime(&dateTime));

        stream.write(dateTimeBuffer);
    }
    // Print the module name
    stream.write("# Module identifier: " + module->getIdentifier() + "\n\n");

    // Write the code section
    stream.write(".section \".code\"\n.attributes \"rx\"\n\n");
    for (Module::FunctionList::const_iterator it = module->getFunctions().begin(),
         end = module->getFunctions().end(); it != end; ++it)
    {
        exportDataForFunction(stream, *it);
    }

    // Write the data & rodata section
    stream.write(".section \".data\"\n.attributes \"rw\"\n\n");
}

void AssemblyILExporter::exportDataForFunction(io::OutputStream& stream, Function* f) const
{
    core::String result("# Generating code for function: " + f->getName() + "\n");
    // Begin
    result.append(".def " + f->getName() + "\n");
    stream.write(result);

    

    // End
    stream.writeln(".endef\n");
}


