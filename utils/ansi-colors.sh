#!env bash
#
# Table of ANSI colors
#
# © Copyright 2022 FreeLancer Development Team
# Licensed under the GPL v3+
#
# Written by J. Marrero

echo -e "\n\t\t\tA table of ANSI color codes."
echo -e "\t\t© Copyright 2022 FreeLancer Development Team"
echo -e "\t\t\tLicensed under the GPL v3+"
printf "\n"

echo "-- 8bit colors --"
printf "Standard: \033[38;5;237m"
for code in {0..15}
do
	printf "\033[48;5;${code}m %.2d " $code
	if [ $code -eq 7 ] 
	then
		printf "\033[0m\n\033[38;5;235m          "
	fi
done
printf "\033[0m\n"

printf "\n\033[0mGroupings:\n\n"
for i in 16 22 28;
do
	for j in $i $((i+36)) $((i+72)) $((i+108)) $((i+144)) $((i+180));
	do
		printf "    \033[38;5;255m"
		
		for code in $j $((j+1)) $((j+2)) $((j+3)) $((j+4)) $((j+5));
		do
			printf "\033[48;5;${code}m %3d " $code
		done
		
		printf "\033[0m    \033[38;5;235m"
		for code in $((j+18)) $((j+19)) $((j+20)) $((j+21)) $((j+22)) $((j+23));
		do
			printf "\033[48;5;${code}m %3d " $code
		done
		
		printf "\033[0m\n"
	done
	
	printf "\n"
done

printf "\033[0mGrayscale:\n\n    "
for code in {232..255}
do
	printf "\033[48;5;${code}m %.3d " $code
	if [ $code -eq 243 ] 
	then
		printf "\033[0m\n\033[38;5;16m    "
	fi
done

# Reset the terminal color. 
printf "\033[0m\n"