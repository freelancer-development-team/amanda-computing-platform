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
 * File:   Integer.h
 * Author: Javier Marrero
 *
 * Created on April 16, 2022, 11:18 PM
 */

#ifndef INTEGER_H
#define INTEGER_H

#include <amanda-vm-c/sdk-types.h>
#include <amanda-vm/Object.h>
#include <amanda-vm/String.h>
#include <amanda-vm/Exception.h>
#include <amanda-vm/IllegalArgumentException.h>

#include <cerrno>

namespace amanda
{

/**
 * Functions declared in this name space defines conversion functions for
 * C++ primitive types that do not rely on higher infrastructure.
 */
namespace util
{

/**
 * Convert a UTF8 encoded stream of bytes into 
 * 
 * @param bytes
 * @return
 */
unsigned long long fromStreamOfBytes(const char* bytes);

}

namespace core
{

/**
 * The integer class is an utility class that allows boxing/un-boxing of standard
 * integer types. It allows parsing integers in several notations, currently
 * decimal, hexadecimal, octal and binary.
 * <p>
 * This class is designed as a template, and its specialization are supposed to
 * handle the particular cases. It uses a template argument for saving space
 * and better suit the runtime representation of the handled integer.
 *
 * @author J. Marrero
 */
template <typename T>
class Integer : public Object
{

    AMANDA_OBJECT(Integer<T>, Object)
public:

    /**
     * Returns an unsigned long long after parsing the provided string. If radix
     * is omitted, base 10 is assumed.
     * 
     * @param rhs
     * @param radix
     * @return
     */
    static long long parseInt(const core::String& rhs, unsigned short radix = 10)
    {
        long long result = strtoll(rhs.toCharArray(), NULL, radix);
        if (errno == ERANGE)
            throw IllegalArgumentException("Illegal integer literal");

        return result;
    }

    /**
     * Similar to the <code>parseInt</code> method, but returns an <code>
     * unsigned long long int</code> instead.
     * 
     * @param rhs
     * @param radix
     * @return
     */
    static unsigned long long parseUnsignedInt(const core::String& rhs, unsigned short radix = 10)
    {
        unsigned long long result = strtoull(rhs.toCharArray(), NULL, radix);
        if (errno == ERANGE)
            throw IllegalArgumentException("Illegal unsigned integer literal");

        return result;
    }

    /**
     * Return the size of a string large enough to hold the given number
     *
     * @param num the number we want the string length for (must be positive)
     * @param radix the radix (base) that will be used for the string
     * @return a size sufficient for a string of num
     */
    static unsigned stringSize(T num, unsigned radix)
    {
        int exp;
        if (radix < 4)
        {
            exp = 1;
        }
        else if (radix < 8)
        {
            exp = 2;
        }
        else if (radix < 16)
        {
            exp = 3;
        }
        else if (radix < 32)
        {
            exp = 4;
        }
        else
        {
            exp = 5;
        }
        unsigned size = 0;
        do
        {
            num >>= exp;
            size++;
        }
        while (num != 0);

        return size;
    }

    /**
     * Returns an integer object that is result of parsing the string contained
     * in the passed argument.
     * 
     * @param rhs
     * @return
     */
    static Integer<T> valueOf(const core::String& rhs)
    {
        return Integer<T>(rhs);
    }

    /**
     * Creates a new <code>Integer</code> object from an integral type.
     * 
     * @param value
     */
    Integer(const T value) : value(value) { }

    /**
     * Parses and builds a new <code>Integer</code> from its string representation.
     * 
     * @param value
     */
    Integer(const String& value) : value((T) util::fromStreamOfBytes(value.toCharArray())) { }

    /// Default copy constructor

    Integer(const Integer<T>& rhs) : value(rhs) { }

    /// Retrieves the value of the integer (un-boxes the integer)

    T get() const
    {
        return value;
    }

    /// Computes the maximum representable value and returns it.

    T max()
    {
        return (T) (1ULL << (sizeof (T) * CHAR_BIT));
    }

protected:

    T value;

} ;

/* Typedefs for various integer types. */
typedef Integer<unsigned char>      Byte;
typedef Integer<unsigned short>     UShort;
typedef Integer<unsigned int>       UInt;
typedef Integer<unsigned long>      ULong;
typedef Integer<unsigned long long> UBigLong;

typedef Integer<short>          Short;
typedef Integer<int>            Int;
typedef Integer<long>           Long;
typedef Integer<long long>      BigLong;

}
}

#endif /* INTEGER_H */

