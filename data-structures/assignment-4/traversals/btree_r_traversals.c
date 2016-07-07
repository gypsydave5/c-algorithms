#include <stdlib.h>
#include "btree.h"
#include "stack.h"

void pre_order(node* n, void (*f)(int)) {
  if (n != NULL) {
    (*f)(n->value);
    pre_order(n->left, f);
    pre_order(n->right, f);
  }
}

void inorder(node* n, void (*f)(int)) {
  if (n != NULL) {
    inorder(n->left, f);
    (*f)(n->value);
    inorder(n->right, f);
  }
}

void post_order(node* n, void (*f)(int)) {
  if (n != NULL) {
    post_order(n->left, f);
    post_order(n->right, f);
    (*f)(n->value);
  }
}
