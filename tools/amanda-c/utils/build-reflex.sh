#!/bin/sh
# 
# File:   build-reflex.sh
# Author: Javier Marrero
#
# Created on Mar 13, 2022, 10:43:31 AM
#

echo "Building RE-Flex"
printf "GCC version: "
gcc -dumpversion

scriptpath="$(dirname $(realpath $0))"
. "$scriptpath/reflex-commons.sh"

# Sub-shell this
(
cd $REFLEX_SOURCES_DIR
./build.sh

)
