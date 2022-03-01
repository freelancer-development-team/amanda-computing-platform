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
 * File:   String.h
 * Author: Javier Marrero
 *
 * Created on February 13, 2022, 5:04 PM
 */

#ifndef STRING_H
#define STRING_H

#include <amanda-vm/ReferenceCounted.h>
#include <amanda-vm-c/sdk-definitions.h>

#include <cassert>
#include <cstdarg>
#include <cstring>
#include <cctype>

namespace amanda
{

namespace core
{

static const int CONVERSION_BUFFER_LENGTH = 128;
static const int MATRIX_CONVERSION_BUFFER_LENGTH = 256;

class String : public ReferenceCounted
{
public:

    /// Construct empty.
    String() :
        bufferLength(0),
        bufferCapacity(0),
        buffer(&endZero)
    {
    }

    /// Construct from another string.
    String(const String& str) :
        bufferLength(0),
        bufferCapacity(0),
        buffer(&endZero)
    {
        *this = str;
    }

    /// Construct from a C string.
    String(const char* str) :
        bufferLength(0),
        bufferCapacity(0),
        buffer(&endZero)
    {
        *this = str;
    }

    /// Construct from a C string.
    String(char* str) :
        bufferLength(0),
        bufferCapacity(0),
        buffer(&endZero)
    {
        *this = (const char*)str;
    }

    /// Construct from a char array and length.
    String(const char* str, unsigned length) :
        bufferLength(0),
        bufferCapacity(0),
        buffer(&endZero)
    {
        resize(length);
        copyCharacters(buffer, str, length);
    }

    /// Construct from a null-terminated wide character array.
    String(const wchar_t* str) :
        bufferLength(0),
        bufferCapacity(0),
        buffer(&endZero)
    {
        setUtf8FromWChar(str);
    }

    /// Construct from a null-terminated wide character array.
    String(wchar_t* str) :
        bufferLength(0),
        bufferCapacity(0),
        buffer(&endZero)
    {
        setUtf8FromWChar(str);
    }

    /// Construct from an integer.
    explicit String(int value);
    /// Construct from a short integer.
    explicit String(short value);
    /// Construct from a long integer.
    explicit String(long value);
    /// Construct from a long long integer.
    explicit String(long long value);
    /// Construct from an unsigned integer.
    explicit String(unsigned value);
    /// Construct from an unsigned short integer.
    explicit String(unsigned short value);
    /// Construct from an unsigned long integer.
    explicit String(unsigned long value);
    /// Construct from an unsigned long long integer.
    explicit String(unsigned long long value);
    /// Construct from a float.
    explicit String(float value);
    /// Construct from a double.
    explicit String(double value);
    /// Construct from a bool.
    explicit String(bool value);
    /// Construct from a character.
    explicit String(char value);
    /// Construct from a character and fill length.
    explicit String(char value, unsigned length);

    /// Construct from a convertable value.
    template <class T> explicit String(const T& value) :
        bufferLength(0),
        bufferCapacity(0),
        buffer(&endZero)
    {
        *this = value.toString();
    }

    /// Destruct.
    ~String()
    {
        if (bufferCapacity)
            delete[] buffer;
    }

    /// Assign a string.
    String& operator =(const String& rhs)
    {
        resize(rhs.bufferLength);
        copyCharacters(buffer, rhs.buffer, rhs.bufferLength);

        return *this;
    }

    /// Assign a C string.
    String& operator =(const char* rhs)
    {
        unsigned rhsLength = getCharArrayLength(rhs);
        resize(rhsLength);
        copyCharacters(buffer, rhs, rhsLength);

        return *this;
    }

    /// Add-assign a string.
    String& operator +=(const String& rhs)
    {
        unsigned oldLength = bufferLength;
        resize(bufferLength + rhs.bufferLength);
        copyCharacters(buffer + oldLength, rhs.buffer, rhs.bufferLength);

        return *this;
    }

