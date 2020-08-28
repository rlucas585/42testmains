#!/bin/bash
DEFAULT="\e[39m"
BLACK="\e[30m"
RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
MAGENTA="\e[35m"
CYAN="\e[36m"

if [ -e "libftprintf.a" ]
then
	make
	./printf_tester
	diff real.output test.output > diff.output
	filesize=$(wc -c <"diff.output")
	if [ $filesize -ne 0 ]
	then
		printf $RED"Test failure\n"$NORMAL
	else
		printf $GREEN"Output matches in all tests\n"$NORMAL
	fi
else
	printf $RED"Please make sure that libftprintf.a is in the current directory\n"$NORMAL
fi
