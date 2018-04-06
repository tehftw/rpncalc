appname := rpncalc

CC := clang
CFLAGS := -Wall -lm -g


srcfiles :=  $(wildcard *.c)
objects := $(patsubst %.c, %.o, $(srcfiles) )

all: $(appname)

$(appname): $(objects)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)
