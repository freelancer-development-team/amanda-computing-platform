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
 * File:   AssemblerParser.cpp
 * Author: Javier Marrero
 * 
 * Created on April 2, 2022, 1:26 AM
 */

#include <amanda-vm/Binutils/Assembler/AssemblerParser.h>

// Amanda API
#include <amanda-vm/Binutils/Linker/Function.h>

// Include the scanner code
#include "_scanner.hpp"
#include "_tokens.h"

#define YYSCAN(x)   ((yyscan_t) (x))

using namespace amanda;
using namespace amanda::binutils::as;

/* ========================================================================== */

AssemblerParser::AssemblerParser(io::File* input, io::File* output)
:
input(input),
logger(logging::Logger::getLogger("amanda.binutils.as.parser")),
object(NULL),
output(output),
scanner(NULL)
{
    logger->trace("initializing parser...");
    scanner_lex_init_extra(this, (yyscan_t*) & scanner);
}

AssemblerParser::~AssemblerParser()
{
    logger->trace("destroying parser...");
    scanner_lex_destroy(YYSCAN(scanner));
}

void AssemblerParser::generateCode(io::OutputStream& stream)
{
    assert(object.get() != NULL && "Null pointer exception.");
    logger->debug("generating code for object file @0x%p", object.get());

    // Object files are self-contained. There's no need for further analysis.
    // Just output the code...
    object->marshall(stream);

    logger->debug(" -- done --");
}

void AssemblerParser::parse()
{
    // Set the input for the scanner (it accepts 8-bit normalized UTF-8 text)
    scanner_restart(input->getHandle(), YYSCAN(scanner));

    // Create the binary object file in memory.
    io::Path outputPath(output->getPath());

    object = new ld::BinaryObject(output, outputPath.getLastPathComponent());
    logger->trace("created in-memory object file at address: 0x%p, with name %s.", object, object->getName().toCharArray());

    // Create some discardable book-keeping data
    ld::Section* currentSection = new ld::Section(".code");
    currentSection->setCapabilities(ld::Section::READ | ld::Section::EXECUTE);

    ld::Function* currentFunction = NULL;
    
    // -- debug --
    logger->trace("created default code section object with read/execute attributes.");
    object->addSection(currentSection); // Add the section to the object file.

    // Parse
    bool override = false;
    while (tokenize(override) != 0)
    {
        override = false;
        switch (token)
        {
            case TOKEN_SECTION:
            {
                /**
                 * Enter the parsing state corresponding to a section. Now is
                 * expecting a string literal representing the section name,
                 * and parsing continues.
                 */
                core::String sectionName;
                if (scanner_lex(scanner) == TOKEN_STRING)
                {
                    sectionName = scanner_get_text(YYSCAN(scanner));

                    if (currentSection != NULL)
                    {
                        object->addSection(currentSection);
                    }

                    //TODO: Check if we are adding to the same default section.
                    currentSection = new ld::Section(sectionName);

                    // -- debug --
                    logger->trace("created section object @0x%p with name '%s'.", currentSection, sectionName.toCharArray());

                    if (lookAhead() == TOKEN_ATTRIBUTES)
                    {
                        if (tokenize(true) == TOKEN_STRING)
                        {
                            core::String attributes = text();
                            currentSection->setCapabilities(ld::Section::capabilitiesFromString(attributes));

                            logger->trace("set attributes for section '%s': <%s>",
                                          currentSection->getSectionName().toCharArray(),
                                          attributes.toCharArray());
                        }
                        else
                        {
                            error("expected a string with valid section attributes (r, w, x). Got '%s'.", text());
                        }
                    }
                }
                else
                {
                    error("expected a valid section identifier.");
                }
                break;
            }
            case TOKEN_DEF:
            {
                /**
                 * We are defining a function.
                 */
                core::String identifier;
                if (tokenize() == TOKEN_IDENTIFIER)
                {
                    /**
                     * Ok, we have correctly defined a function header.
                     * Now we need to match a sequence of operations.
                     */
                    identifier = scanner_get_text(scanner);

                    if (currentFunction != NULL)
                    {
                        error("attempted to declare a function while still on another function's body. Unbalanced \".def/.endef\"");
                    }
                    else
                    {
                        currentFunction = new ld::Function(identifier);
                        logger->trace("created a function object @0x%p with name %s.",
                                      currentFunction, currentFunction->getName().toCharArray());
                    }
                }
                else
                {
                    error("expected a valid function identifier, got '%s'.", text());
                }
                break;
            }
            case TOKEN_ENDEF:
            {
                /* We have finished with our function. Add it to the current
                 * section. If the current section does not have execution
                 * privileges emit a warning.
                 */
                if (currentSection->hasCapability(ld::Section::EXECUTE) == false)
                {
                    warn("added code to a section without execution capabilities (offending function: '%s') at section <%s>.",
                         currentFunction->getName().toCharArray(),
                         currentSection->getSectionName().toCharArray());
                }
                currentSection->addSymbol(currentFunction);

                // Make the pointer to the current function NULL.
                currentFunction = NULL;

                // Break
                break;
            }
            default:
            {
                if (token > __TOKEN_BINARY_MIN && token < __TOKEN_BINARY_MAX)
                {
                    // Binary operations
                    int suffix = tokenize();
                    if (suffix >= TOKEN_SUFFIX_BYTE && suffix <= TOKEN_SUFFIX_DOUBLE)
                    {

                    }
                    else
                    {
                        error("invalid instruction suffix (%s). Expecting a valid suffix (b, w, l, q, d, f)",
                              text());
                    }
                }
                else if (token > __TOKEN_UNARY_MIN && token < __TOKEN_UNARY_MAX)
                {
                    // Unary operations
                    bool hasSuffix = false;
                    bool needSuffix = false;

                    // Save the token!
                    int insn = token;

                    // Check if we have a suffix
                    int suffix = lookAhead();
                    if (suffix >= TOKEN_SUFFIX_BYTE && suffix <= TOKEN_SUFFIX_DOUBLE)
                    {
                        hasSuffix = true;
                    }

                    switch (insn)
                    {
                        case TOKEN_RET:
                            needSuffix = true;
                            break;
                    }

                    if (hasSuffix && !needSuffix)
                    {
                        error("invalid suffix instruction not requiring a suffix.");
                    }
                    else
                    {
                        if (!hasSuffix && needSuffix)
                        {
                            error("missing instruction suffix for current instruction (b, w, l, q, f, d).");
                        }
                        else
                        {
                            // Set the override flag to true, else we won't parse correctly.
                            override = true;

                            // Create and add the instruction!
                            vm::vm_byte_t opcode = tokenToInstruction(insn, hasSuffix ? suffix : AMANDA_ICONV_NO_SUFFIX);
                            currentFunction->emit(new as::Instruction(opcode));
                        }
                    }
                }
                else
                {
                    // Error
                    error("unexpected syntax error.");
                }
                break;
            }
        }
    }

    // Do some clean-up!
    // 1. Insert the last used section (it wouldn't be inserted otherwise)
    if (currentSection != NULL)
        object->addSection(currentSection);

    // Last but not least. Log.
    logger->trace("finished assembly parsing & analysis. Ready for code generation...");
    logger->trace("created object file with %lu sections.",
                  object->countSections());
    for (ld::SectionTable::const_iterator it = object->getSections().begin(), end = object->getSections().end(); it != end; ++it)
    {
        logger->trace("section: {key: '%s' -> value: %s'} | capabilities: %s",
                      it->first.toCharArray(),
                      it->second->getSectionName().toCharArray(),
                      ld::Section::stringFromCapabilities(it->second->getCapabilities()).toCharArray());
    }
}

