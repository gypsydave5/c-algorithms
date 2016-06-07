#include <stdio.h>
#include "array_stack.h"
#include "is_balanced.h"

static int pop_mismatch(char pop, char c) {
  if ((pop == '{') && (c != '}')) {
    return 1;
  }
  if ((pop == '[') && (c != ']')) {
    return 1;
  }
  if ((pop == '(') && (c != ')')) {
    return 1;
  }
  return 0;
}

int is_balanced_array_stack(char string[1000000]) {
  int i;
  char c, pop;
  a_stack s;

  stack_init(&s);

  for (i = 0; i < 1000000; i++) {
    c = string[i];
    if (c == '\0') {
      if (s.size == 0) {
        return -1;
      } else {
        return i;
      }
    }

    if (c == '{' || c == '[' || c == '(') {
      stack_push(&s, c);
    }

    if (c == '}' || c == ']' || c == ')') {
      pop = stack_pop(&s);
      if (pop_mismatch(pop, c)) {
        return i + 1;
      }
    }
  }
  return -1;
}
