#include <stdio.h>
#include "array_stack.h"
#include "is_balanced.h"

static int pop_mismatch(char pop, char c) {
  if ((c == '}') && (pop != '{')) {
    return 1;
  }
  if ((c == ']') && (pop != '[')) {
    return 1;
  }
  if ((c == ')') && (pop != '(')) {
    return 1;
  }
  return 0;
}

int is_balanced_array_stack(char string[1000000]) {
  int i, pop, err;
  char c;
  a_stack s;

  stack_init(&s);

  for (i = 0; i < 1000000; i++) {
    c = string[i];
    if (c == '\0') {
      if (s.size == 0) {
        return -1;
      } else {
        stack_pop(&s, &pop);
        return pop + 1;
      }
    }

    if (c == '{' || c == '[' || c == '(') {
      stack_push(&s, i);
    }

    if (c == '}' || c == ']' || c == ')') {
      err = stack_pop(&s, &pop);
      if (err) {
        return i + 1;
      }
      if (pop_mismatch(string[pop], c)) {
        return i + 1;
      }
    }
  }
  return -1;
}
