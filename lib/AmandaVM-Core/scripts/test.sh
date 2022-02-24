#!/bin/sh
# 
# File:   test.sh
# Author: Javier Marrero
#
# Created on Feb 15, 2022, 12:58:47 AM
#

scriptpath="$(dirname $(realpath $0))"
. "$scriptpath/common.sh"

echo "-- building tests --"

# Make build tests
cd ..
make -j8 build-tests
onerror

# Function to execute and print the test file being run.
rtest()
{
    clear
    printf "\n\t--------\n\t\e[0;37minfo\e[0m: running test $1\n\t--------\n\n"
    "$1"
}

# Traverse the build directory
# if there's an executable file, run it.
echo "-- running tests --"
cd build
FILES="$(find -type f -name '*.exe')"
echo $FILES

for file in $FILES
do
    rtest $file
done
cd ..
