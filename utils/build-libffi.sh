#!env bash
#
# Build & install libffi
#
# © Copyright 2022 FreeLancer Development Team
# Licensed under the GPL v3+
#
# Written by J. Marrero

ABSOLUTE_PATH="$(dirname $(dirname $(realpath $0)))"

echo "-- building libffi: foreign function interface library --"

PREFIX="$ABSOLUTE_PATH/third-party/libffi/bin"
echo "libffi be installed at: $PREFIX"

# Goto main directory
cd ..

# Goto libffi sources
cd third-party/libffi

# Make the distribution directory
mkdir -p bin

# Clean
make -j8 clean
make -j8 distclean

# Configure
./configure --prefix="$PREFIX"

# Make, make check & make install
make -j8
make -j8 check
make -j8 install

echo "-- done, success --"