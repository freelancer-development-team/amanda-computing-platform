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
 * File:   CompilationContext.h
 * Author: Javier Marrero
 *
 * Created on March 14, 2022, 1:43 AM
 */

#ifndef COMPILATIONCONTEXT_H
#define COMPILATIONCONTEXT_H

// Amanda API
#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/File.h>

// Compiler API
#include <amanda-c/Scanner.h>
#include <amanda-c/Parser.h>
#include <amanda-c/ParserLocations.h>
#include <amanda-c/ast-package.h>

// IL
#include <amanda-vm/IL/Module.h>
#include <amanda-vm/IL/Value.h>

namespace amanda
{
namespace compiler
{

class CompilationContext : public core::Object
{
    AMANDA_OBJECT(CompilationContext, core::Object)

public:

    CompilationContext(io::File* input);
    virtual ~CompilationContext();

    virtual il::Module* performSSATransformation();
    void                printAbstractSyntaxTree();
    void                setAbstractSyntaxTree(ast::NCompilationUnit* tree);

protected:

    virtual void        performSemanticAnalysis();

    ast::NCompilationUnit*          abstractSyntaxTree;
    core::StrongReference<io::File> inputFile;
    DefaultParser*                  parserObject;
    Scanner*                        scannerObject;

} ;

}
}

#endif /* COMPILATIONCONTEXT_H */

