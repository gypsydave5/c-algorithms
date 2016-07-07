test-all: test-naive test-binary comparison-test benchmark

build-binary: binary.o
	gcc -pipe -O2 -std=c11 binaryMain.c binarySearch.o -o binarySearch

build-naive: naive.o
	gcc -pipe -O2 -std=c11 naiveMain.c naiveSearch.o -o naiveSearch

build-iterative: iterative.o
	gcc -pipe -O2 -std=c11 binaryIterativeMain.c iterativeBinary.o -o iterativeBinary

build-comparison: binary.o naive.o
	gcc -pipe -O2 -std=c11 comparison.c naiveSearch.o binarySearch.o -o comparison

comparison-test: build-comparison
	cram comparison.t

build-benchmark: binary.o naive.o iterative.o
	gcc -pipe -O2 -std=c11 benchmark.c naiveSearch.o binarySearch.o iterativeBinary.o -o benchmark

benchmark: build-benchmark
	./benchmark

test-naive: build-naive
	SEARCHBIN=naiveSearch cram test.t

test-binary: build-binary
	SEARCHBIN=binarySearch cram test.t

test-iterative: build-iterative
	SEARCHBIN=iterativeBinary cram test.t

naive.o:
	gcc -c -pipe -O2 -std=c11 naiveSearch.c defs.h

binary.o:
	gcc -c -pipe -O2 -std=c11 binarySearch.c defs.h

iterative.o:
	gcc -c -pipe -O2 -std=c11 iterativeBinary.c defs.h

clean:
	rm binarySearch naiveSearch comparison benchmark defs.h.gch naiveSearch.o binarySearch.o iterativeBinary.o
