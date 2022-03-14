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
 * File:   CompilationContext.cpp
 * Author: Javier Marrero
 * 
 * Created on March 14, 2022, 1:43 AM
 */

#include <amanda-c/CompilationContext.h>

using namespace amanda;
using namespace amanda::compiler;

CompilationContext::CompilationContext(io::File* input, io::File* output)
:
inputFile(input),
outputFile(output)
{
}

CompilationContext::~CompilationContext()
{
    delete scannerObject;
    delete parserObject;
}

int CompilationContext::performSSATransformation()
{
    reflex::Input inputObject(inputFile->getHandle());
    scannerObject = new Scanner(inputObject);
    scannerObject->filename = inputFile->getPath().toCharArray();

    parserObject = new DefaultParser(*scannerObject);

    return parserObject->parse();
}
