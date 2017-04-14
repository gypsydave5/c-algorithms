CC=gcc
CFLAGS=-std=c11 -Wall -pedantic -g3
PERF=-pg
PROD=-O2
NAME=kmp

test: ut at

at: build
	cram test.t

ut: prefix_test kmp_test
	./prefix_test && ./kmp_test

build: main.o kmp.o prefix.o
	$(CC) $(CFLAGS) -o $(NAME) $^

main.o: main.c kmp.h

prefix_test: prefix_test.o prefix.o
kmp_test: kmp_test.o kmp.o prefix.o

prefix_test.o: prefix_test.c prefix.h
prefix.o: prefix.c prefix.h

kmp_test.o: kmp_test.c kmp.h prefix.h
kmp.o: kmp.c kmp.h prefix.h

test_sub: submission
	cram test.t

submission: submission.c
	$(CC) $(CFLAGS) -o $(NAME) $^

clean:
	$(RM) *.o $(NAME) *.err *_test
