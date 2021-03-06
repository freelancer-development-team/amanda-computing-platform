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
 * File:   AmandaSDK.h
 * Author: Javier Marrero
 *
 * Created on February 13, 2022, 2:14 PM
 */

#ifndef AMANDASDK_H
#define AMANDASDK_H

/* AmandaSDK C interface (code library only) */
#include <amanda-vm-c/sdk-assert-helper.h>
#include <amanda-vm-c/sdk-definitions.h>
#include <amanda-vm-c/sdk-toolchains.h>
#include <amanda-vm-c/sdk-types.h>
#include <amanda-vm-c/sdk-version.h>

/* AmandaSDK C++ interface (core library only) */
#include <amanda-vm/Callable.h>
#include <amanda-vm/Class.h>
#include <amanda-vm/Exception.h>
#include <amanda-vm/IllegalArgumentException.h>
#include <amanda-vm/Integer.h>
#include <amanda-vm/Interface.h>
#include <amanda-vm/Object.h>
#include <amanda-vm/Pointer.h>
#include <amanda-vm/ReferenceCounted.h>
#include <amanda-vm/String.h>
#include <amanda-vm/System.h>
#include <amanda-vm/Types.h>

#include <amanda-vm/ADT/Array.h>
#include <amanda-vm/ADT/BinaryBuffer.h>
#include <amanda-vm/ADT/Collections.h>
#include <amanda-vm/ADT/Iterators.h>

#include <amanda-vm/IO/Closeable.h>
#include <amanda-vm/IO/ConsistentInputStream.h>
#include <amanda-vm/IO/ConsistentOutputStream.h>
#include <amanda-vm/IO/Console.h>
#include <amanda-vm/IO/File.h>
#include <amanda-vm/IO/FileInputStream.h>
#include <amanda-vm/IO/FileOutputStream.h>
#include <amanda-vm/IO/Flushable.h>
#include <amanda-vm/IO/InputStream.h>
#include <amanda-vm/IO/MemoryOutputStream.h>
#include <amanda-vm/IO/OutputStream.h>
#include <amanda-vm/IO/Path.h>
#include <amanda-vm/IO/PrintStream.h>

#include <amanda-vm/Logging/ConsoleHandler.h>
#include <amanda-vm/Logging/ErrorManager.h>
#include <amanda-vm/Logging/Filter.h>
#include <amanda-vm/Logging/Formatter.h>
#include <amanda-vm/Logging/GNUFormatter.h>
#include <amanda-vm/Logging/Handler.h>
#include <amanda-vm/Logging/LogManager.h>
#include <amanda-vm/Logging/LogRecord.h>
#include <amanda-vm/Logging/Logger.h>
#include <amanda-vm/Logging/SimpleFormatter.h>
#include <amanda-vm/Logging/StreamHandler.h>

#include <amanda-vm/NIO/IOException.h>

#include <amanda-vm/Threading/Runnable.h>
#include <amanda-vm/Threading/Synchronization.h>
#include <amanda-vm/Threading/SynchronizationError.h>
#include <amanda-vm/Threading/Thread.h>
#include <amanda-vm/Threading/ThreadingException.h>

#endif /* AMANDASDK_H */

