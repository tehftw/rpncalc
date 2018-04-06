
OUT = rpncalc.out
CPPSOURCES = main.cpp dstack.cpp chstack.cpp functions.cpp
OBJECTFILES = $(subst .cpp,.o,$(CPPSOURCES))

CPPCOMPILER = clang++
CPP_COMPILER_FLAGS = -std=c++11 -lm

GCCFLAGS = -Wall -g

CPPCHECK = cppcheck
CPPCHECKFLAGS = -q


rpncalc: $(CPPSOURCES)
	$(CPPCOMPILER) $(CPP_COMPILER_FLAGS) $(CPPSOURCES) -o $(OUT) -I .
