#!/bin/sh
# 
# File:   global-config.sh
# Author: Javier Marrero
#
# Created on Feb 15, 2022, 12:04:56 PM
#

 Include user variables if available
if [ -f variables.sh ]; then
	. variables.sh
fi

#
# Overrides a variable if it is not set
#
#   with CC "g++"
#
with() {
	if [ -z "${!1}" ]; then eval $1='$2'; fi
}

isset() {
	printf "\e[37;3mChecking for existence of variable: $1\e[0m"
	if [ -z "${!1}" ];
	then
		printf "\e[31;1m\nerror:\e[0m missing variable $1\n"
		exit 1
	else
		printf "\e[37;3m (value: ${!1})\n\e[0m"
	fi
}

checkpath() {
	printf "\e[37;3mChecking for existence of directory: $1\e[0m\n"

	if ! [ -d "$1" ];
	then
		printf "\e[31;1merror:\e[0m invalid directory: '$1'\n"
		exit 1
	fi
}

isdir() {
	printf "\e[37;3mChecking for existence of directory: $1\e[0m\n"

	if ! [ -d "$1" ];
	then
		printf "\e[31;1merror:\e[0m inexistent directory: '$1'\n"
		false
	else
		true
	fi
}

getback() {
	cd ..
}

#
# Requires the specified tool, quits with an error otherwise
#
#   requireTool "g++"
#
checktool() {
	if ! type "$1" >/dev/null 2>&1
	then
		>&2 printf "\e[31;1merror:\e[0m missing required tool '$1'"
		exit 1
	else
		>&2 echo "info: found required tool '$1.'"
		echo "Getting version for $1: $($1 --version)." >> tools-log.txt 2>&1
		echo >> tools-log.txt 2>&1
	fi
}

#
# Prints a list entry
#
#   list "example.txt"
#
list() {
	echo " - '$1'"
}

#
# Cleans the given directory
#
#   cleanDirectory "bin"
#
cleandir() {
	if [ -d "$1" ]
	then
		rm -rf $1
	fi
	mkdir "$1"
	list $1
}

#
# Removes the given file
#
#	remove "file.txt"
#
remove() {
	if [ -e "$1" ]
	then
		rm -f $1
	fi
	list $1
}

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

#
# Converts a source path to an object
#
#   sourceToObject "src/myclass.cpp"
#
sto() {
	echo $1.o | sed "s/\//_/g"
}


#
# Prints a header
#
headline() {
	printf "\e[0;1m$1\e[0m\n"
}

target_headline() {
	printf "\e[0;7m\nTARGET:\e[0m $1\n\n"
}

target_successful() {
	printf "\e[32;1mtarget successful\e[0m\n\n"
}

info() {
	printf "\e[32;1minfo:\e[0m $1\n"
}

warning() {
	printf "\e[33;1mwarning:\e[0m $1\n"
}

error() {
	printf "\e[31;1merror: \e[0m $1\n\n"
}

fatal() {
	printf "\e[31;1merror: \e[0m $1\n\n"
	exit 1
}

#
# Utils
#
pushd () {
    command pushd "$@" > /dev/null
}

popd () {
    command popd "$@" > /dev/null
}

# Global variables
export ABSOLUTE_PATH="$(dirname $(realpath $0))"

