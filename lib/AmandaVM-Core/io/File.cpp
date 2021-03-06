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
 * File:   File.cpp
 * Author: Javier Marrero
 * 
 * Created on February 13, 2022, 6:12 PM
 */

#include <amanda-vm/io/File.h>
#include <amanda-vm/Threading/Synchronization.h>

/* C interface */
#include <amanda-vm-c/sdk-definitions.h>

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/*
 * Check this and replace for portability. While we're supporting GCC this
 * seems not to be a real issue.
 */
#ifdef __GNUC__
#    include <unistd.h>
#    include <sys/stat.h>
#endif

using amanda::io::File;

using amanda::core::String;

const File File::STDIN(STDIN_FILENO, READ);
const File File::STDERR(STDERR_FILENO, WRITE);
const File File::STDOUT(STDOUT_FILENO, WRITE);

bool File::isTerminalStream(const File* file)
{
    return (file == &STDERR) || (file == &STDOUT) || (file == &STDIN);
}

File::File(int descriptor, FileAccessMode accessMode)
:
accessMode(accessMode),
handle(NULL)
{
    attributes.attr_file = true;
    switch (descriptor)
    {
        case STDIN_FILENO:
            name = "Standard Input";
            handle = stdin;
            break;
        case STDOUT_FILENO:
            name = "Standard Output";
            handle = stdout;
            break;
        case STDERR_FILENO:
            name = "Standard Error Output";
            handle = stderr;
            break;
        default:
            handle = fdopen(descriptor, getAccessModeString(accessMode));
            break;
    }
}

File::File(const core::String& name, FileAccessMode accessMode, bool inmediate)
:
name(name),
accessMode(accessMode),
handle(NULL)
{
    /* Normalize the path if on Windows. */
#ifdef _W32
    this->name.replace('\\', '/');
#endif

    if (inmediate)
    {
        open();
    }
}

File::File(const Path& path, FileAccessMode accessMode, bool inmediate)
:
name(path.toString()),
accessMode(accessMode),
handle(NULL)
{
    if (inmediate)
    {
        open();
    }
}

File::File(const File& file)
:
name(file.name),
accessMode(file.accessMode),
handle(file.handle)
{
    std::memcpy(&attributes, &file.attributes, sizeof (file.attributes));
}

File::~File()
{
    close();
}

bool File::canExecute() const
{
    return (_access(name.toCharArray(), X_OK) == 0);
}

bool File::canRead() const
{
    return (_access(name.toCharArray(), R_OK) == 0);
}

bool File::canWrite() const
{
    return (_access(name.toCharArray(), W_OK) == 0);
}

void File::close()
{
    //AMANDA_SYNCHRONIZED(lock);
    //{
    if (handle)
    {
        if (handle != stdout
            && handle != stdin
            && handle != stderr)
        {
            fflush(handle);
            rewind(handle);
            clearerr(handle);

            fclose(handle);

            attributes.attr_open = false;
        }
    }
    //}
    //AMANDA_DESYNCHRONIZED(lock);
}

bool File::exists() const
{
    return (_access(name.toCharArray(), F_OK) == 0);
}

void File::flush() const
{
    if (handle && isFile())
    {
        fflush(handle);
    }
}

File::FileAccessMode File::getAccessMode() const
{
    return accessMode;
}

int File::getCharacter() const
{
    int result = -1;
    if (handle && isFile() && (accessMode & READ))
    {
        result = fgetc(handle);
    }
    return result;
}

FILE* File::getHandle() const
{
    return handle;
}

const char* File::getAccessModeString(FileAccessMode accessMode) const
{
    static char tmp[10] = {0};
    memset(tmp, '\0', 10);

    if (accessMode & APPEND)
    {
        strcpy(tmp, "a");
    }
    else if (accessMode & CREATE)
    {
        if (accessMode & READ)
        {
            strcpy(tmp, "w+");
        }
        else if (accessMode & WRITE)
        {
            strcpy(tmp, "w");
        }
    }
    else
    {
        if (accessMode & WRITE)
        {
            strcpy(tmp, "r+");
        }
        else if (accessMode & READ)
        {
            strcpy(tmp, "r");
        }
    }

    /* Open the file in binary mode? (Non important on most systems) */
    if (accessMode & BINARY)
    {
        strcat(tmp, "b");
    }

    return (const char*) tmp;
}

String File::getLastErrorString() const
{
    return String(strerror(errno));
}

const String& File::getPath() const
{
    return name;
}

uint64_t File::getSize() const
{
    uint64_t result = 0;
#ifdef __GNUC__
    struct _stat64 buf;
    stat64(name.toCharArray(), &buf);

    result = buf.st_size;
#endif
    return result;
}

bool File::isDirectory() const
{
    return (attributes.attr_dir);
}

bool File::isEndOfFile() const
{
    bool result = false;
    if (handle)
    {
        result = feof(handle);
    }
    return result;
}

