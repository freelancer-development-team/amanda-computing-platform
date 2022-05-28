#!env bash
#
# Count gow many times the word Amanda is written
#
# © Copyright 2022 FreeLancer Development Team
# Licensed under the GPL v3+
#
# Written by J. Marrero

# Subshell this
(
cd ..

FILES="$(find ! -path "./.git/*" ! -path "./.github/*" ! -path "./third-party/*" ! -path "*/build/*" -type f)"
TOTAL=0

for file in $FILES;
do
	PARTIAL="$(grep -o -i amanda "${file}" | wc -l)"
	if [ "$PARTIAL" -ne "0" ]
	then
		printf "%4d times in \"$file.\"\n" $PARTIAL	
	fi
	
	TOTAL="$(($PARTIAL + $TOTAL))"
done

echo "The word amanda is counted " $TOTAL " times."

)
