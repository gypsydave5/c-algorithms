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

void btree_destroy(node **root) {
  if (*root) {
    int i;
    for (i = 0; i < NUM_CHILDREN; i++) {
      btree_destroy(&(*root)->child[i]);
    }
    free(*root);
  }
  *root = NULL;
}

node *find(node *root, int target) {
  while (root != NULL && root->value != target) {
    if (root->value > target) {
      if (root->child[LEFT] != NULL) {
        root = root->child[LEFT];
      } else {
        return root;
      }
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

static void promote(node *target, node *replacement) {
  node *parent = target->parent;
  replacement->parent = parent;
  if (parent) {
    if (parent->child[LEFT] == target) {
      parent->child[LEFT] = replacement;
    } else {
      parent->child[RIGHT] = replacement;
    }
  }
}

static void replace(node *target, node *replacement) {
  promote(target, replacement);
  replacement->child[LEFT] = target->child[LEFT];
  replacement->child[RIGHT] = target->child[RIGHT];
}

static void remove_from_parent(node *target) {
  if (target->parent == NULL) {
    node_init(target);
    return;
  }
  if (target->parent->child[LEFT] == target) {
    target->parent->child[LEFT] = NULL;
    if (target) {
      free(target);
    }
    return;
  }
  target->parent->child[RIGHT] = NULL;
  if (target) {
    free(target);
  }
}

void delete_node(node **root, node *target) {
  node *replacement;
  if (!(target->child[LEFT] || target->child[RIGHT])) {
    remove_from_parent(target);
  } else {
    if (target->child[RIGHT] == NULL) {
      replacement = target->child[LEFT];
      promote(target, replacement);
    } else {
      replacement = next(target);
      if (replacement->child[RIGHT]) {
        promote(replacement, replacement->child[RIGHT]);
      } else {
        replacement->parent->child[LEFT] = NULL;
      }
      replace(target, replacement);
    }
    if (*root == target) {
      *root = replacement;
    }
  }
  if (target) {
    free(target);
  }
}

int btree_range_sum(node **root, int start, int end) {
  int result;
  result = 0;
  node *target;
  target = find(*root, start);
  while (target && target->value <= end) {
    result += target->value;
    target = next(target);
  }
  return result;
}
