npmcalc: main.c dstack.c chstack.c
	gcc main.c dstack.c chstack.c -o npmcalc.o -I . -lm
