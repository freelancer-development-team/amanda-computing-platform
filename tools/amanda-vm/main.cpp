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

/* Amanda API */
#include <AmandaVM.h>
#include <amanda-vm/Binutils/package.hxx>
#include <amanda-vm/Option/package.hxx>

/* C++ Library */
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <list>

/* Internal API */
#include <amanda-vm/vm-initialization.h>

#define AMANDA_ERROR(...) io::console().err.println("amanda-vm: \033[31;1merror\033[0m: " __VA_ARGS__)

using namespace amanda;

int main(int argc, char** argv)
{
    cli::Options options;
    adt::Array<core::String> argumentsArray = cli::makeArgumentsArray(argc, argv);
    core::StrongReference<cli::CommandLine> commandLine = vm::parseCommandLineArguments(argumentsArray, options);

    /* Parse the command line */
    int finalResult = EXIT_SUCCESS;
    if (commandLine->hasOption('h'))
    {
        amanda::vm::printFormattedHelpMessage(options);
    }
    if (commandLine->hasOption("version"))
    {
        amanda::vm::printVersionInformation();
    }
    else
    {
        // Parse the rest of options
        if (commandLine->hasOption("show-version"))
        {
            amanda::vm::printVersionInformation();
        }
        if (commandLine->hasOption('L'))
        {

        }

        const std::list<core::String>& arguments = commandLine->getArgumentList();
        if (arguments.size() < 1)
        {
            amanda::vm::printFormattedHelpMessage(options);
            AMANDA_ERROR("no valid module passed (needs 1 at least, passed %u).", arguments.size());
            abort();
        }

        /* Create the virtual machine context helpers. */
        //TODO: Add the allocation limit
        core::StrongReference<vm::MemoryManager> memoryManager = new vm::MemoryManager();

#ifndef USE_MALLOC_ALLOCATOR
        core::StrongReference<vm::MemoryAllocator> memoryAllocator = new vm::LocklessDefaultAllocator(memoryManager->getReference());
#else
        core::StrongReference<vm::MemoryAllocator> memoryAllocator = new vm::DefaultPoolAllocator(memoryManager->getReference());
#endif

        /* Create the virtual machine context. */
        core::StrongReference<vm::Context> context =
                new vm::Context(memoryAllocator,
                                argv[1]);

        /* Create & configure the scheduler */
        core::StrongReference<vm::ThreadScheduler> scheduler = new vm::NativeThreadScheduler(context->getReference());
        context->setScheduler(scheduler);

        /* Load the file and start executing. */
        for (std::list<core::String>::const_iterator iter = arguments.begin(),
             end = arguments.end(); iter != end; ++iter)
        {
            try
            {
                int partialResult = context->loadAndExecute(*iter);
                if (((unsigned) partialResult) > ((unsigned) finalResult))
                {
                    // Exit with the highest exit code
                    finalResult = partialResult;
                }
            }
            catch (core::Exception& ex)
            {
                vm::Context::getLogger().fatal("%s: %s",
                                               core::String(ex.getClassDynamically().getName()).toCharArray(),
                                               ex.getMessage().toLower().toCharArray());
            }
        }
    }
    return finalResult;
}
