CC=gcc
CFLAGS=-std=c11 -Wall -pedantic -g3
PERF=-pg
PROD=-O2

ut: btree-spec splay-spec splay-two-spec
	./btree-spec && \
	./splay-spec && \
	./splay-two-spec

at: range-sums
	cram acceptance_tests/*.t

stress-test:
	ruby stress_test.rb

submission-at: submission
	cram acceptance_tests/*.t

submission: submission.o
	$(CC) $(CFLAGS) -o range-sums $^
submission.o: submission.c

range-sums: main.o btree.o splay.o
	$(CC) $(CFLAGS) -o $@ $^
main.o: main.c btree.h

btree-spec: btree.spec.o btree.o splay.o
	$(CC) $(CFLAGS) -o $@ $^
btree.spec.o: btree.spec.c btree.h
btree.o: btree.c

splay-spec: splay.spec.o splay.o btree.o
	$(CC) $(CFLAGS) -o $@ $^
splay.o: splay.c

splay-two-spec: splay.spec.o splay_two.o btree.o
	$(CC) $(CFLAGS) -o $@ $^
splay_two.o: splay_two.c

splay.spec.o: splay.spec.c splay.h

clean:
	$(RM) *-spec *.o btree-spec *.err a.out range-sums
