CC = gcc
CFLAGS = -Wall 
SRCS = $(wildcard 7.*.c)
PROGS = $(patsubst %.c, %, $(SRCS))

all:$(PROGS)

%:%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	find . -type f -executable -print0 | xargs -0 rm -f --