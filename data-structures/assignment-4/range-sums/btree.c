#include <stdlib.h>
#include "btree.h"

void node_init(node *n) {
  int i;
  n->parent = NULL;
  for (i = 0; i < NUM_CHILDREN; i++) {
    n->child[i] = NULL;
  }
  n->value = -1;
  n->height = -1;
}

void node_copy(node *source, node *destination) {
  int i;
  destination->value = source->value;
  for (i = 0; i < NUM_CHILDREN; i++) {
    destination->child[i] = source->child[i];
  }
  destination->height = source->height;
  destination->parent = source->parent;
}

node *find(node *root, int target) {
  while (root != NULL && root->value != target) {
    if (root->value > target) {
      root = root->child[LEFT];
    } else {
      root = root->child[RIGHT];
    }
  }
  return root;
}

void insert(node *root, int value) {
  if (root->value == -1) {
    root->value = value;
    return;
  }

  node *new_node;
  new_node = malloc(sizeof(node));
  node_init(new_node);
  new_node->value = value;
  while (1) {
    if (root->value > value) {
      if (root->child[LEFT]) {
        root = root->child[LEFT];
      } else {
        root->child[LEFT] = new_node;
        new_node->parent = root;
        return;
      }
    } else {
      if (root->child[RIGHT]) {
        root = root->child[RIGHT];
      } else {
        root->child[RIGHT] = new_node;
        new_node->parent = root;
        return;
      }
    }
  }
}

static node *left_descendent(node *n) {
  for (;;) {
    if (n->child[LEFT] == NULL) {
      return n;
    }

    n = n->child[LEFT];
  }
}

static node *right_ancestor(node *n) {
  for (;;) {
    if (n->parent == NULL) {
      return NULL;
    }
    if (n->value < n->parent->value) {
      return n->parent;
    }
    n = n->parent;
  }
}

node *next(node *n) {
  if (n->child[RIGHT]) {
    return left_descendent(n->child[RIGHT]);
  } else {
    return right_ancestor(n);
  }
}
