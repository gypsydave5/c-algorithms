typedef struct {
  int *contents;
  int size;
} a_stack;

void stack_init(a_stack *sp);
void stack_destroy(a_stack *sp);
int stack_pop(a_stack *sp, int *a);
void stack_push(a_stack *sp, int c);
int is_stack_empty(a_stack *sp);
