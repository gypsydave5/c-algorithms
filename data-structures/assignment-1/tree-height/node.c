#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void node_init(node *n) {
  darray da;
  darray_init(&da);

  n->parent = NULL;
  n->id = -1;
  n->childCount = 0;
  n->children = da;
}

void node_add_child(node *child, node *parent) {
  child->parent = parent;
  darray_push(&parent->children, child);
  parent->childCount++;
}

long long tree_depth_r(node *root) {
  long long i, depth;
  depth = -1;
  if (root->childCount == 0) {
    return 1;
  }
  for (i = 0; i < root->childCount; i++) {
    long long d;
    d = tree_depth_r(darray_get(&root->children, i)) + 1;
    depth = d > depth ? d : depth;
  }
  return depth;
}

long long tree_depth_i(node *root) {
  long long depth, i, j;
  darray current_level;
  darray_init(&current_level);
  darray_push(&current_level, root);
  depth = 0;

  while (current_level.top != -1) {
    darray next_level;
    darray_init(&next_level);

    for (i = 0; i <= current_level.top; i++) {
      node *current_node;
      current_node = darray_get(&current_level, i);

      if (current_node->childCount > 0) {
        for (j = 0; j < current_node->childCount; j++) {
          darray_push(&next_level, darray_get(&current_node->children, j));
        }
      }
    }

    depth++;
    current_level = next_level;
  }
  return depth;
}
