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
 * File:   Ast.h
 * Author: Javier Marrero
 *
 * Created on March 13, 2022, 12:40 AM
 */

#ifndef AMANDA_AST_H
#define AMANDA_AST_H

/*
 * The following includes constitutes the Amanda programming language abstract
 * syntax tree representation. Please, when adding nodes to this tree, include
 * them here and sort the includes alphabetically.
 * 
 */

#include <amanda-c/ast/Lists.h>
#include <amanda-c/ast/NBinaryOperator.h>
#include <amanda-c/ast/NBlock.h>
#include <amanda-c/ast/NCompilationUnit.h>
#include <amanda-c/ast/NCompoundStatement.h>
#include <amanda-c/ast/NDeclaration.h>
#include <amanda-c/ast/NExpression.h>
#include <amanda-c/ast/NExpressionStatement.h>
#include <amanda-c/ast/NFunctionCall.h>
#include <amanda-c/ast/NFunctionDeclaration.h>
#include <amanda-c/ast/NNamespaceDeclaration.h>
#include <amanda-c/ast/NReturnStatement.h>
#include <amanda-c/ast/NStatement.h>
#include <amanda-c/ast/NUsingDeclaration.h>
#include <amanda-c/ast/NWhileStatement.h>

#endif /* AST_H */

