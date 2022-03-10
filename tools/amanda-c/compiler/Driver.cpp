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
 * File:   Driver.cpp
 * Author: Javier Marrero
 * 
 * Created on March 10, 2022, 9:22 AM
 */

#include <amanda-c/Driver.h>
#include <AmandaSDK.h>

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

void Driver::setShowStatistics(bool show)
{
    this->statistics = show;
}

void Driver::setVerbose(bool verbose)
{
    this->verbose = verbose;
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
