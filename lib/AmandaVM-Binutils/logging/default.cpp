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

#include <amanda-vm/Binutils/Logging.h>
#include <amanda-vm/Logging/ConsoleHandler.h>

using namespace amanda;
using namespace amanda::binutils;

void amanda::binutils::setFormatterForPackage(const logging::Formatter& formatter)
{
    static bool initialized = false;
    static logging::Logger* parentLogger = logging::Logger::getLogger("amanda.binutils");
    
    AMANDA_SYNCHRONIZED(lock);
    {
        if (initialized == false)
        {
            // Initialize the logger!
            parentLogger->setUseParentHandlers(false);

            // Create the console handler which is default.
            logging::ConsoleHandler* handler = new logging::ConsoleHandler(eliminateConstness(&formatter));
            parentLogger->addHandler(*handler);

            // Set the status variable
            initialized = true;
        }

        if (parentLogger)
        {
            for (unsigned i = 0; i < parentLogger->getHandlers().size(); ++i)
            {
                parentLogger->getHandlers()[i]->setFormatter(amanda::eliminateConstness(formatter));
            }
        }
    }
    AMANDA_DESYNCHRONIZED(lock);
}

logging::Logger& amanda::binutils::getPackageLogger()
{
    static logging::Logger* packageLogger = logging::Logger::getLogger("amanda.binutils");
    assert(packageLogger != NULL && "Null pointer exception");

    return *packageLogger;
}
