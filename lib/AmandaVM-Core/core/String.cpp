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

#include <amanda-vm/String.h>

// C++
#include <cstdio>
#include <cstdlib>

using amanda::core::String;

char String::endZero = 0;
const String String::EMPTY;

String String::makeFormattedStringWithArguments(const core::String& fmt, va_list va)
{
    size_t limit = 0x10 * fmt.length();
    char* buffer = static_cast<char*>(std::calloc(limit, sizeof (char)));

    ::vsnprintf(buffer, limit, fmt.toCharArray(), va);
    String result(buffer);

    std::free(buffer);
    return result;
}

String String::makeFormattedString(const core::String& fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    String result = makeFormattedStringWithArguments(fmt, va);
    va_end(va);

    return result;
}

String::String(int value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    char tempBuffer[CONVERSION_BUFFER_LENGTH];
    sprintf(tempBuffer, "%d", value);
    *this = tempBuffer;
}

String::String(short value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    char tempBuffer[CONVERSION_BUFFER_LENGTH];
    sprintf(tempBuffer, "%d", value);
    *this = tempBuffer;
}

String::String(long value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    char tempBuffer[CONVERSION_BUFFER_LENGTH];
    sprintf(tempBuffer, "%ld", value);
    *this = tempBuffer;
}

String::String(long long value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    char tempBuffer[CONVERSION_BUFFER_LENGTH];
    sprintf(tempBuffer, "%lld", value);
    *this = tempBuffer;
}

String::String(unsigned value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    char tempBuffer[CONVERSION_BUFFER_LENGTH];
    sprintf(tempBuffer, "%u", value);
    *this = tempBuffer;
}

String::String(unsigned short value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    char tempBuffer[CONVERSION_BUFFER_LENGTH];
    sprintf(tempBuffer, "%u", value);
    *this = tempBuffer;
}

String::String(unsigned long value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    char tempBuffer[CONVERSION_BUFFER_LENGTH];
    sprintf(tempBuffer, "%lu", value);
    *this = tempBuffer;
}

String::String(unsigned long long value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    char tempBuffer[CONVERSION_BUFFER_LENGTH];
    sprintf(tempBuffer, "%llu", value);
    *this = tempBuffer;
}

String::String(float value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    char tempBuffer[CONVERSION_BUFFER_LENGTH];
    sprintf(tempBuffer, "%g", value);
    *this = tempBuffer;
}

String::String(double value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    char tempBuffer[CONVERSION_BUFFER_LENGTH];
    sprintf(tempBuffer, "%.15g", value);
    *this = tempBuffer;
}

String::String(bool value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    if (value)
        * this = "true";
    else
        *this = "false";
}

String::String(char value) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    resize(1);
    buffer[0] = value;
}

String::String(char value, unsigned length) :
bufferLength(0),
bufferCapacity(0),
buffer(&endZero)
{
    resize(length);
    for (unsigned i = 0; i < length; ++i)
        buffer[i] = value;
}

String& String::operator +=(int rhs)
{
    return *this += String(rhs);
}

String& String::operator +=(short rhs)
{
    return *this += String(rhs);
}

String& String::operator +=(long rhs)
{
    return *this += String(rhs);
}

String& String::operator +=(long long rhs)
{
    return *this += String(rhs);
}

String& String::operator +=(unsigned rhs)
{
    return *this += String(rhs);
}

String& String::operator +=(unsigned short rhs)
{
    return *this += String(rhs);
}

String& String::operator +=(unsigned long rhs)
{
    return *this += String(rhs);
}

String& String::operator +=(unsigned long long rhs)
{
    return *this += String(rhs);
}

String& String::operator +=(float rhs)
{
    return *this += String(rhs);
}

String& String::operator +=(bool rhs)
{
    return *this += String(rhs);
}

void String::replace(char replaceThis, char replaceWith, bool caseSensitive)
{
    if (caseSensitive)
    {
        for (unsigned i = 0; i < bufferLength; ++i)
        {
            if (buffer[i] == replaceThis)
                buffer[i] = replaceWith;
        }
    }
    else
    {
        replaceThis = (char) tolower(replaceThis);
        for (unsigned i = 0; i < bufferLength; ++i)
        {
            if (tolower(buffer[i]) == replaceThis)
                buffer[i] = replaceWith;
        }
    }
}

