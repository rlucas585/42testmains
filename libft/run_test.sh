#!/bin/bash

# Define colors
RED='\033[00;31m'
GREEN='\033[00;32m'

# Define directory for library and flags
LIBDIR="mylibft"
FLAGS="-Wall -Werror -Wextra"

# Compile my own results and place them in text file
gcc -o testexec $FLAGS -lft -L$LIBDIR -I$LIBDIR testmain.c
./testexec > ryanout.txt
cat fd_tests >> ryanout.txt
rm fd_tests

# Use makefile of evaluated person to create their library, then compile their
# executable and place results in text file
make -C evaluation
gcc -o testexec $FLAGS -lft -Levaluation -Ievaluation testmain.c
./testexec > evalout.txt
cat fd_tests >> evalout.txt

# Generate a diff file of the differences in results
diff ryanout.txt evalout.txt > results.diff

# Count the number of lines that differ between files, and trim the output to
# show number of differences
some_var="$(diff "ryanout.txt" "evalout.txt" | grep ">" | wc -l | tr -d " " \
	| tr -d "\n")"
if [ $some_var -ne 0 ]; then
	printf "${RED} There are "
	cat -e results.diff | grep ">" | wc -l | tr -d " " | tr -d "\n"
	printf " differences \n"
else
	printf "${GREEN} There are "
	cat -e results.diff | grep ">" | wc -l | tr -d " " | tr -d "\n"
	printf " differences \n"
fi

# Delete fd_tests and executable
rm fd_tests testexec
