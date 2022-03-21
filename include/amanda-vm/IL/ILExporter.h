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
 * File:   ILExporter.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 5:11 PM
 */

#ifndef ILEXPORTER_H
#define ILEXPORTER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IL/Module.h>

#include <stdint.h>

namespace amanda
{
namespace il
{

/**
 * The <code>ILExporter</code> class represents an abstract data type that grabs
 * a IL Module and exports all its code and data to a custom format, may it be
 * some binary format suitable for serialization and transmission through a
 * network, or simple plain text suitable as entry for an assembler.
 *
 * @author J. Marrero
 */
class ILExporter : public core::Object
{
    AMANDA_OBJECT(ILExporter, core::Object)

public:
    
    ILExporter(Module* module);
    virtual ~ILExporter();

    virtual void exportData(char buffer[], size_t size) = 0;

private:

    core::StrongReference<Module> module;
} ;

}
}

#endif /* ILEXPORTER_H */

