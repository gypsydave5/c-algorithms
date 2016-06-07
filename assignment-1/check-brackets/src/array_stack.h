typedef struct {
  char *contents;
  int size;
} a_stack;

void stack_init(a_stack *sp);
void stack_destroy(a_stack *sp);
char stack_pop(a_stack *sp);
void stack_push(a_stack *sp, char c);
