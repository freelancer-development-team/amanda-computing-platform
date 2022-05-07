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
 * File:   EndiannessConsistentStream.h
 * Author: Javier Marrero
 *
 * Created on March 26, 2022, 11:25 PM
 */

#ifndef ENDIANNESSCONSISTENTSTREAM_H
#define ENDIANNESSCONSISTENTSTREAM_H

#include <amanda-vm/IO/InputStream.h>

namespace amanda
{
namespace io
{

/**
 * The consistent input stream is a class that consistently treats input as a
 * stream of big endian data independently of the machine endianness. At the
 * time of the class instantiation, endianness of the input data must be
 * specified. If not specified, the class assumes the machine endianness.
 * <p>
 * If an incorrect endianness is specified, data byte order inversion may be
 * carried out, and it will give inconsistent reads. The class has no means to
 * compute the endianness of a chunk of data (since endianness is just a
 * convention).
 *
 * @author J. Marrero
 */
class ConsistentInputStream : public InputStream
{

    AMANDA_OBJECT(ConsistentInputStream, InputStream)
public:

    typedef enum Endianness
    {
        BIG_ENDIAN = 1,
        LITTLE_ENDIAN = 2,
        BOTH_ENDIAN = 4,
        UNKNOWN_ENDIAN = -1
    } Endianness;

    static Endianness   getMachineEndianness();
    static bool         isLittleEndian();
    static bool         isBigEndian();

    ConsistentInputStream(InputStream& stream, Endianness endianness);
    virtual ~ConsistentInputStream();

    virtual void        close() const;
    virtual Endianness  getEndianness() const;
    virtual void        read(void* buffer, size_t size) const;
    virtual void        read(void* buffer, size_t size, size_t count) const;
    virtual void        reset() const;
    virtual void        seek(uint64_t offset) const;
    virtual uint64_t    tell() const;

protected:

    InputStream& getWrappedStream() const;

private:

    Endianness      endianness;
    InputStream&    stream;

} ;

}
}

#endif /* ENDIANNESSCONSISTENTSTREAM_H */

