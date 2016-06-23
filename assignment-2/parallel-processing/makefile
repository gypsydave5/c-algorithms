ac-test: build-submission
	cram test.t

build-submission:
	gcc submission.c -o parallel-processing.bin

build-heap:
	gcc main.c pp_heap.c -o parallel-processing.bin

build-sort:
	gcc main.c pp_sort.c -o parallel-processing.bin

stress:
	gcc stress-test.c pp_heap.c pp_sort.c -o stress-test.bin && ./stress-test.bin
