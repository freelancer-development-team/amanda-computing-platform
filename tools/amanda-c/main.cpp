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
 * File:   main.cpp
 * Author: Javier Marrero
 *
 * Created on February 27, 2022, 10:38 PM
 */

/* Amanda API includes */
#include <AmandaSDK.h>
#include <amanda-vm/Option/package.hxx>

/* Project includes */
#include <amanda-c/Driver.h>
#include <amanda-c/Messages.h>
#include <amanda-c/OptionsParser.h>
#include <amanda-c/c/version.h>

/* Standard C/C++ includes */
#include <cstdio>
#include <cstdlib>
#include <csignal>
#include <signal.h>
#include <clocale>

using namespace amanda;

void handleSegmentationFault(int signalNumber)
{
    compiler::log::fatal("internal compiler segmentation fault.");
}

void handleNonSigSegv(int signalNumber)
{
    switch (signalNumber)
    {
        case SIGINT:
        case SIGTERM:
            compiler::log::fatal("compilation canceled by user.");
            break;
        default:
            compiler::log::fatal("unknown fault.");
            break;
    }
}

/*
 * This is the entry point for the Amanda Programming Language compiler
 * frontend. This function parses the arguments and calls the compiler driver
 * with the appropriate options or switches.
 */
int main(int argc, char** argv)
{
    /* Set up the locale */
    std::setlocale(LC_ALL, "");

    /* Set-up signal handler */
    signal(SIGSEGV, &handleSegmentationFault);
    signal(SIGTERM, &handleNonSigSegv);
    signal(SIGINT, &handleNonSigSegv);

    /* Create the compiler driver object. */
    core::StrongReference<compiler::Driver> driver = new compiler::Driver();

    /* Now create the options object, parse the command line options and install
     * the appropriate flags into the object.
     */
    core::StrongReference<cli::Options> options = new cli::Options();
    adt::Array<core::String> arguments = cli::makeArgumentsArray(argc, argv);
    core::StrongReference<cli::CommandLine> commandLine
            = compiler::parseCommandLineArguments(arguments, options.get());

    /* Eliminate the possibility of a NULL dereference. */
    assert(!commandLine.isNull() && "Returned a NULL command line.");

    /* Parse the command line. */
    if (commandLine->hasOption('h'))
    {
        compiler::displayHelpMessage(options->getReference());
    }
    else if (commandLine->hasOption("version"))
    {
        compiler::displayVersionInformation();
    }
    else
    {
        if (commandLine->hasOption('c'))
        {
            driver->setCallLinker(false);
        }
        if (commandLine->hasOption("dump-version"))
        {
            io::console().out.println("amanda-c (AmandaSDK %s) %s", SDK_FULLVERSION_STRING, AMANDA_C_FULLVERSION_STRING);
        }
        if (commandLine->hasOption('o'))
        {
            /* Parse the comma separated values */
            adt::Array<core::String> values = commandLine->getOptionValues('o');
            for (unsigned i = 0; i < values.length(); i++)
            {
                core::StrongReference<io::File> file = new io::File(values[0], io::File::WRITE | io::File::CREATE | io::File::BINARY);
                assert(!file.isNull() && "Not enough memory.");

                driver->addOutputFile(file.get());
            }
        }
        if (commandLine->hasOption('S'))
        {
            driver->setCallAssembler(false);
            driver->setCallLinker(false);
        }
        if (commandLine->hasOption("statistics"))
        {
            driver->setShowStatistics(true);
        }
        if (commandLine->hasOption("verbose"))
        {
            driver->setVerbose(true);
        }
        if (commandLine->hasOption('W'))
        {
            core::String level = commandLine->getOptionValue('W');
            if (level == "all")
            {
                driver->setWarnLevel(compiler::Driver::WL_ALL);
            }
            //TODO: Finish this
        }

        for (std::vector<core::String>::iterator iter = commandLine->getArgumentList().begin();
             iter != commandLine->getArgumentList().end(); ++iter)
        {
            io::File* f = new io::File(*iter, io::File::READ);
            assert(f != NULL && "Not enough memory.");

            if (!f->open() || f->isError() || !(f->isFile()))
            {
                compiler::log::error("unable to open file '%s' for reading. %s.", f->getPath().toCharArray(),
                                     f->getLastErrorString().toCharArray());
            }
            else
            {
                if (driver->isVerbose())
                {
                    compiler::log::info("added file '%s' to the input stream.", f->getPath().toCharArray());
                }
                driver->addInputFile(f);
            }
        }

        /* Perform some validations to the input data. */
        if (!driver->hasInputFiles())
        {
            compiler::log::fatal("no input files.");
        }
        if (!driver->hasOutputFiles())
        {
            if (driver->isVerbose())
            {
                compiler::log::warning("no output files. Default filenames are used.");
            }

            for (std::list<io::File*>::const_iterator iter = driver->getInputFiles().begin();
                 iter != driver->getInputFiles().end(); ++iter)
            {
                const core::String& inPath = (*iter)->getPath();
                core::String outPath = inPath.substring(0, inPath.length() - 4).append(".il");

                if (driver->isVerbose())
                {
                    compiler::log::info("adding '%s' to the output stream.", outPath.toCharArray());
                }

                io::File* outFile = new io::File(outPath, io::File::WRITE | io::File::CREATE | io::File::BINARY);
                assert(outFile != NULL && "Not enough memory.");

                driver->addOutputFile(outFile);
            }
        }

        try
        {
            /* Perform the compiler pass. */
            driver->compileFiles();

            /* If statistics must be shown, display... */
            driver->showStatistics();
        }
        catch (core::Exception& ex)
        {
            amanda::compiler::log::fatal(ex.getMessage());
        }
    }
    return EXIT_SUCCESS;
}

