CC=gcc
CFLAGS=-std=c11 -Wall -pedantic -g3
PERF=-pg
PROD=-O2

ut: btree-spec
	./btree-spec

at: range-sums
	cram test.t

btree-spec: btree.spec.o btree.o
	$(CC) $(CFLAGS) -o $@ $^

btree.spec.o: btree.spec.c btree.h
btree.o: btree.c

clean:
	$(RM) *.spec *.o btree-spec *.err
