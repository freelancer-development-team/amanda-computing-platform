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
 * File:   Driver.cpp
 * Author: Javier Marrero
 * 
 * Created on March 10, 2022, 9:22 AM
 */

#include <amanda-c/Driver.h>
#include <amanda-c/Messages.h>
#include <amanda-c/CompilationContext.h>
#include <AmandaSDK.h>

#include <amanda-vm/IL/AssemblyILExporter.h>
#include <amanda-vm/IO/FileOutputStream.h>

using namespace amanda;
using namespace amanda::compiler;

Driver::Driver()
:
statistics(false),
verbose(false)
{
    initTicks = clock();
    errorCount = 0;
    warningCount = 0;
}

Driver::~Driver()
{
    for (std::list<io::File*>::iterator iter = inputFiles.begin(); iter != inputFiles.end(); ++iter)
    {
        (*iter)->release();
    }

    for (std::list<io::File*>::iterator iter = outputFiles.begin(); iter != outputFiles.end(); ++iter)
    {
        (*iter)->release();
    }
}

void Driver::addInputFile(io::File* file)
{
    if (file != NULL)
    {
        file->grab();
        inputFiles.push_back(file);
    }
}

void Driver::addOutputFile(io::File* file)
{
    if (file != NULL)
    {
        file->grab();
        outputFiles.push_back(file);
    }
}

int Driver::compileFile(io::File* input, io::File* output)
{
    assert(input != NULL && "Passed NULL input file.");
    assert(output != NULL && "Passed NULL output file.");

    int result = 0;
    if (verbose)
    {
        log::info("Compiling file '%s' into '%s'.", input->getPath().toCharArray(),
                  output->getPath().toCharArray());
    }

    try
    {
        core::StrongReference<CompilationContext> context = new CompilationContext(input);
        core::StrongReference<il::Module> module = context->performSSATransformation();

        // Perform the different optimization passes as specified


        // Export the IL to assembly code
        core::StrongReference<il::ILExporter> exporter = new il::AssemblyILExporter(module);
        if (!assemble)
        {
            // Export the assembly code directly
            if (!output->isOpen())
            {
                if (!output->open())
                {
                    throw nio::IOException(output->getLastErrorString());
                }
            }

            io::FileOutputStream outputStream(output);
            exporter->exportData(outputStream);
        }
        else
        {

        }
    }
    catch (core::Exception& ex)
    {
        log::error("%s: %s: %s", input->getPath().toCharArray(), ex.getClassDynamically().getName(), ex.getMessage().toCharArray());
        result = 1;
    }

    return result;
}

void Driver::compileFiles()
{
    try
    {
        // For the maximum number of threads, initialize one compilation process in
        // each of them.
        if (verbose)
        {
            log::info("Beginning compilation process... (%lu input file%s)",
                      inputFiles.size(),
                      inputFiles.size() > 1 ? "s" : "");
        }

        // Exit with the highest exit code
        int result = 0;

        /// TODO: Handle this properly
        STL_ITERATOR(list, io::File*, o_it);
        STL_ITERATOR(list, io::File*, i_it);
        for (i_it = inputFiles.begin(),
             o_it = outputFiles.begin(); i_it != inputFiles.end(); ++i_it)
        {
            int compileStatus = compileFile(*i_it, *o_it);
            if (compileStatus > result)
            {
                result = compileStatus;
            }

            if (o_it != outputFiles.end())
            {
                ++o_it;
            }
        }

        if (result != 0)
        {
            throw core::Exception("compilation failed...");
        }
    }
    catch (...)
    {
        log::fatal("unspecified internal error.");
    }
}

const std::list<io::File*>& Driver::getInputFiles()
{
    return inputFiles;
}

const std::list<io::File*>& Driver::getOutputFiles()
{
    return outputFiles;
}

bool Driver::hasInputFiles() const
{
    return !inputFiles.empty();
}

bool Driver::hasOutputFiles() const
{
    return !outputFiles.empty();
}

bool Driver::isShowStatistics() const
{
    return statistics;
}

bool Driver::isVerbose() const
{
    return verbose;
}

void Driver::setCallAssembler(bool callAssembler)
{
    assemble = callAssembler;
}

void Driver::setCallLinker(bool callLinker)
{
    link = callLinker;
}

void Driver::setShowStatistics(bool show)
{
    this->statistics = show;
}

void Driver::setVerbose(bool verbose)
{
    this->verbose = verbose;
}

void Driver::setWarnLevel(WarningLevel level)
{
    this->warningLevel = level;
}

void Driver::showStatistics()
{
    if (statistics && verbose)
    {
        finiTicks = ::clock();
        double ellapsed = (finiTicks - initTicks) / 100.0f;

        io::console().out.println("Statistics:\n"
                                  "    errors:        %-10lu\n"
                                  "    warnings:      %-10lu\n"
                                  "    time ellapsed: %.2lfs",
                                  errorCount,
                                  warningCount,
                                  ellapsed);
    }
}
