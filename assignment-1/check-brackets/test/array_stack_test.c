#include <assert.h>
#include <stdio.h>
#include "../src/array_stack.h"

void test_initializing_array_stack() {
  a_stack stack;
  stack_init(&stack);
  stack.contents[0] = 50;

  assert(stack.size == 0);
  assert(stack.contents[0] == 50);
}

void test_destroying_array_stack() {
  a_stack stack;
  stack_init(&stack);
  stack.contents[0] = 50;
  stack_destroy(&stack);

  assert(stack.size == -1);
  assert(stack.contents == NULL);
}

void test_pushing_to_array_stack() {
  a_stack stack;
  stack_init(&stack);
  stack_push(&stack, 5);

  assert(stack.size == 1);
  assert(stack.contents[0] == 5);
}

void test_popping_array_stack() {
  int res, err;
  a_stack stack;
  stack_init(&stack);
  stack_push(&stack, 5);
  err = stack_pop(&stack, &res);

  assert(stack.size == 0);
  assert(res == 5);
}

void test_popping_empty_stack() {
  int res, err;
  res = 66;
  a_stack stack;
  stack_init(&stack);
  err = stack_pop(&stack, &res);

  assert(stack.size == 0);
  assert(res == 66);
  assert(err == 1);
}

void test_is_stack_empty() {
  int res;
  a_stack stack;
  stack_init(&stack);
  res = is_stack_empty(&stack);

  assert(res == 1);
}

int main() {
  test_initializing_array_stack();
  test_destroying_array_stack();
  test_pushing_to_array_stack();
  test_popping_array_stack();
  test_popping_empty_stack();
  test_is_stack_empty();
  printf("All tests passing\n");
}