void String::replace(const String& replaceThis, const String& replaceWith, bool caseSensitive)
{
    unsigned nextPos = 0;

    while (nextPos < bufferLength)
    {
        unsigned pos = find(replaceThis, nextPos, caseSensitive);
        if (pos == NPOS)
            break;
        replace(pos, replaceThis.bufferLength, replaceWith);
        nextPos = pos + replaceWith.bufferLength;
    }
}

void String::replace(unsigned pos, unsigned length, const String& replaceWith)
{
    // If substring is illegal, do nothing
    if (pos + length > bufferLength)
        return;

    replace(pos, length, replaceWith.buffer, replaceWith.bufferLength);
}

void String::replace(unsigned pos, unsigned length, const char* replaceWith)
{
    // If substring is illegal, do nothing
    if (pos + length > bufferLength)
        return;

    replace(pos, length, replaceWith, getCharArrayLength(replaceWith));
}

String String::replaced(char replaceThis, char replaceWith, bool caseSensitive) const
{
    String ret(*this);
    ret.replace(replaceThis, replaceWith, caseSensitive);
    return ret;
}

String String::replace(const String& replaceThis, const String& replaceWith, bool caseSensitive) const
{
    String ret(*this);
    ret.replace(replaceThis, replaceWith, caseSensitive);
    return ret;
}

String& String::append(const String& str)
{
    return *this += str;
}

String& String::append(const char* str)
{
    return *this += str;
}

String& String::append(char c)
{
    return *this += c;
}

String& String::append(const char* str, unsigned length)
{
    if (str)
    {
        unsigned oldLength = bufferLength;
        resize(oldLength + length);
        copyCharacters(&buffer[oldLength], str, length);
    }
    return *this;
}

void String::insert(unsigned pos, const String& str)
{
    if (pos > bufferLength)
        pos = bufferLength;

    if (pos == bufferLength)
        (*this) += str;
    else
        replace(pos, 0, str);
}

void String::insert(unsigned pos, char c)
{
    if (pos > bufferLength)
        pos = bufferLength;

    if (pos == bufferLength)
        (*this) += c;
    else
    {
        unsigned oldLength = bufferLength;
        resize(bufferLength + 1);
        moveRange(pos + 1, pos, oldLength - pos);
        buffer[pos] = c;
    }
}

void String::resize(unsigned newLength)
{
    if (!bufferCapacity)
    {
        // If zero length requested, do not allocate buffer yet
        if (!newLength)
            return;

        // Calculate initial capacity
        bufferCapacity = newLength + 1;
        if (bufferCapacity < MIN_CAPACITY)
            bufferCapacity = MIN_CAPACITY;

        buffer = new char[bufferCapacity];
    }
    else
    {
        if (newLength && bufferCapacity < newLength + 1)
        {
            // Increase the capacity with half each time it is exceeded
            while (bufferCapacity < newLength + 1)
                bufferCapacity += (bufferCapacity + 1) >> 1;

            char* newBuffer = new char[bufferCapacity];
            // Move the existing data to the new buffer, then delete the old buffer
            if (bufferLength)
                copyCharacters(newBuffer, buffer, bufferLength);
            delete[] buffer;

            buffer = newBuffer;
        }
    }

    buffer[newLength] = 0;
    bufferLength = newLength;
}

void String::reserve(unsigned newCapacity)
{
    if (newCapacity < bufferLength + 1)
        newCapacity = bufferLength + 1;
    if (newCapacity == bufferCapacity)
        return;

    char* newBuffer = new char[newCapacity];
    // Move the existing data to the new buffer, then delete the old buffer
    copyCharacters(newBuffer, buffer, bufferLength + 1);
    if (bufferCapacity)
        delete[] buffer;

    bufferCapacity = newCapacity;
    buffer = newBuffer;
}

void String::compact()
{
    if (bufferCapacity)
        reserve(bufferLength + 1);
}

void String::clear()
{
    resize(0);
}

void String::swap(String& str)
{

}

