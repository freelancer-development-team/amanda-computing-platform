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
 * File:   Location.h
 * Author: Javier Marrero
 *
 * Created on March 23, 2022, 2:04 AM
 */

#ifndef LOCATION_H
#define LOCATION_H

#include <amanda-vm/Object.h>

namespace amanda
{
namespace il
{

/**
 * Represents a location in the source file.
 *
 * @author J. Marrero
 */
class Location : public core::Object
{
    AMANDA_OBJECT(Location, core::Object)

public:

    Location(unsigned long long il = 1, unsigned long long ic = 1, unsigned long long fl = 1, unsigned long long fc = 1);
    virtual ~Location();
    
    unsigned long long  getFinalColumn() const ;
    unsigned long long  getFinalLine() const ;
    unsigned long long  getInitialColumn() const ;
    unsigned long long  getInitialLine() const ;
    void                setFinalColumn(unsigned long long finalColumn);
    void                setFinalLine(unsigned long long finalLine);
    void                setInitialColumn(unsigned long long initialColumn);
    void                setInitialLine(unsigned long long initialLine);

private:

    unsigned long long initialLine;
    unsigned long long initialColumn;
    unsigned long long finalLine;
    unsigned long long finalColumn;
} ;

}
}

#endif /* LOCATION_H */

