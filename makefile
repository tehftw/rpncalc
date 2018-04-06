appname := rpncalc

CXX := clang++
CXXFLAGS := -std=c++11 -lm -Wall -g

srcfiles := $(shell find . -name "*.cpp")
objects := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)


