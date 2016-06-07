test: build-test
	./test_bin && rm test_bin

build-test:
	gcc ./src/array_stack.c ./test/array_stack_test.c -o test_bin

build-main:
	gcc ./src/array_stack.c ./src/main.c ./src/is_balanced_array_stack.c -o main
