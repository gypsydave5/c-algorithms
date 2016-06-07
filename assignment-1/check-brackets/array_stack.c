#include <stdlib.h>
#include "array_stack.h"

void stack_init(a_stack *sp) {
  char *newContents;
  newContents = (char *)malloc(sizeof(char) * 1000000);
  sp->contents = newContents;
  sp->size = 0;
}

void stack_destroy(a_stack *sp) {
  free(sp->contents);
  sp->contents = NULL;
  sp->size = -1;
}

void stack_push(a_stack *sp, char c) {
  sp->contents[sp->size] = c;
  sp->size++;
}

char stack_pop(a_stack *sp) {
  sp->size--;
  return sp->contents[sp->size];
}
