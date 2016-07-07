#include <stdlib.h>
#include "btree.h"
#include "stack.h"

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
