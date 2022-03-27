#!/bin/sh
# 
# File:   build-libjit.sh
# Author: Javier Marrero
#
# Created on Mar 25, 2022, 12:01:01 PM
#

#
# Fails if the previous command was erroneous
#
#   $CC -c ...
#   failOnError
#
onerror() {
	if [[ $? != 0 ]]; then
		printf "\e[31;3mtarget failed\e[0m $1\n\n"
		exit 1
	fi
}

target_successful() {
	printf "\e[32;3mBUILD SUCCESSFUL\e[0m\n\n"
}

# Absolute path (for prefix)
export ABSOLUTE_PATH="$(realpath .)"

LIBJIT_SOURCES="../../third-party/libjit-0.1.4"
INSTALL_DIR="$ABSOLUTE_PATH/libjit-0.1.4-binaries"
BUILD_DIR="$INSTALL_DIR/build"

LIBJIT_CONFIGURE="$(realpath $LIBJIT_SOURCES/configure)"

# Subshell this
(
if [ -e "$INSTALL_DIR/lib/libjitplus.a" ]
then
    echo "No need to build GNU LibJIT"
    target_successful
    exit 0
fi

    echo "Building GNU Libjit version 0.1.4"
    echo "LibJIT will be installed on $INSTALL_DIR"

    # Create the installation directory and switch to the source directory
    mkdir -p "$INSTALL_DIR"
    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"
    onerror "directory switch"

    echo " -- Cleaning GNU Libjit previous builds"
    make clean

    echo " -- Configuring GNU Libjit"
    $LIBJIT_CONFIGURE --prefix=$INSTALL_DIR
    onerror "configure"

    echo " -- Building & testing GNU Libjit"
    make -j8 all
    onerror "make"
    make -j8 install
    onerror "make install"

    echo " -- Cleaning up"
    rm -rf "$BUILD_DIR"

    target_successful


)
