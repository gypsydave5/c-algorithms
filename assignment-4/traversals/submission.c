#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int value;
  int height;
  struct node *parent;
  struct node *left;
  struct node *right;
} node;

typedef struct elt {
  struct elt* next;
  node* node;
} elt;

void node_init(node *n) {
  n->parent = NULL;
  n->left = NULL;
  n->right = NULL;
  n->value = -1;
  n->height = -1;
}

void node_copy(node *source, node *destination) {
  destination->value = source->value;
  destination->left = source->left;
  destination->right = source->right;
  destination->height = source->height;
  destination->parent = source->parent;
}

elt *stack_init() { return NULL; }

void stack_destroy(elt **head) {
  elt *current, *next;
  current = *head;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}

void stack_push(elt **head, node *n) {
  elt *new_el;
  new_el = malloc(sizeof(elt));
  new_el->node = n;
  new_el->next = *head;
  *head = new_el;
}

node *stack_pop(elt **head) {
  node *n;
  n = (*head)->node;
  elt *new_head;
  new_head = (*head)->next;
  free(*head);
  *head = new_head;
  return n;
}

node *stack_peek(elt *head) { return head->node; }
void pre_order(node* n, void (*f)(int)) {
  elt* stack;
  node* current;
  stack = stack_init();
  stack_push(&stack, n);

  while (stack != NULL) {
    current = stack_pop(&stack);

    (*f)(current->value);
    if (current->right != NULL) {
      stack_push(&stack, current->right);
    }
    if (current->left != NULL) {
      stack_push(&stack, current->left);
    }
  }
}

void inorder(node* n, void (*f)(int)) {
  elt* stack;
  stack = stack_init();
  node* current = n;

  while (stack != NULL || current != NULL) {
    if (current != NULL) {
      stack_push(&stack, current);
      current = current->left;
    } else {
      current = stack_pop(&stack);
      (*f)(current->value);
      current = current->right;
    }
  }
}

void post_order(node* n, void (*f)(int)) {
  elt* stack;
  stack = stack_init();
  node *current, *temp;
  current = n;

  while (current != NULL || stack != NULL) {
    if (current != NULL) {
      if (current->right != NULL) {
        stack_push(&stack, current->right);
      }
      stack_push(&stack, current);
      current = current->left;
    } else {
      current = stack_pop(&stack);
      if (current->right != NULL && stack != NULL &&
          stack_peek(stack)->value == current->right->value) {
        temp = current;
        current = stack_pop(&stack);
        stack_push(&stack, temp);
      } else {
        (*f)(current->value);
        current = NULL;
      }
    }
  }
}

void print_int(int i) { printf("%d ", i); }

int main() {
  int node_count, i;
  scanf("%d\n", &node_count);

  node nodes[node_count];

  for (i = 0; i < node_count; i++) {
    int value, left, right;
    node_init(&nodes[i]);

    scanf("%d %d %d", &value, &left, &right);
    nodes[i].value = value;

    if (left != -1) {
      nodes[i].left = &nodes[left];
      nodes[left].parent = &nodes[i];
    }

    if (right != -1) {
      nodes[i].right = &nodes[right];
      nodes[right].parent = &nodes[i];
    }
  }

  inorder(&nodes[0], print_int);
  printf("\n");
  pre_order(&nodes[0], print_int);
  printf("\n");
  post_order(&nodes[0], print_int);
  printf("\n");
}

