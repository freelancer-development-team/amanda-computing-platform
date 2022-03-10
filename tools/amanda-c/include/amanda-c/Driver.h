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
 * File:   Driver.h
 * Author: Javier Marrero
 *
 * Created on March 10, 2022, 9:22 AM
 */

#ifndef DRIVER_H
#define DRIVER_H

#include <amanda-vm/Object.h>
#include <amanda-vm/Pointer.h>
#include <amanda-vm/IO/File.h>

#include <ctime>
#include <list>

namespace amanda
{
namespace compiler
{

/**
 * This driver class is a compiler driver front-end class.
 */
class Driver : public core::Object
{
    AMANDA_OBJECT(Driver, core::Object)

public:

    Driver();
    virtual ~Driver();

    void                        addInputFile(io::File* file);
    void                        addOutputFile(io::File* file);
    const std::list<io::File*>& getInputFiles();
    const std::list<io::File*>& getOutputFiles();
    bool                        hasInputFiles() const;
    bool                        hasOutputFiles() const;
    bool                        isShowStatistics() const;
    bool                        isVerbose() const;
    void                        setShowStatistics(bool show);
    void                        setVerbose(bool verbose);
    void                        showStatistics();

protected:

    std::list<io::File*>        inputFiles;
    std::list<io::File*>        outputFiles;
    bool                        statistics;
    bool                        verbose;

private:

    clock_t                     initTicks;
    clock_t                     finiTicks;

    unsigned long               warningCount;
    unsigned long               errorCount;
} ;

}
}

#endif /* DRIVER_H */