    /// Add-assign a C string.
    String& operator +=(const char* rhs)
    {
        unsigned rhsLength = getCharArrayLength(rhs);
        unsigned oldLength = bufferLength;
        resize(bufferLength + rhsLength);
        copyCharacters(buffer + oldLength, rhs, rhsLength);

        return *this;
    }

    /// Add-assign a character.
    String& operator +=(char rhs)
    {
        unsigned oldLength = bufferLength;
        resize(bufferLength + 1);
        buffer[oldLength] = rhs;

        return *this;
    }

    /// Add-assign (concatenate as string) an integer.
    String& operator +=(int rhs);
    /// Add-assign (concatenate as string) a short integer.
    String& operator +=(short rhs);
    /// Add-assign (concatenate as string) a long integer.
    String& operator +=(long rhs);
    /// Add-assign (concatenate as string) a long long integer.
    String& operator +=(long long rhs);
    /// Add-assign (concatenate as string) an unsigned integer.
    String& operator +=(unsigned rhs);
    /// Add-assign (concatenate as string) a short unsigned integer.
    String& operator +=(unsigned short rhs);
    /// Add-assign (concatenate as string) a long unsigned integer.
    String& operator +=(unsigned long rhs);
    /// Add-assign (concatenate as string) a long long unsigned integer.
    String& operator +=(unsigned long long rhs);
    /// Add-assign (concatenate as string) a float.
    String& operator +=(float rhs);
    /// Add-assign (concatenate as string) a bool.
    String& operator +=(bool rhs);

    /// Add-assign (concatenate as string) an arbitrary type.
    template <class T> String operator +=(const T& rhs) { return *this += rhs.ToString(); }

    /// Add a string.
    String operator +(const String& rhs) const
    {
        String ret;
        ret.resize(bufferLength + rhs.bufferLength);
        copyCharacters(ret.buffer, buffer, bufferLength);
        copyCharacters(ret.buffer + bufferLength, rhs.buffer, rhs.bufferLength);

        return ret;
    }

    /// Add a C string.
    String operator +(const char* rhs) const
    {
        unsigned rhsLength = getCharArrayLength(rhs);
        String ret;
        ret.resize(bufferLength + rhsLength);
        copyCharacters(ret.buffer, buffer, bufferLength);
        copyCharacters(ret.buffer + bufferLength, rhs, rhsLength);

        return ret;
    }

    /// Test for equality with another string.
    bool operator ==(const String& rhs) const { return strcmp(toCharArray(), rhs.toCharArray()) == 0; }

    /// Test for inequality with another string.
    bool operator !=(const String& rhs) const { return strcmp(toCharArray(), rhs.toCharArray()) != 0; }

    /// Test if string is less than another string.
    bool operator <(const String& rhs) const { return strcmp(toCharArray(), rhs.toCharArray()) < 0; }

    /// Test if string is greater than another string.
    bool operator >(const String& rhs) const { return strcmp(toCharArray(), rhs.toCharArray()) > 0; }

    /// Test for equality with a C string.
    bool operator ==(const char* rhs) const { return strcmp(toCharArray(), rhs) == 0; }

    /// Test for inequality with a C string.
    bool operator !=(const char* rhs) const { return strcmp(toCharArray(), rhs) != 0; }

    /// Test if string is less than a C string.
    bool operator <(const char* rhs) const { return strcmp(toCharArray(), rhs) < 0; }

    /// Test if string is greater than a C string.
    bool operator >(const char* rhs) const { return strcmp(toCharArray(), rhs) > 0; }

    /// Return char at index.
    char& operator [](unsigned index)
    {
        assert(index < bufferLength);
        return buffer[index];
    }

    /// Return const char at index.
    const char& operator [](unsigned index) const
    {
        assert(index < bufferLength);
        return buffer[index];
    }

    /// Return char at index.
    char& charAt(unsigned index)
    {
        assert(index < bufferLength);
        return buffer[index];
    }

