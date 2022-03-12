#!env bash
#
# Count lines of code
#
# © Copyright 2022 FreeLancer Development Team
# Licensed under the GPL v3+
#
# Written by J. Marrero

# Subshell this
(
cd ..
echo -e "\nC++ Sources:"
find . -name "*.cpp" | xargs wc -l | sort -nr

echo -e "\nC++ Headers:"
find include -name "*.h" | xargs wc -l | sort -nr

)