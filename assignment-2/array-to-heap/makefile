default: ac-test

ac-test: build-submission
	cram test.t

build:
	gcc main.c log.c heap-array.c -o array-to-heap.bin

test:
	gcc log.c heap-array.c heap-array.spec.c -o heap-array.spec.bin && ./heap-array.spec.bin

build-submission:
	gcc submission.c -o heap-array.bin