String String::substring(unsigned pos) const
{
    if (pos < bufferLength)
    {
        String ret;
        ret.resize(bufferLength - pos);
        copyCharacters(ret.buffer, buffer + pos, ret.bufferLength);

        return ret;
    }
    else
        return String();
}

String String::substringl(unsigned pos, unsigned length) const
{
    if (pos < bufferLength)
    {
        String ret;
        if (pos + length > bufferLength)
            length = bufferLength - pos;
        ret.resize(length);
        copyCharacters(ret.buffer, buffer + pos, ret.bufferLength);

        return ret;
    }
    else
        return String();
}

String String::substring(unsigned start, unsigned end) const
{
    return substringl(start, end - start);
}

String String::trimmed() const
{
    unsigned trimStart = 0;
    unsigned trimEnd = bufferLength;

    while (trimStart < trimEnd)
    {
        char c = buffer[trimStart];
        if (c != ' ' && c != 9)
            break;
        ++trimStart;
    }
    while (trimEnd > trimStart)
    {
        char c = buffer[trimEnd - 1];
        if (c != ' ' && c != 9)
            break;
        --trimEnd;
    }

    return substringl(trimStart, trimEnd - trimStart);
}

String String::toLower() const
{
    String ret(*this);
    for (unsigned i = 0; i < ret.bufferLength; ++i)
        ret[i] = (char) tolower(buffer[i]);

    return ret;
}

String String::toUpper() const
{
    String ret(*this);
    for (unsigned i = 0; i < ret.bufferLength; ++i)
        ret[i] = (char) toupper(buffer[i]);

    return ret;
}

unsigned String::find(char c, unsigned startPos, bool caseSensitive) const
{
    if (caseSensitive)
    {
        for (unsigned i = startPos; i < bufferLength; ++i)
        {
            if (buffer[i] == c)
                return i;
        }
    }
    else
    {
        c = (char) tolower(c);
        for (unsigned i = startPos; i < bufferLength; ++i)
        {
            if (tolower(buffer[i]) == c)
                return i;
        }
    }

    return NPOS;
}

unsigned String::find(const String& str, unsigned startPos, bool caseSensitive) const
{
    if (!str.bufferLength || str.bufferLength > bufferLength)
        return NPOS;

    char first = str.buffer[0];
    if (!caseSensitive)
        first = (char) tolower(first);

    for (unsigned i = startPos; i <= bufferLength - str.bufferLength; ++i)
    {
        char c = buffer[i];
        if (!caseSensitive)
            c = (char) tolower(c);

        if (c == first)
        {
            unsigned skip = NPOS;
            bool found = true;
            for (unsigned j = 1; j < str.bufferLength; ++j)
            {
                c = buffer[i + j];
                char d = str.buffer[j];
                if (!caseSensitive)
                {
                    c = (char) tolower(c);
                    d = (char) tolower(d);
                }

                if (skip == NPOS && c == first)
                    skip = i + j - 1;

                if (c != d)
                {
                    found = false;
                    if (skip != NPOS)
                        i = skip;
                    break;
                }
            }
            if (found)
                return i;
        }
    }

    return NPOS;
}

unsigned String::findLast(char c, unsigned startPos, bool caseSensitive) const
{
    if (startPos >= bufferLength)
        startPos = bufferLength - 1;

    if (caseSensitive)
    {
        for (unsigned i = startPos; i < bufferLength; --i)
        {
            if (buffer[i] == c)
                return i;
        }
    }
    else
    {
        c = (char) tolower(c);
        for (unsigned i = startPos; i < bufferLength; --i)
        {
            if (tolower(buffer[i]) == c)
                return i;
        }
    }

    return NPOS;
}

