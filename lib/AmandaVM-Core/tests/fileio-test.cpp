/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fileio-test.cpp
 * Author: Javier Marrero
 *
 * Created on February 15, 2022, 4:55 PM
 */

#include <stdlib.h>
#include <iostream>

#include <AmandaSDK.h>

using namespace amanda::core;
using namespace amanda::io;

/*
 * Simple C++ Test Suite
 */

int main(int argc, char** argv)
{
    Path path("example.txt");
    File* wfile = new File(path.toString().toCharArray(), File::WRITE | File::CREATE);
    if (wfile->open())
    {
        console().out.println("Opened file %s with mode %s for write-test.",
                              wfile->getPath().toCharArray(),
                              wfile->getAccessModeString(wfile->getAccessMode()));

        // Stream & write test
        PrintStream* writer = new PrintStream(wfile);
        bool wt = writer->println("This is an example file. We're writing this string\n"
                                  "to it. This file has several lines, in example:\n\n"
                                  "this is a line.\n"
                                  "this is another line.\n"
                                  "We will be notified if the write operation fails.\n"
                                  "The name of this file is: %s\n"
                                  "This file is a regular file? %d\n"
                                  "Is writable? %d\n"
                                  "Is readable? %d\n"
                                  "Has execute permissions? %d\n"
                                  "Open mode: %s",
                                  wfile->getPath().toCharArray(),
                                  wfile->isFile(),
                                  wfile->canWrite(),
                                  wfile->canRead(),
                                  wfile->canExecute(),
                                  wfile->getAccessModeString(wfile->getAccessMode()));

        if (!wt)
        {
            console().err.println("Unable to write to file!");
        }
    }
    else
    {
        console().err.println("Unable to open file '%s' for write test.", wfile->getPath().toCharArray());
    }
    delete wfile;

    File* rfile = new File(path, File::READ);
    if (rfile->open())
    {
        console().out.println("Opened file %s with mode %s for read-test.",
                              rfile->getPath().toCharArray(),
                              rfile->getAccessModeString(rfile->getAccessMode()));

        // Read test.
        char* buffer = (char*) calloc(0x1000, sizeof (char));
        bool rt = rfile->readline(buffer, 1000);
        if (!rt)
        {
            console().err.println("Unable to read to buffer.");
        }
        else
        {
            console().out.println("buffer: '%s'", buffer);
        }

        // Free the read-buffer.
        free(buffer);

        /* Print the file! */
        rfile->reset();
        bool eof = false;
        do
        {
            eof = rfile->isEndOfFile();
            char tmp[512];
            rfile->read(tmp, 512);

            if (!eof)
            {
                console().out.println(tmp);
            }
        }
        while (!eof);
    }
    else
    {
        console().err.println("Unable to open file '%s' for read test.",
                              rfile->getPath().toCharArray());
    }
    delete rfile;
    return (EXIT_SUCCESS);
}

