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
 * File:   conio-tests.cpp
 * Author: Javier Marrero
 *
 * Created on February 15, 2022, 1:15 AM
 */

#include <stdlib.h>
#include <iostream>

#include <AmandaSDK.h>

using namespace amanda::io;

int main(int argc, char** argv)
{
    console().out.println("Hello, world!");
    console().err.println("This is a standard error message!");
    console().out.println("This line should be printed after cleanup.");
    console().err.println("Standard output lines doesn't show for an unknown reason.");

    return (EXIT_SUCCESS);
}

