#include <stdlib.h>
#include "array_stack.h"

void stack_init(a_stack *sp) {
  int *newContents;
  newContents = (int *)malloc(sizeof(int) * 1000000);
  sp->contents = newContents;
  sp->size = 0;
}

void stack_destroy(a_stack *sp) {
  free(sp->contents);
  sp->contents = NULL;
  sp->size = -1;
}

void stack_push(a_stack *sp, int c) {
  sp->contents[sp->size] = c;
  sp->size++;
}

int stack_pop(a_stack *sp, int *a) {
  if (is_stack_empty(sp)) {
    return 1;
  }
  sp->size--;
  *a = sp->contents[sp->size];
  return 0;
}

int is_stack_empty(a_stack *sp) {
  if (sp->size > 0) {
    return 0;
  }
  return 1;
}
