#include <stdlib.h>
#include "btree.h"

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