bool File::isError() const
{
    bool result = false;
    if (handle)
    {
        //AMANDA_SYNCHRONIZED(lock);
        //{
        result = ferror(handle);
        //}
        //AMANDA_DESYNCHRONIZED(lock);
    }
    return result;
}

bool File::isFile() const
{
    return (attributes.attr_file);
}

bool File::isOpen() const
{
    return (attributes.attr_open);
}

bool File::modifyAccessMode(FileAccessMode newAccessMode)
{
    bool result = false;
    AMANDA_SYNCHRONIZED(lock);
    {
        if (handle && isFile())
        {
            handle = freopen(getPath().toCharArray(), getAccessModeString(newAccessMode), handle);
            this->accessMode = newAccessMode;

            result = (handle == NULL);
        }
    }
    AMANDA_DESYNCHRONIZED(lock);
    return result;
}

bool File::open()
{
    bool result = false;

    AMANDA_SYNCHRONIZED(lock);
    {
        handle = fopen(name.toCharArray(), getAccessModeString(accessMode));

        /*
         * Stat system call. May replace if something more portable appears.
         */
        struct stat stat_info;
        if (stat(name.toCharArray(), &stat_info) == 0)
        {
            unsigned short fmode = (stat_info.st_mode & S_IFMT);
            switch (fmode)
            {
                case S_IFDIR:
                    attributes.attr_dir = true;
                    break;
                case S_IFREG:
                    attributes.attr_file = true;
                    break;
                default:
                    attributes.attr_file = true;
                    break;
            }

            /* Return the opening status of the file. */
            result = (handle == NULL) ? false : true;
        }

        if (result)
        {
            attributes.attr_open = true;
        }
    }
    AMANDA_DESYNCHRONIZED(lock);
    return result;
}

bool File::read(char* buffer, size_t size) const
{
    return read(buffer, 1, size);
}

bool File::read(char* buffer, size_t size, size_t count) const
{
    bool result = false;
    //AMANDA_SYNCHRONIZED(lock);
    //{
    if ((size > 0) && (buffer != NULL)
        && handle != NULL
        && (accessMode & READ)
        && isFile())
    {
        clearerr(handle);
        size_t read = fread(buffer, size, count, handle);

        result = !ferror(handle) && (read > 0);
    }
    //}
    //AMANDA_DESYNCHRONIZED(lock);
    return result;
}

bool File::readline(char* buffer, size_t limit) const
{
    bool result = false;
    //AMANDA_SYNCHRONIZED(lock);
    //{
    if ((handle != NULL) && canRead() && !isEndOfFile())
    {
        clearerr(handle);
        fgets(buffer, limit, handle);
        buffer[strlen(buffer) - 1] = '\0';

        result = ferror(handle) == false;
    }
    //}
    //AMANDA_DESYNCHRONIZED(lock);
    return result;
}

void File::rename(const core::String& str)
{
    AMANDA_SYNCHRONIZED(lock);
    {
        ::rename(name.toCharArray(), str.toCharArray());
        name = str;
    }
    AMANDA_DESYNCHRONIZED(lock);
}

bool File::reset() const
{
    bool result = false;
    if (handle && isFile())
    {
        //AMANDA_SYNCHRONIZED(lock);
        //{
        rewind(handle);
        //}
        //AMANDA_DESYNCHRONIZED(lock);
        result = true;
    }
    return result;
}

void File::setPosition(uint64_t offset) const
{
    //AMANDA_SYNCHRONIZED(lock);
    //{
    if (isOpen() && isFile())
    {
        // Reset the file indicator
        rewind(handle);

        // Get how many iterations and the final addendum
        fseeko64(handle, (off64_t) offset, SEEK_SET);
    }
    //}
    //AMANDA_DESYNCHRONIZED(lock);
}

uint64_t File::tell() const
{
    off64_t position = 0;
    //    AMANDA_SYNCHRONIZED(lock);
    //    {
    if (isOpen() && isFile())
    {
        position = ftello64(handle);
    }
    //    }
    //    AMANDA_DESYNCHRONIZED(lock);
    return (uint64_t) position;
}

bool File::write(const char* str) const
{
    bool result = false;
    //    AMANDA_SYNCHRONIZED(lock);
    //    {
    if (handle && (accessMode & WRITE) && isFile())
    {
        size_t written = fwrite(str, sizeof (char), strlen(str), handle);
        fflush(handle);

        result = (written == strlen(str));
    }
    //    }
    //    AMANDA_DESYNCHRONIZED(lock);
    return result;
}

bool File::write(const void* bytes, size_t size) const
{
    bool result = false;
    //    AMANDA_SYNCHRONIZED(lock);
    //    {
    if (handle && (accessMode & WRITE) && isFile())
    {
        size_t written = fwrite(bytes, sizeof (char), size, handle);
        fflush(handle);

        result = (written == size);
    }
    //    }
    //    AMANDA_DESYNCHRONIZED(lock);
    return result;
}
