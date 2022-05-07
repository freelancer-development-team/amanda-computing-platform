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
 * File:   Input.h
 * Author: Javier Marrero
 *
 * Created on April 11, 2022, 11:43 PM
 */

#ifndef _AMANDA_BINUTILS_INPUT_H
#define _AMANDA_BINUTILS_INPUT_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/File.h>

// Pair
#include <utility>

namespace amanda
{
namespace binutils
{

/**
 * This is a simple alias for the <code>std::pair</code> object. This object
 * is nothing but a template specialization with two <code>core::String</code>
 * as the members of the pair. An object of this class is used to feed the
 * lexical scanner of the assembler.
 * <p>
 * For constructing objects of this type use the function <code>
 * associateInputStream</code>, that given the right parameters provides an
 * object of this type. For the second parameter one would use any of the input
 * grabbing functions provided below.
 * 
 */
typedef std::pair<core::String, core::String> AssemblerInputStream;

/**
 * Builds the assembler input string from a memory buffer. The memory buffer
 * must be present & non-null and the length must be greater than zero. The
 * provided memory must not have any NULL ('<code>\\0</code>') character within.
 * Assuming this is correct UTF8 or ASCII encoded text, that should not be the
 * case.
 * <p>
 * There is no case in receiving other data than what you can get from a stream
 * of chars, since we are receiving not binary data but text suitable to be
 * parsed by the assembler proper. That is why we are receiving a char pointer,
 * not some obscure void pointer with an associated length.
 * <p>
 * The restriction of not having any NULL byte in the stream encourages this
 * anyway.
 *
 * @author J. Marrero
 */
core::String buildAssemblerInputFromMemory(const char* mem);

/**
 * Builds assembler input from a file object. The file must have read permission
 * and be opened for this function to work properly. The file must not contain
 * any NULL bytes and must be ASCII or UTF8 encoded text. Support for other file
 * encodings not compatible with these two is still under implementation.
 * <p>
 * This function does not own a reference to the passed file object; rather a
 * weak reference to the object. Object's life cycle is not responsibility of
 * this function, and therefore the object's reference count remains untouched
 * towards the execution of this function.
 *
 * @author J. Marrero
 */
core::String buildAssemblerInputFromFile(const io::File* file);

/**
 * Associates a file name to a input stream previously constructed with the
 * functions <code>buildAssemblerInputFromFile</code> and <code>
 * buildAssemblerInputFromMemory</code>. The returned object is an instance of
 * the <code>std::pair</code> template. This is the object that must be
 * passed to the <code>AssemblerLexer</code> instance; as the scanner stores
 * the name of its input for error diagnostics purposes.
 * </p>
 *
 * @author J. Marrero
 */
AssemblerInputStream associateInputStream(const core::String& streamName, const core::String& stream);

}
}

#endif /* INPUT_H */
