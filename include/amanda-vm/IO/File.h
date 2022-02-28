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
 * File:   File.h
 * Author: Javier Marrero
 *
 * Created on February 13, 2022, 6:12 PM
 */

#ifndef FILE_H
#define FILE_H

#include <amanda-vm/Object.h>
#include <amanda-vm/String.h>
#include <amanda-vm/io/Path.h>

#include <stdio.h>

namespace amanda
{
namespace io
{

class File : public amanda::core::Object
{
    AMANDA_OBJECT(File, amanda::core::Object)

public:

    static const File STDIN;
    static const File STDOUT;
    static const File STDERR;

    enum
    {
        READ = 0x1,
        WRITE = 0x2,
        APPEND = 0x4,
        CREATE = 0x8,
        BINARY = 0x10
    };
    typedef unsigned FileAccessMode;

    File(int descriptor, FileAccessMode accessMode);
    File(const core::String& name, FileAccessMode accessMode, bool inmediate = false);
    File(const Path& path, FileAccessMode accessMode, bool inmediate = false);

    bool                canExecute() const;
    bool                canRead() const;
    bool                canWrite() const;
    void                close();
    bool                exists() const;
    void                flush() const;
    FileAccessMode      getAccessMode() const;
    const char*         getAccessModeString(FileAccessMode accessMode) const;
    int                 getCharacter() const;
    FILE*               getHandle() const;
    const core::String& getPath() const;
    bool                isDirectory() const;
    bool                isEndOfFile() const;
    bool                isError() const;
    bool                isFile() const;
    bool                modifyAccessMode(FileAccessMode newAccessMode);
    bool                open();
    bool                read(char* buffer, size_t size) const;
    bool                readline(char* buffer, size_t limit) const;
    void                rename(const core::String& str);
    bool                reset() const;
    bool                write(const char* str) const;
    bool                write(const void* bytes, size_t size) const;

private:

    core::String    name;
    FileAccessMode  accessMode;
    FILE*           handle;

    struct
    {
        bool        attr_dir;
        bool        attr_file;
    } attributes;
    
} ;

}
}

#endif /* FILE_H */

