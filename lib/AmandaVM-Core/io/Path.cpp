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
 * File:   Path.cpp
 * Author: Javier Marrero
 * 
 * Created on February 15, 2022, 12:24 AM
 */

#include <amanda-vm/io/Path.h>
#include <amanda-vm/NIO/IOException.h>
#include <amanda-vm/NIO/NoSuchFileException.h>
#include <amanda-vm-c/sdk-configuration.h>

// C++
#include <cctype>
#include <cwchar>
#include <cwctype>
#include <cstdarg>
#include <cerrno>

#ifdef _W32
#    include <windows.h>
#endif

#ifdef __GNUC__
#    include <unistd.h>
#    include <dirent.h>
#    include <sys/stat.h>
#endif

using namespace amanda;
using namespace amanda::io;

using amanda::io::Path;
using amanda::core::String;

const core::String& Path::END_OF_PATH = core::String::EMPTY;

Path Path::get(const core::String& first, ...)
{
    Path result(first);
    va_list va;
    va_start(va, first);

    for (core::String arg = va_arg(va, core::String); arg != END_OF_PATH;
         arg = va_arg(va, core::String))
    {
        result.join(arg);
    }

    va_end(va);
    return result;
}

Path::Path(const core::String& pathName)
:
pathName(pathName)
{
    checkNotEmpty();
    normalize();
}

Path::Path(const Path& first, const Path& second)
:
pathName(first.toString())
{
    checkNotEmpty();
    join(second);
}

Path::Path(const Path& rhs)
:
pathName(rhs.pathName)
{
}

Path::~Path()
{
}

void Path::checkNotEmpty() const
{
    if (pathName.isEmpty())
    {
        throw nio::IOException("empty pathname.");
    }
}

short Path::compareTo(const Path& other) const
{
    return std::wcscoll(pathName.toWideCharArray(), other.pathName.toWideCharArray());
}

bool Path::endsWith(const core::String& str) const
{
    return pathName.endsWith(str, true);
}

const Path::DirectoryList Path::getAllFilesInDirectory() const
{
    DirectoryList list;
#ifdef __GNUC__
    DIR* dirp;
    struct dirent *dp;

    if ((dirp = opendir(pathName.toCharArray())) == NULL)
    {
        throw nio::NoSuchFileException(pathName);
    }
    else
    {
        errno = 0;
        AMANDA_SYNCHRONIZED(lock);
        {
            do
            {
                if ((dp = readdir(dirp)) != NULL)
                {
                    if (strcmp(dp->d_name, ".") != 0 &&
                        strcmp(dp->d_name, "..") != 0)
                    {
                        Path entry(*this, Path(dp->d_name));
                        list.push_back(entry);
                    }
                }
            }
            while (dp != NULL);
        }
        AMANDA_DESYNCHRONIZED(lock);
    }

    closedir(dirp);
    if (errno != 0)
    {
        throw nio::IOException(core::String::makeFormattedString("error reading directory: %s", getLastPathComponent().toCharArray()));
    }
#endif
    return list;
}

String Path::getLastPathComponent() const
{
    String lastComponent(pathName);
    unsigned lastSeparator = lastComponent.findLast(PATH_SEPARATOR);
    if (lastSeparator != String::NPOS)
    {
        lastComponent = lastComponent.substring(lastSeparator + 1);
    }
    return lastComponent;
}

unsigned Path::getNameCount() const
{
    return pathName.count(PATH_SEPARATOR) + 1;
}

Path Path::getParent() const
{
    Path path(pathName);
    unsigned index = pathName.findLast(PATH_SEPARATOR);
    if (index != String::NPOS)
    {
        path = Path(pathName.substring(0, index));
    }
    return path;
}

bool Path::hasExtension(const core::String& str) const
{
    return pathName.endsWith(str, false);
}

bool Path::exists() const
{
    core::String path(pathName);
#ifdef _W32
    path.replace(PATH_SEPARATOR, '\\');
#endif
    return (_access(path.toCharArray(), F_OK) == 0);
}

bool Path::isAbsolutePath() const
{
    bool result = false;
#if _W32
    if (pathName.find(":/") != core::String::NPOS || pathName.startsWith("/"))
    {
        result = true;
    }
#else
    if (pathName.startsWith("/"))
    {
        result = true;
    }
#endif
    return result;
}

bool Path::isDirectory() const
{
    // Fail fast behavior
    bool result = false;
    if (exists())
    {
        struct stat info;

        core::String path(pathName);
#ifdef _W32
        path.replace(PATH_SEPARATOR, '\\');
#endif

        int statResult = stat(path.toCharArray(), &info);
        if (statResult != 0)
        {
            core::String cause("'stat' function failed");
            switch (statResult)
            {
                case EACCES:
                    cause = "search permission is denied for one of the directories in the path.";
                    break;
                case EFAULT:
                    cause = "bad address";
                    break;
                case ELOOP:
                    cause = "too many symbolic links.";
                    break;
                case ENAMETOOLONG:
                    cause = "path name exceeds the maximum size.";
                    break;
                case ENOENT:
                    cause = "path does not exists.";
                    break;
                case ENOMEM:
                    cause = "out of memory (kernel memory)";
                    break;
                case EOVERFLOW:
                    cause = "unable to retrieve 'stat' info";
                    break;
            }

            throw nio::IOException(cause);
        }
        else
        {
            result = S_ISDIR(info.st_mode);
        }
    }
    return result;
}

bool Path::isRelativePath() const
{
    return !isAbsolutePath();
}

Path& Path::join(const core::String& second)
{
    join(second);
    return *this;
}

Path& Path::join(const Path& second)
{
    pathName.append(PATH_SEPARATOR).append(second.pathName);
    return *this;
}

Path& Path::makeAbsolute()
{
    *this = toAbsolutePath();
    return *this;
}

Path& Path::makeWindowsPath()
{
    pathName.replace(PATH_SEPARATOR, '\\');
    return *this;
}

Path& Path::normalize()
{
    pathName.replace('\\', PATH_SEPARATOR);
    return *this;
}

Path Path::toAbsolutePath() const
{
    if (isAbsolutePath())
    {
        return *this;
    }
    else
    {
        wchar_t resolvedPath[512] = {0};
#ifdef _W32
        if (_wfullpath(resolvedPath, pathName.toWideCharArray(), 512) == NULL)
        {
            throw nio::IOException("invalid pathname.");
        }
#else
        //TODO: Port this code to Linux
#endif

        return io::Path(resolvedPath);
    }
}

String Path::toString() const
{
    return pathName;
}
