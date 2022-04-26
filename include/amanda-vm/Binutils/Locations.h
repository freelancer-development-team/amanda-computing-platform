/*
 * Copyright (C) 2022 Javier Marrero
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
 * File:   Locations.h
 * Author: Javier Marrero
 *
 * Created on April 12, 2022, 2:01 AM
 */

#ifndef LOCATIONS_H
#define LOCATIONS_H

namespace amanda
{
namespace binutils
{

/**
 * Represents a position pair (line/column). If a position contains negative
 * numbers it is an invalid position.
 */
typedef struct position
{
    signed long long column;
    signed long long row;
} position_t;

/**
 * A location defining a range or interval of positions.
 */
typedef struct location
{
    position_t first;
    position_t last;
} location_t;

}
}

#endif /* LOCATIONS_H */

