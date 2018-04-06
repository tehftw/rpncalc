
CPPSOURCES = main.cpp dstack.cpp chstack.cpp functions.cpp
OUT = rpncalc.out

CC = clang++
FLAGS = -std=c++11 -lm

GCCFLAGS = -Wall -g

rpncalc: $(CPPFILES)
	$(CC) $(FLAGS) $(CPPSOURCES) -o $(OUT) -I .
