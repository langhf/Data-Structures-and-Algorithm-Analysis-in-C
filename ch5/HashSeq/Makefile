CC = gcc

CFLAGS = -Og -Wall -I .
LDLIBS = -lpthread -lm

COUNTERARGS = -O1 -Wall 

PROGS = HashSep\
		main\

all: $(PROGS)

main: HashSep.o main.o
clean:
	rm -r $(PROGS) *.o *.~