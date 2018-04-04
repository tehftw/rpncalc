npmcalc: main.c dstack.c chstack.c functions.c
	gcc main.c dstack.c chstack.c functions.c -o npmcalc.o -I . -lm
