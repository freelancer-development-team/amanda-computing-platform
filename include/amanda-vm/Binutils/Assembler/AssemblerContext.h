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
 * File:   AssemblerContext.h
 * Author: Javier Marrero
 *
 * Created on March 27, 2022, 4:06 PM
 */

#ifndef ASSEMBLERCONTEXT_H
#define ASSEMBLERCONTEXT_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/File.h>
#include <amanda-vm/Logging/Logger.h>

namespace amanda
{
namespace binutils
{
namespace as
{

/**
 * The assembler context is the class that manages the assembly of a source
 * file into an object file (not linked yet).
 */
class AssemblerContext : public core::Object
{
    AMANDA_OBJECT(AssemblerContext, core::Object)

public:

    AssemblerContext();
    virtual ~AssemblerContext();

    io::File*   getInputFile() const ;
    io::File*   getOutputFile() const ;
    bool        isVerbose() const;
    void        performAssemblyPass();
    void        setVerbose(bool verbose);
    void        setInputFile(io::File* inputFile);
    void        setOutputFile(io::File* outputFile);

protected:

    core::StrongReference<io::File>         inputFile;
    core::StrongReference<logging::Logger>  logger;
    core::StrongReference<io::File>         outputFile;
    bool                                    verbose;
    
} ;

}
}
}

#endif /* ASSEMBLERCONTEXT_H */

