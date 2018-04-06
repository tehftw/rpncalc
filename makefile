appname := rpncalc
default: $(appname)

CC := clang
CFLAGS := -Wall -lm -g

RM=rm -f

srcfiles :=  $(wildcard *.c)
objects := $(patsubst %.c, %.o, $(srcfiles) )


$(appname): $(objects)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)

clean:
	$(RM) $(objects)
