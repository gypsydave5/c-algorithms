CC=gcc
CFLAGS=-std=c11 -Wall -pedantic -g3
PERF=-pg
PROD=-O2
NAME=kmp

test: build
	cram test.t

build: main.o
	$(CC) $(CFLAGS) -o $(NAME) $^

main.o: main.c

clean:
	$(RM) *.o $(NAME) *.err
