/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PathTest.cpp
 * Author: Javier Marrero
 *
 * Created on July 12, 2022, 2:18 PM
 */

#include <stdlib.h>
#include <iostream>

#include <amanda-vm/IO/Path.h>

using namespace amanda;
using namespace amanda::io;

/*
 * Simple C++ Test Suite
 */

int main(int argc, char** argv)
{
    Path path(".");
    std::cout << "Absolute path: " << path.toAbsolutePath().toString().toCharArray() << std::endl;
    std::cout << "Entries in this directory: " << std::endl;

    const Path::DirectoryList entries = path.getAllFilesInDirectory();
    for (Path::DirectoryList::const_iterator it = entries.begin();
         it != entries.end(); ++it)
    {
        std::cout << "entry: " << (*it).toString().toCharArray() << " | abs: " << (*it).toAbsolutePath().toString().toCharArray() << std::endl;
    }

    return (EXIT_SUCCESS);
}

