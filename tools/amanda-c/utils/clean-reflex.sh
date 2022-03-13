#!/bin/sh
# 
# File:   clean-reflex.sh
# Author: Javier Marrero
#
# Created on Mar 13, 2022, 10:44:22 AM
#

scriptpath="$(dirname $(realpath $0))"
. "$scriptpath/reflex-commons.sh"

(
cd $REFLEX_SOURCES_DIR
./clean.sh

)
