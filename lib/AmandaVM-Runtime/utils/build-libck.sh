#!env bash
#
# Build & install libck: lock-less data structures
#
# © Copyright 2022 FreeLancer Development Team
# Licensed under the GPL v3+
#
# Written by J. Marrero

ABSOLUTE_PATH="$(dirname $(dirname $(dirname $(dirname $(realpath $0)))))"

echo "-- building libck: lockless data structures library --"

PREFIX="$ABSOLUTE_PATH/third-party/ck/bin"
PREFIX="${PREFIX/\//}"

echo "libck will be installed at: $PREFIX"

# Only build if not built yet
if [[ ! -f "/$PREFIX/lib/libck.a" ]]
then

echo "-- need to build libck because could not find library --"

# Goto libck sources
cd "$ABSOLUTE_PATH/third-party/ck"

# Make the distribution directory
mkdir -p bin

# Clean
# make -j8 clean

# Configure
./configure --prefix="$PREFIX"

# Make, make check & make install
make -j8
make -j8 install

else
echo "-- no need to build libck --"
fi

echo "-- done, success --"
