rpncalc: main.cpp dstack.cpp chstack.cpp functions.cpp
	g++ -std=c++11 main.cpp dstack.cpp chstack.cpp functions.cpp -o rpncalc.out -I . -lm