void AssemblerParser::error(const core::String& message, ...)
{
    yyscan_t sc = YYSCAN(scanner);
    va_list va;
    va_start(va, message);
    core::String formatted = core::String::makeFormattedStringWithArguments(message, va);

    logger->error("%s: %d:%d: syntax error, %s",
                  input->getPath().toCharArray(),
                  scanner_get_lineno(sc),
                  scanner_get_column(sc),
                  formatted.toCharArray());

    va_end(va);
    throw core::Exception(core::String::makeFormattedString("syntax error: %s (last input \"%s\").", formatted.toCharArray(), text()));
}

void AssemblerParser::warn(const core::String& message, ...)
{
    yyscan_t sc = YYSCAN(scanner);
    va_list va;
    va_start(va, message);
    core::String formatted = core::String::makeFormattedStringWithArguments(message, va);

    logger->warn("%s: %d:%d: %s",
                 input->getPath().toCharArray(),
                 scanner_get_lineno(sc),
                 scanner_get_column(sc),
                 formatted.toCharArray());

    va_end(va);
}

int AssemblerParser::lookAhead()
{
    // Set the feeding variable to false, since the next tokenization wont need
    // any lexer call.
    feeding = false;

    token = scanner_lex(YYSCAN(scanner));
    return token;
}

const char* AssemblerParser::text()
{
    return scanner_get_text(YYSCAN(scanner));
}

int AssemblerParser::tokenize(bool override)
{
    // Only read a token if we need to feed.
    if (feeding || override)
    {
        token = scanner_lex(YYSCAN(scanner));
    }

    // Reset the feeding flag, now we're hungry since we have consumed the token.
    feeding = true;
    return token;
}
