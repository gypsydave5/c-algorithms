#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *contents;
  int size;
} a_stack;

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

int main() {
  char str[1000000];
  int res;
  scanf("%s", str);

  res = is_balanced_array_stack(str);

  if (res < 0) {
    printf("Success\n");
  } else {
    printf("%d\n", res);
  }
}
