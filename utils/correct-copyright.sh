#!env bash
#
# Correct the copyright declarations
#
# © Copyright 2022 FreeLancer Development Team
# Licensed under the GPL v3+
#
# Written by J. Marrero

echo "-- correcting copyright notice on .h, .c & .cpp files"

# Do all of this in a subshell
(
cd ..

HEADER_FILES="$(find -type f -name '*.h')"
C_FILES="$(find -type f -name '*.c')"
CPP_FILES="$(find -type f -name '*.cpp')"

for file in $HEADER_FILES $C_FILES $CPP_FILES;
do
	sed -i 's/Copyright (C) 2022 Javier Marrero/Copyright (C) 2022 FreeLancer Development Team/' $file
done

)