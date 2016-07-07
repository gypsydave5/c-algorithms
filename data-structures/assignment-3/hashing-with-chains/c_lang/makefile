ut: build-ut
	./linked-list-unit-test.bin && \
	./hash-function-unit-test.bin && \
	./chain-hash-unit-test.bin

at: build
	cram test.t

sat: build-sub
	cram test.t

build-sub:
	gcc submission.c -o ./hash.bin

build:
	gcc main.c chain-hash.c linked-list.c hash-function.c -o ./hash.bin

build-ut: build-linked-list-spec build-hash-function-spec build-chain-hash-spec

build-linked-list-spec:
	gcc linked-list.c linked-list.spec.c -o ./linked-list-unit-test.bin

build-hash-function-spec:
	gcc hash-function.c hash-function.spec.c -o ./hash-function-unit-test.bin

build-chain-hash-spec:
	gcc chain-hash.c linked-list.c hash-function.c chain-hash.spec.c -o ./chain-hash-unit-test.bin

tidy:
	rm linked-list-unit-test.bin a.out

hf-build:
	gcc hash-function-main.c hash-function.c -o hash-function.bin