unsigned String::findLast(const String& str, unsigned startPos, bool caseSensitive) const
{
    if (!str.bufferLength || str.bufferLength > bufferLength)
        return NPOS;
    if (startPos > bufferLength - str.bufferLength)
        startPos = bufferLength - str.bufferLength;

    char first = str.buffer[0];
    if (!caseSensitive)
        first = (char) tolower(first);

    for (unsigned i = startPos; i < bufferLength; --i)
    {
        char c = buffer[i];
        if (!caseSensitive)
            c = (char) tolower(c);

        if (c == first)
        {
            bool found = true;
            for (unsigned j = 1; j < str.bufferLength; ++j)
            {
                c = buffer[i + j];
                char d = str.buffer[j];
                if (!caseSensitive)
                {
                    c = (char) tolower(c);
                    d = (char) tolower(d);
                }

                if (c != d)
                {
                    found = false;
                    break;
                }
            }
            if (found)
                return i;
        }
    }

    return NPOS;
}

bool String::startsWith(const String& str, bool caseSensitive) const
{
    return find(str, 0, caseSensitive) == 0;
}

bool String::endsWith(const String& str, bool caseSensitive) const
{
    unsigned pos = findLast(str, length() - 1, caseSensitive);
    return pos != NPOS && pos == length() - str.length();
}

int String::compare(const String& str, bool caseSensitive) const
{
    return compare(toCharArray(), str.toCharArray(), caseSensitive);
}

int String::compare(const char* str, bool caseSensitive) const
{
    return compare(toCharArray(), str, caseSensitive);
}

void String::setUtf8FromLatin1(const char* str)
{
    char temp[7];

    clear();

    if (!str)
        return;

    while (*str)
    {
        char* dest = temp;
        encodeUtf8(dest, (unsigned) *str++);
        *dest = 0;
        append(temp);
    }
}

void String::setUtf8FromWChar(const wchar_t* str)
{
    char temp[7];

    clear();

    if (!str)
        return;

#ifdef _WIN32
    while (*str)
    {
        unsigned unicodeChar = decodeUtf16(str);
        char* dest = temp;
        encodeUtf8(dest, unicodeChar);
        *dest = 0;
        append(temp);
    }
#else
    while (*str)
    {
        char* dest = temp;
        encodeUtf8(dest, (unsigned) *str++);
        *dest = 0;
        append(temp);
    }
#endif
}

unsigned String::lengthUtf8() const
{
    unsigned ret = 0;

    const char* src = buffer;
    if (!src)
        return ret;
    const char* end = buffer + bufferLength;

    while (src < end)
    {
        decodeUtf8(src);
        ++ret;
    }

    return ret;
}

unsigned String::byteOffsetUtf8(unsigned index) const
{
    unsigned byteOffset = 0;
    unsigned utfPos = 0;

    while (utfPos < index && byteOffset < bufferLength)
    {
        nextUtf8Character(byteOffset);
        ++utfPos;
    }

    return byteOffset;
}

unsigned String::nextUtf8Character(unsigned& byteOffset) const
{
    if (!buffer)
        return 0;

    const char* src = buffer + byteOffset;
    unsigned ret = decodeUtf8(src);
    byteOffset = (unsigned) (src - buffer);

    return ret;
}

unsigned String::utf8CharAt(unsigned index) const
{
    unsigned byteOffset = byteOffsetUtf8(index);
    return nextUtf8Character(byteOffset);
}

void String::replaceUtf8(unsigned index, unsigned unicodeChar)
{
    unsigned utfPos = 0;
    unsigned byteOffset = 0;

    while (utfPos < index && byteOffset < bufferLength)
    {
        nextUtf8Character(byteOffset);
        ++utfPos;
    }

    if (utfPos < index)
        return;

    unsigned beginCharPos = byteOffset;
    nextUtf8Character(byteOffset);

    char temp[7];
    char* dest = temp;
    encodeUtf8(dest, unicodeChar);
    *dest = 0;

    replace(beginCharPos, byteOffset - beginCharPos, temp, (unsigned) (dest - temp));
}

String& String::appendUtf8(unsigned unicodeChar)
{
    char temp[7];
    char* dest = temp;
    encodeUtf8(dest, unicodeChar);
    *dest = 0;
    return append(temp);
}

String String::substringUtf8(unsigned pos) const
{
    unsigned utf8Length = lengthUtf8();
    unsigned byteOffset = byteOffsetUtf8(pos);
    String ret;

    while (pos < utf8Length)
    {
        ret.appendUtf8(nextUtf8Character(byteOffset));
        ++pos;
    }

    return ret;
}

