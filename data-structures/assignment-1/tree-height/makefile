test:
	gcc node.c darray.c darray.spec.c -o darray.spec.bin && ./darray.spec.bin

acceptance: build
	cram test.t

build:
	gcc node.c darray.c main.c -o tree-height.out
