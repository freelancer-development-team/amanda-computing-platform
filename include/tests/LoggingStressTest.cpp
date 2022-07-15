/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LoggingStressTest.cpp
 * Author: Javier Marrero
 *
 * Created on July 10, 2022, 12:40 PM
 */

#include <stdlib.h>
#include <iostream>

#include <amanda-vm/Logging/Logger.h>

using namespace amanda;
using namespace amanda::logging;

/*
 * Simple C++ Test Suite
 */

int main(int argc, char** argv)
{
    Logger& logger = Logger::getLogger("test")->getReference();

    for (int i = 0; i < 100000; ++i)
    {
        logger.info("i = %d", i);
        //printf("i-> %d\n", i);
    }

    system("pause");
    return (EXIT_SUCCESS);
}

