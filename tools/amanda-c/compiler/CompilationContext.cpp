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
 * File:   CompilationContext.cpp
 * Author: Javier Marrero
 * 
 * Created on March 14, 2022, 1:43 AM
 */

#include <amanda-c/CompilationContext.h>
#include <amanda-c/SemanticAnalizer.h>
#include <amanda-c/Messages.h>

#include <amanda-vm/Frontend/SemanticException.h>
#include <amanda-vm/IL/package.hxx>

using namespace amanda;
using namespace amanda::compiler;

CompilationContext::CompilationContext(io::File* input)
:
abstractSyntaxTree(NULL),
inputFile(input),
parserObject(NULL),
scannerObject(NULL)
{
    // Create the long lived scanner object
    reflex::Input inputObject(inputFile->getHandle());
    scannerObject = new Scanner(inputObject);
    scannerObject->filename = inputFile->getPath().toCharArray();
}

CompilationContext::~CompilationContext()
{
    // Delete all the acquired resources.
    // Scanner, parser and abstract syntax tree instance for this compilation
    // unit.
    delete scannerObject;
    delete parserObject;

    // Release a reference to the AST object (it may be owned by other classes)
    if (abstractSyntaxTree != NULL)
        abstractSyntaxTree->release();
}

void CompilationContext::setAbstractSyntaxTree(ast::NCompilationUnit* tree)
{
    assert(tree != NULL && "Null pointer exception");
    abstractSyntaxTree = tree;

    // We are owning now a reference to the tree.
    abstractSyntaxTree->grab();
}

il::Module* CompilationContext::performSSATransformation()
{
    // RAII pattern
    parserObject = new DefaultParser(*this, *scannerObject);
    int parserResult = 1;

    // The resulting object
    il::Module* result = NULL;

    //TODO: Debug only when necessary
    // parserObject->set_debug_level(1);

    try
    {
        parserResult = parserObject->parse();
        if (parserResult == 0)
        {
            performSemanticAnalysis();  // This throws an exception if fails

            // Now perform the SSA transformation
            core::StrongReference<il::CodeGenContext> codeGenContext =
                    new il::CodeGenContext();

            result = abstractSyntaxTree->performSSATransformationForModule(codeGenContext->getReference());
        }
    }
    catch (core::Exception& ex)
    {
        log::fatal("%s: %s", ex.getClassDynamically().getName(), ex.getMessage().toCharArray());
        throw ex;
    }
    return result;
}

void CompilationContext::printAbstractSyntaxTree()
{
    assert(abstractSyntaxTree != NULL && "Null pointer exception.");

    io::console().err.println("\n ===== ABSTRACT SYNTAX TREE ===== ");
    abstractSyntaxTree->printNodeAndChildren();
    io::console().err.println(" ===== DONE ===== \n");

}

void CompilationContext::performSemanticAnalysis()
{
    assert(abstractSyntaxTree != NULL && "Null pointer exception.");

#if 1
    /* Debug print the entire tree. */
    printAbstractSyntaxTree();
#endif

    try
    {
        core::StrongReference<SemanticAnalizer> semanticAnalizer = new SemanticAnalizer();
        assert(!semanticAnalizer.isNull() && "Null pointer exception");

        abstractSyntaxTree->doSemanticAnalysis(*semanticAnalizer);
    }
    catch (frontend::SemanticException& ex)
    {
        log::error(ex.getMessage());
    }
}
