#include <assert.h>
#include <stdio.h>
#include "array_stack.h"

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
  stack_push(&stack, 'b');

  assert(stack.size == 1);
  assert(stack.contents[0] == 'b');
}

void test_popping_array_stack() {
  char res;
  a_stack stack;
  stack_init(&stack);
  stack_push(&stack, 'b');
  res = stack_pop(&stack);

  assert(stack.size == 0);
  assert(res == 'b');
}

int main() {
  test_initializing_array_stack();
  test_destroying_array_stack();
  test_pushing_to_array_stack();
  test_popping_array_stack();
  printf("All tests passing\n");
}
