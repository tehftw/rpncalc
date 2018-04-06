# /bin/bash

clear && 
	cppcheck *.c && 
	echo ____________________cppcheck on all .c files finished &&
	make && 
	echo ____________________build finished &&
	./rpncalc.out
