rpncalc: main.c dstack.c chstack.c functions.c
	gcc main.c dstack.c chstack.c functions.c -o rpncalc.o -I . -lm
