CC=gcc
CFLAGS=-std=c11 -Wall -pedantic -g3
PERF=-pg
PROD=-O2
NAME=bwt

test: ut at

at: build
	cram test.t

ut: bwt-test
	./bwt-test

build: main.o bwt.o
	$(CC) $(CFLAGS) -o $(NAME) $^

main.o: main.c bwt.h

bwt-test: bwt.test.o bwt.o
	$(CC) $(CFLAGS) -o $@ $^

bwt.test.o: bwt.test.c bwt.h
bwt.o: bwt.c bwt.h

clean:
	$(RM) *.o $(NAME) *-test *.err
