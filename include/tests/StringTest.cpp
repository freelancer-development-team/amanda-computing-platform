/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringTest.cpp
 * Author: Javier Marrero
 *
 * Created on July 12, 2022, 11:38 AM
 */

#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cwchar>
#include <cwctype>

#include <amanda-vm/String.h>

using namespace amanda;

using amanda::core::String;

/*
 * Simple C++ Test Suite
 */

int main(int argc, char** argv)
{
    // Test 1
    {
        core::String str("this is a string :D");
        std::printf("str: %s\n", str.toCharArray());
        std::wprintf(L"the wide char string format specifier is: %S\n", L"%S");
        std::wprintf(L"str: %S\n", str.toWideCharArray());
    }
    return (EXIT_SUCCESS);
}