String String::substringUtf8(unsigned pos, unsigned length) const
{
    unsigned utf8Length = lengthUtf8();
    unsigned byteOffset = byteOffsetUtf8(pos);
    unsigned endPos = pos + length;
    String ret;

    while (pos < endPos && pos < utf8Length)
    {
        ret.appendUtf8(nextUtf8Character(byteOffset));
        ++pos;
    }

    return ret;
}

void String::encodeUtf8(char*& dest, unsigned unicodeChar)
{
    if (unicodeChar < 0x80)
        *dest++ = unicodeChar;
    else if (unicodeChar < 0x800)
    {
        dest[0] = (char) (0xc0 | ((unicodeChar >> 6) & 0x1f));
        dest[1] = (char) (0x80 | (unicodeChar & 0x3f));
        dest += 2;
    }
    else if (unicodeChar < 0x10000)
    {
        dest[0] = (char) (0xe0 | ((unicodeChar >> 12) & 0xf));
        dest[1] = (char) (0x80 | ((unicodeChar >> 6) & 0x3f));
        dest[2] = (char) (0x80 | (unicodeChar & 0x3f));
        dest += 3;
    }
    else if (unicodeChar < 0x200000)
    {
        dest[0] = (char) (0xf0 | ((unicodeChar >> 18) & 0x7));
        dest[1] = (char) (0x80 | ((unicodeChar >> 12) & 0x3f));
        dest[2] = (char) (0x80 | ((unicodeChar >> 6) & 0x3f));
        dest[3] = (char) (0x80 | (unicodeChar & 0x3f));
        dest += 4;
    }
    else if (unicodeChar < 0x4000000)
    {
        dest[0] = (char) (0xf8 | ((unicodeChar >> 24) & 0x3));
        dest[1] = (char) (0x80 | ((unicodeChar >> 18) & 0x3f));
        dest[2] = (char) (0x80 | ((unicodeChar >> 12) & 0x3f));
        dest[3] = (char) (0x80 | ((unicodeChar >> 6) & 0x3f));
        dest[4] = (char) (0x80 | (unicodeChar & 0x3f));
        dest += 5;
    }
    else
    {
        dest[0] = (char) (0xfc | ((unicodeChar >> 30) & 0x1));
        dest[1] = (char) (0x80 | ((unicodeChar >> 24) & 0x3f));
        dest[2] = (char) (0x80 | ((unicodeChar >> 18) & 0x3f));
        dest[3] = (char) (0x80 | ((unicodeChar >> 12) & 0x3f));
        dest[4] = (char) (0x80 | ((unicodeChar >> 6) & 0x3f));
        dest[5] = (char) (0x80 | (unicodeChar & 0x3f));
        dest += 6;
    }
}

#define GET_NEXT_CONTINUATION_BYTE(ptr) *ptr; if ((unsigned char)*ptr < 0x80 || (unsigned char)*ptr >= 0xc0) return '?'; else ++ptr;

