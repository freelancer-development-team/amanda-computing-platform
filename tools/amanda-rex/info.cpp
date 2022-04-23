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

// SDK API
#include "interface.h"
#include <AmandaSDK.h>
#include <amanda-vm/Binutils/package.hxx>

using namespace amanda;
using namespace amanda::binutils;

void amanda::rdx::displayObjectFileInformation(const core::String& fileName)
{
    // Create the logging object
    core::StrongReference<logging::Logger> logger = logging::Logger::getLogger("amanda.read-executable.informant");

    // Get a reference to the console output.
    // For future implementations, this may be wrapped in order to allow
    // output redirection.
    io::PrintStream& out = io::console().out;

    // Get the file object
    core::StrongReference<io::File> file = new io::File(fileName, io::File::READ | io::File::BINARY);
    if (file->open() == true)
    {
        logger->info("opened '%s' for reading.", file->getPath().toCharArray());

        // Create the input stream that will be used to read from the file.
        io::FileInputStream fstream(file);
        binutils::ModuleReader mstream(file->getPath(), fstream);

        if (Module::checkMagicNumber(mstream) == false)
        {
            logger->error("'%s' is not a valid AmandaVM executable file (invalid magic number).",
                          file->getPath().toCharArray());
        }
        else
        {
            // Proceed as normal
            // Grab some data
            uint64_t sizeInBytes = file->getSize();

            // Print some header information
            out.println("MODULE NAME:           %s\n"
                        "SIZE:                  %luB (%.2lfKiB, %.2lfMiB)\n",
                        file->getPath().toCharArray(),
                        sizeInBytes, (double) sizeInBytes / 0x400, (double) sizeInBytes / 0x100000);

            core::StrongReference<Module> module = mstream.read();
            out.println("IMAGE VERSION:         %s", Module::decodeVersionFromTriplet(module->getBinaryFormatVersion()).toCharArray());
            out.println("ENTRY POINT ADDRESS:   0x%016llx", module->getEntryPointAddress());
            out.println("NUMBER OF SECTIONS:    %d", module->countSections());
        }
    }
    else
    {
        logger->error("unable to open '%s' for reading. %s.",
                      file->getPath().toCharArray(),
                      file->getLastErrorString().toCharArray());
    }
}
