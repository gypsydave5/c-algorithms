#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *contents;
  int size;
} a_stack;

int is_stack_empty(a_stack *sp) {
  if (sp->size > 0) {
    return 0;
  }
  return 1;
}

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