unsigned String::decodeUtf8(const char*& src)
{
    if (src == 0)
        return 0;

    unsigned char char1 = *src++;

    // Check if we are in the middle of a UTF8 character
    if (char1 >= 0x80 && char1 < 0xc0)
    {
        while ((unsigned char) *src >= 0x80 && (unsigned char) *src < 0xc0)
            ++src;
        return '?';
    }

    if (char1 < 0x80)
        return char1;
    else if (char1 < 0xe0)
    {
        unsigned char char2 = GET_NEXT_CONTINUATION_BYTE(src);
        return (unsigned) ((char2 & 0x3f) | ((char1 & 0x1f) << 6));
    }
    else if (char1 < 0xf0)
    {
        unsigned char char2 = GET_NEXT_CONTINUATION_BYTE(src);
        unsigned char char3 = GET_NEXT_CONTINUATION_BYTE(src);
        return (unsigned) ((char3 & 0x3f) | ((char2 & 0x3f) << 6) | ((char1 & 0xf) << 12));
    }
    else if (char1 < 0xf8)
    {
        unsigned char char2 = GET_NEXT_CONTINUATION_BYTE(src);
        unsigned char char3 = GET_NEXT_CONTINUATION_BYTE(src);
        unsigned char char4 = GET_NEXT_CONTINUATION_BYTE(src);
        return (unsigned) ((char4 & 0x3f) | ((char3 & 0x3f) << 6) | ((char2 & 0x3f) << 12) | ((char1 & 0x7) << 18));
    }
    else if (char1 < 0xfc)
    {
        unsigned char char2 = GET_NEXT_CONTINUATION_BYTE(src);
        unsigned char char3 = GET_NEXT_CONTINUATION_BYTE(src);
        unsigned char char4 = GET_NEXT_CONTINUATION_BYTE(src);
        unsigned char char5 = GET_NEXT_CONTINUATION_BYTE(src);
        return (unsigned) ((char5 & 0x3f) | ((char4 & 0x3f) << 6) | ((char3 & 0x3f) << 12) | ((char2 & 0x3f) << 18) |
                           ((char1 & 0x3) << 24));
    }
    else
    {
        unsigned char char2 = GET_NEXT_CONTINUATION_BYTE(src);
        unsigned char char3 = GET_NEXT_CONTINUATION_BYTE(src);
        unsigned char char4 = GET_NEXT_CONTINUATION_BYTE(src);
        unsigned char char5 = GET_NEXT_CONTINUATION_BYTE(src);
        unsigned char char6 = GET_NEXT_CONTINUATION_BYTE(src);
        return (unsigned) ((char6 & 0x3f) | ((char5 & 0x3f) << 6) | ((char4 & 0x3f) << 12) | ((char3 & 0x3f) << 18) |
                           ((char2 & 0x3f) << 24) | ((char1 & 0x1) << 30));
    }
}

#ifdef _WIN32

void String::encodeUtf16(wchar_t*& dest, unsigned unicodeChar)
{
    if (unicodeChar < 0x10000)
        *dest++ = unicodeChar;
    else
    {
        unicodeChar -= 0x10000;
        *dest++ = 0xd800 | ((unicodeChar >> 10) & 0x3ff);
        *dest++ = 0xdc00 | (unicodeChar & 0x3ff);
    }
}

unsigned String::decodeUtf16(const wchar_t*& src)
{
    if (src == 0)
        return 0;

    unsigned short word1 = *src++;

    // Check if we are at a low surrogate
    if (word1 >= 0xdc00 && word1 < 0xe000)
    {
        while (*src >= 0xdc00 && *src < 0xe000)
            ++src;
        return '?';
    }

    if (word1 < 0xd800 || word1 >= 0xe000)
        return word1;
    else
    {
        unsigned short word2 = *src++;
        if (word2 < 0xdc00 || word2 >= 0xe000)
        {
            --src;
            return '?';
        }
        else
            return (((word1 & 0x3ff) << 10) | (word2 & 0x3ff)) + 0x10000;
    }
}
#endif

String& String::appendWithFormat(const char* formatString, ...)
{
    va_list args;
    va_start(args, formatString);
    appendWithFormatArguments(formatString, args);
    va_end(args);
    return *this;
}

String& String::appendWithFormatArguments(const char* formatString, va_list args)
{
    int pos = 0, lastPos = 0;
    int length = (int) strlen(formatString);

    while (true)
    {
        // Scan the format string and find %a argument where a is one of d, f, s ...
        while (pos < length && formatString[pos] != '%') pos++;
        append(formatString + lastPos, (unsigned) (pos - lastPos));
        if (pos >= length)
            return *this;

        char format = formatString[pos + 1];
        pos += 2;
        lastPos = pos;

        switch (format)
        {
                // Integer
            case 'd':
            case 'i':
            {
                int arg = va_arg(args, int);
                append(String(arg));
                break;
            }

                // Unsigned
            case 'u':
            {
                unsigned arg = va_arg(args, unsigned);
                append(String(arg));
                break;
            }

                // Unsigned long
            case 'l':
            {
                unsigned long arg = va_arg(args, unsigned long);
                append(String(arg));
                break;
            }

                // Real
            case 'f':
            {
                double arg = va_arg(args, double);
                append(String(arg));
                break;
            }

                // Character
            case 'c':
            {
                int arg = va_arg(args, int);
                append((char) arg);
                break;
            }

                // C string
            case 's':
            {
                char* arg = va_arg(args, char*);
                append(arg);
                break;
            }

            case 'S':
            {
                String arg = va_arg(args, String);
                append(arg);
                break;
            }

                // Hex
            case 'x':
            {
                char buf[CONVERSION_BUFFER_LENGTH];
                int arg = va_arg(args, int);
                int arglen = ::sprintf(buf, "%x", arg);
                append(buf, (unsigned) arglen);
                break;
            }

                // Pointer
            case 'p':
            {
                char buf[CONVERSION_BUFFER_LENGTH];
                int arg = va_arg(args, int);
                int arglen = ::sprintf(buf, "%p", reinterpret_cast<void*> (arg));
                append(buf, (unsigned) arglen);
                break;
            }

            case '%':
            {
                append("%", 1);
                break;
            }

            default:
                break;
        }
    }
}