    /// Return const char at index.
    const char& charAt(unsigned index) const
    {
        assert(index < bufferLength);
        return buffer[index];
    }

    /// Replace all occurrences of a character.
    void replace(char replaceThis, char replaceWith, bool caseSensitive = true);
    /// Replace all occurrences of a string.
    void replace(const String& replaceThis, const String& replaceWith, bool caseSensitive = true);
    /// Replace a substring.
    void replace(unsigned pos, unsigned length, const String& replaceWith);
    /// Replace a substring with a C string.
    void replace(unsigned pos, unsigned length, const char* replaceWith);
    /// Replace a substring by iterators.
    
    /// Return a string with all occurrences of a character replaced.
    String replaced(char replaceThis, char replaceWith, bool caseSensitive = true) const;
    /// Return a string with all occurrences of a string replaced.
    String replace(const String& replaceThis, const String& replaceWith, bool caseSensitive = true) const;
    /// Append a string.
    String& append(const String& str);
    /// Append a C string.
    String& append(const char* str);
    /// Append a character.
    String& append(char c);
    /// Append characters.
    String& append(const char* str, unsigned length);
    /// Insert a string.
    void insert(unsigned pos, const String& str);
    /// Insert a character.
    void insert(unsigned pos, char c);
    
    /// Resize the string.
    void resize(unsigned newLength);
    /// Set new capacity.
    void reserve(unsigned newCapacity);
    /// Reallocate so that no extra memory is used.
    void compact();
    /// Clear the string.
    void clear();
    /// Swap with another string.
    void swap(String& str);

    /// Return first char, or 0 if empty.
    char front() const { return buffer[0]; }

    /// Return last char, or 0 if empty.
    char back() const { return bufferLength ? buffer[bufferLength - 1] : buffer[0]; }

    /// Return a substring from position to end.
    String substring(unsigned pos) const;
    /// Return a substring with length from position.
    String substring(unsigned pos, unsigned length) const;
    /// Return string with whitespace trimmed from the beginning and the end.
    String trimmed() const;
    /// Return string in uppercase.
    String toUpper() const;
    /// Return string in lowercase.
    String toLower() const;
    
    /// Return index to the first occurrence of a string, or NPOS if not found.
    unsigned find(const String& str, unsigned startPos = 0, bool caseSensitive = true) const;
    /// Return index to the first occurrence of a character, or NPOS if not found.
    unsigned find(char c, unsigned startPos = 0, bool caseSensitive = true) const;
    /// Return index to the last occurrence of a string, or NPOS if not found.
    unsigned findLast(const String& str, unsigned startPos = NPOS, bool caseSensitive = true) const;
    /// Return index to the last occurrence of a character, or NPOS if not found.
    unsigned findLast(char c, unsigned startPos = NPOS, bool caseSensitive = true) const;
    /// Return whether starts with a string.
    bool startsWith(const String& str, bool caseSensitive = true) const;
    /// Return whether ends with a string.
    bool endsWith(const String& str, bool caseSensitive = true) const;

    /// Returns true if both strings are equals
    bool equals(const String& rhs) { return (compare(rhs, true) == 0); }

    /// Return the C string.
    const char* toCharArray() const { return buffer; }

    /// Return length.
    unsigned length() const { return bufferLength; }

    /// Return buffer capacity.
    unsigned capacity() const { return bufferCapacity; }

    /// Return whether the string is empty.
    bool isEmpty() const { return bufferLength == 0; }

    /// Return comparison result with a string.
    int compare(const String& str, bool caseSensitive = true) const;
    /// Return comparison result with a C string.
    int compare(const char* str, bool caseSensitive = true) const;

    /// Return whether contains a specific occurrence of a string.
    bool contains(const String& str, bool caseSensitive = true) const { return find(str, 0, caseSensitive) != NPOS; }

    /// Return whether contains a specific character.
    bool contains(char c, bool caseSensitive = true) const { return find(c, 0, caseSensitive) != NPOS; }

