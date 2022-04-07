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
 * File:   AssemblerContext.cpp
 * Author: Javier Marrero
 * 
 * Created on March 27, 2022, 4:06 PM
 */

#include <amanda-vm/Binutils/Assembler/AssemblerContext.h>
#include <amanda-vm/Logging/ConsoleHandler.h>
#include <amanda-vm/Logging/GNUFormatter.h>
#include <amanda-vm/Binutils/Assembler/AssemblerParser.h>
#include <amanda-vm/IO/ConsistentOutputStream.h>
#include <amanda-vm/IO/FileOutputStream.h>

using namespace amanda;
using namespace amanda::binutils::as;

AssemblerContext::AssemblerContext()
:
logger(logging::Logger::getLogger("amanda.binutils.as"))
{
    // Configure the logger
    logger->setUseParentHandlers(false);
    logger->addHandler(*(new logging::ConsoleHandler(new logging::GNUFormatter("amanda-as", true))));
    // logger->setLevel(logging::Logger::INFO);
}

AssemblerContext::~AssemblerContext()
{
}

bool AssemblerContext::isVerbose() const
{
    return verbose;
}

void AssemblerContext::setVerbose(bool verbose)
{
    this->verbose = verbose;
}

void AssemblerContext::setOutputFile(io::File* outputFile)
{
    this->outputFile = outputFile;
}

io::File* AssemblerContext::getOutputFile() const
{
    return outputFile;
}

void AssemblerContext::setInputFile(io::File* inputFile)
{
    this->inputFile = inputFile;
}

io::File* AssemblerContext::getInputFile() const
{
    return inputFile;
}

void AssemblerContext::performAssemblyPass()
{
    // Log that we have started. These are debug level and therefore they
    // do not show themselves when in production, nor they are even logged.
    // The effort of calling these functions is minimal, please, don't fall
    // pray of premature optimization!
    logger->debug("initiating assembler pass for context @(0x%p).", this);

    core::StrongReference<AssemblerParser> parser = new AssemblerParser(inputFile.get(), outputFile.get());
    try
    {
        parser->parse();

        // Create the output streams & generate the code
        // Open the output file!
        if (!outputFile->open())
        {
            logger->fatal("unable to open file '%s' for writing. %s.",
                          outputFile->getPath().toCharArray(),
                          outputFile->getLastErrorString().toCharArray());
        }
        else
        {
            core::StrongReference<io::FileOutputStream> fileStream = new io::FileOutputStream(outputFile);
            io::ConsistentOutputStream byteStream(*fileStream);

            parser->generateCode(byteStream);
        }
    }
    catch (core::Exception& ex)
    {
        logger->fatal("%s", ex.getMessage().toCharArray());
    }

    // Log if done!
    logger->debug("done assembler pass, cleaning up...");
}


