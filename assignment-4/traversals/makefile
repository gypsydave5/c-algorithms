CC=gcc
CFLAGS=-std=c11 -Wall -pedantic -g3 -O2
PERF=-pg

ut: build-spec stack-spec
	./btree-spec && \
	./stack-spec

perf: build-i-perf build-r-perf
	gprof ./btree-i.bin && \
	gprof ./btree-p.bin

at: build
	cram test.t

sat: build-sub
	cram test.t

submission:
	$(CC) $(CFLAGS) -o btree.bin $^

build-i-perf: main.o btree.o stack.o btree_i_traversals.o
	$(CC) $(CFLAGS) $(PERF) -o btree-p.bin $^

build-r-perf: main.o btree.o stack.o btree_r_traversals.o
	$(CC) $(CFLAGS) $(PERF) -o btree-i.bin $^

build-i: main.o btree.o stack.o btree_i_traversals.o
	$(CC) $(CFLAGS) -o btree.bin $^

build-r: main.o btree.o stack.o btree_r_traversals.o
	$(CC) $(CFLAGS) -o btree.bin $^

btree-spec: btree.spec.o btree.o
	$(CC) $(CFLAGS) -o $@ $^

stack-spec: stack.o stack.spec.o btree.o
	$(CC) $(CFLAGS) -o $@ $^

stack.o: stack.h stack.c
stack.spec.o: stack.h stack.spec.c
btree.o: stack.h btree.c
btree.spec.o: btree.spec.c btree.h
main.o: main.c
btree_i_traversals.o: btree_i_traversals.c btree.h
btree_r_traversals.o: btree_i_traversal.c btree.h
submission.o: submission.c

clean:
	$(RM) *.bin *.o stack-spec btree-spec
