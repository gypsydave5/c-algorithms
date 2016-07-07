CC=gcc
CFLAGS=-std=c11 -Wall -pedantic -g3
PERF=-pg
PROD=-O2

ut: btree-spec stack-spec
	./btree-spec && \
	./stack-spec

btree-spec: btree.spec.o btree.o
	$(CC) $(CFLAGS) -o $@ $^

stack-spec: stack.o stack.spec.o btree.o
	$(CC) $(CFLAGS) -o $@ $^

stack.o: stack.h stack.c
stack.spec.o: stack.h stack.spec.c
btree.o: stack.h btree.c
btree.spec.o: btree.spec.c btree.h

clean:
	$(RM) *.bin *.o stack-spec btree-spec