String& String::format(const String& fmt, ...)
{
    char *buffer = new char[0x1000]; // 4096B should be enough

    va_list va;
    va_start(va, fmt);
    ::vsnprintf(buffer, 0x1000, fmt.toCharArray(), va);
    append(buffer);
    va_end(va);

    delete[] buffer;
    return *this;
}

String& String::formatWithArguments(const String& fmt, va_list args)
{
    char* buffer = new char[0x1000];
    ::vsnprintf(buffer, 0x1000, fmt.toCharArray(), args);
    append(buffer);

    delete[] buffer;
    return *this;
}

int String::compare(const char* lhs, const char* rhs, bool caseSensitive)
{
    if (!lhs || !rhs)
        return lhs ? 1 : (rhs ? -1 : 0);

    if (caseSensitive)
        return strcmp(lhs, rhs);
    else
    {
        for (; ; )
        {
            char l = (char) tolower(*lhs);
            char r = (char) tolower(*rhs);
            if (!l || !r)
                return l ? 1 : (r ? -1 : 0);
            if (l < r)
                return -1;
            if (l > r)
                return 1;

            ++lhs;
            ++rhs;
        }
    }
}

void String::replace(unsigned pos, unsigned length, const char* srcStart, unsigned srcLength)
{
    int delta = (int) srcLength - (int) length;

    if (pos + length < bufferLength)
    {
        if (delta < 0)
        {
            moveRange(pos + srcLength, pos + length, bufferLength - pos - length);
            resize(bufferLength + delta);
        }
        if (delta > 0)
        {
            resize(bufferLength + delta);
            moveRange(pos + srcLength, pos + length, bufferLength - pos - length - delta);
        }
    }
    else
        resize(bufferLength + delta);

    copyCharacters(buffer + pos, srcStart, srcLength);
}

unsigned String::count(const String& str) const
{
    unsigned count = 0;
    if (find(str) != String::NPOS && length() >= str.length())
    {
        for (unsigned i = 0; i < length() - str.length(); ++i)
        {
            if (substring(i).startsWith(str))
            {
                count++;
            }
        }
    }
    return count;
}

std::vector<String> String::split(const String& delimiter, unsigned maxCount) const
{
    // Max-count parameter evaluation
    if (maxCount == 0)
    {
        maxCount = UINT_MAX;
    }

    // Vector initialization
    std::vector<String> result;

    // Count initialization
    unsigned        count = 0;
    unsigned        startPosition = 0;
    unsigned        endPosition = find(delimiter) != String::NPOS ? find(delimiter) : length();
    const unsigned  delimiterLength = delimiter.length();

    if (endPosition == length())
    {
        result.push_back(*this);
    }
    else
    {
        do
        {
            // Substring the token & insert
            const core::String token = substring(startPosition, endPosition);
            result.push_back(token);

            // Update the position variables
            startPosition = endPosition + delimiterLength;
            endPosition = find(delimiter, startPosition);

            // Increase the count
            ++count;
        }
        while ((count <= maxCount)
               && (endPosition != String::NPOS));

        if (endPosition == String::NPOS
            || (count > maxCount))
        {
            result.push_back(substring(startPosition, length()));
        }
    }
    return result;
}