    /// Construct UTF8 content from Latin1.
    void setUtf8FromLatin1(const char* str);
    /// Construct UTF8 content from wide characters.
    void setUtf8FromWChar(const wchar_t* str);
    /// Calculate number of characters in UTF8 content.
    unsigned lengthUtf8() const;
    /// Return byte offset to char in UTF8 content.
    unsigned byteOffsetUtf8(unsigned index) const;
    /// Return next Unicode character from UTF8 content and increase byte offset.
    unsigned nextUtf8Character(unsigned& byteOffset) const;
    /// Return Unicode character at index from UTF8 content.
    unsigned utf8CharAt(unsigned index) const;
    /// Replace Unicode character at index from UTF8 content.
    void replaceUtf8(unsigned index, unsigned unicodeChar);
    /// Append Unicode character at the end as UTF8.
    String& appendUtf8(unsigned unicodeChar);
    /// Return a UTF8 substring from position to end.
    String substringUtf8(unsigned pos) const;
    /// Return a UTF8 substring with length from position.
    String substringUtf8(unsigned pos, unsigned length) const;

    /// Return hash value for HashSet & HashMap.
    unsigned hashCode() const
    {
        unsigned hash = 0;
        const char* ptr = buffer;
        while (*ptr)
        {
            hash = *ptr + (hash << 6) + (hash << 16) - hash;
            ++ptr;
        }

        return hash;
    }

    /// Encode Unicode character to UTF8. Pointer will be incremented.
    static void encodeUtf8(char*& dest, unsigned unicodeChar);
    /// Decode Unicode character from UTF8. Pointer will be incremented.
    static unsigned decodeUtf8(const char*& src);
#ifdef _W32
    /// Encode Unicode character to UTF16. Pointer will be incremented.
    static void encodeUtf16(wchar_t*& dest, unsigned unicodeChar);
    /// Decode Unicode character from UTF16. Pointer will be incremented.
    static unsigned decodeUtf16(const wchar_t*& src);
#endif

    /// Return length of a C string.
    static unsigned getCharArrayLength(const char* str) { return str ? (unsigned)strlen(str) : 0; }

    /// Append to string using formatting.
    String& appendWithFormat(const char* formatString, ...);
    /// Append to string using variable arguments.
    String& appendWithFormatArguments(const char* formatString, va_list args);

    /// Compare two C strings.
    static int compare(const char* str1, const char* str2, bool caseSensitive);

    /// Position for "not found."
    static const unsigned NPOS = 0xffffffff;
    /// Initial dynamic allocation size.
    static const unsigned MIN_CAPACITY = 8;
    /// Empty string.
    static const String EMPTY;

private:
    /// Move a range of characters within the string.
    void moveRange(unsigned dest, unsigned src, unsigned count)
    {
        if (count)
            memmove(buffer + dest, buffer + src, count);
    }

    /// Copy chars from one buffer to another.
    static void copyCharacters(char* dest, const char* src, unsigned count)
    {
#ifdef _MSC_VER
        if (count)
            memcpy(dest, src, count);
#else
        char* end = dest + count;
        while (dest != end)
        {
            *dest = *src;
            ++dest;
            ++src;
        }
#endif
    }

    /// Replace a substring with another substring.
    void replace(unsigned pos, unsigned length, const char* srcStart, unsigned srcLength);

    /// String length.
    unsigned bufferLength;
    /// Capacity, zero if buffer not allocated.
    unsigned bufferCapacity;
    /// String buffer, null if not allocated.
    char* buffer;

    /// End zero for empty strings.
    static char endZero;
};

/// Add a string to a C string.
inline String operator +(const char* lhs, const String& rhs)
{
    String ret(lhs);
    ret += rhs;
    return ret;
}

/// Add a string to a wide char C string.
inline String operator +(const wchar_t* lhs, const String& rhs)
{
    String ret(lhs);
    ret += rhs;
    return ret;
}

}
}

#endif /* STRING_H */

