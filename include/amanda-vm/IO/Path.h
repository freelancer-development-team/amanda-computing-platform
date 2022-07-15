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
 * File:   Path.h
 * Author: Javier Marrero
 *
 * Created on February 15, 2022, 12:24 AM
 */

#ifndef PATH_H
#define PATH_H

#include <amanda-vm/Object.h>
#include <amanda-vm/String.h>

// C API
#include <amanda-vm-c/sdk-configuration.h>

// C++
#include <vector>

namespace amanda
{
namespace io
{

/**
 * The <code>Path</code> class abstract all native path operations, such as
 * normalization, relative paths, absolute paths.
 *
 * @author J. Marrero
 */
class Path : public amanda::core::Object
{
    AMANDA_OBJECT(Path, amanda::core::Object)

public:

    typedef std::vector<Path>   DirectoryList;

    static const core::String&  END_OF_PATH;
    static const char           PATH_SEPARATOR = '/';

    static Path get(const core::String& first, ...);

    Path(const core::String& pathName = core::String::EMPTY);
    Path(const Path& first, const Path& second);
    Path(const Path& rhs);
    virtual ~Path();

    virtual short               compareTo(const Path& other) const;
    virtual bool                endsWith(const core::String& str) const;
    virtual bool                exists() const;
    virtual const DirectoryList getAllFilesInDirectory() const;
    virtual core::String        getLastPathComponent() const;
    virtual unsigned            getNameCount() const;
    virtual Path                getParent() const;
    virtual bool                hasExtension(const core::String& str) const;
    virtual bool                isAbsolutePath() const;
    virtual bool                isDirectory() const;
    virtual bool                isRelativePath() const;
    virtual Path&               join(const core::String& second);
    virtual Path&               join(const Path& second);
    virtual Path&               makeAbsolute();
    virtual Path&               normalize();
    virtual Path                toAbsolutePath() const;
    virtual core::String        toString() const;

#ifdef _W32
    Path&                       makeWindowsPath();
#endif

private:

    core::String pathName;

    void                        checkNotEmpty() const;
} ;

}
}

#endif /* PATH_H */

