#include "btree.h"
#include <limits.h>
#include <stdlib.h>
#include "splay.h"

static unsigned long long getSum(node *node) {
  if (node == 0) {
    return 0;
  }
  return node->sum;
}

static unsigned long long getValue(node *node) {
  if (node == 0) return 0;
  return node->value;
}

void join(unsigned long long direction, node **parent, node **child) {
  (*parent)->child[direction] = *child;
  if (*child != 0) {
    (*child)->parent = *parent;
  }
}

void treeCalcSum(node **root) {
  unsigned long long new_sum;
  new_sum = 0;
  if (*root == 0) return;

  new_sum += getSum((*root)->child[LEFT]);
  new_sum += getSum((*root)->child[RIGHT]);
  (*root)->sum = new_sum + (*root)->value;
}

void update(node *n) {
  treeCalcSum(&n);
  if (n->child[LEFT]) {
    n->child[LEFT]->parent = n;
  }
  if (n->child[RIGHT]) {
    n->child[RIGHT]->parent = n;
  }
}

void treeInit(node **n, unsigned long long value) {
  (*n)->value = value;
  (*n)->sum = value;
  (*n)->child[LEFT] = 0;
  (*n)->child[RIGHT] = 0;
  (*n)->parent = 0;
}

void treeInsert(node **root, unsigned long long new_value) {
  unsigned long long direction;
  node *new_node;
  splay(root, new_value);

  if (*root != 0 && (*root)->value == new_value) return;

  new_node = malloc(sizeof(node));
  treeInit(&new_node, new_value);

  if (*root == 0) {
    *root = new_node;
    return;
  }

  direction = (*root)->value > new_value;

  join(direction, &new_node, root);
  join(!direction, &new_node, &(*root)->child[!direction]);
  (*root)->child[!direction] = 0;

  *root = new_node;
}

unsigned long long treeContains(node **root, unsigned long long value) {
  splay(root, value);
  return *root != 0 && (*root)->value == value;
}

void treeRemove(node **root, unsigned long long target) {
  node *left, *right;
  splay(root, target);
  if (*root == 0 || (*root)->value != target) return;

  left = (*root)->child[LEFT];
  right = (*root)->child[RIGHT];
  free(*root);
  *root = 0;

  if (left == 0 && right == 0) {
    *root = 0;
    return;
  }

  if (left == 0) {
    right->parent = 0;
    *root = right;
    return;
  }

  splay(&left, ULLONG_MAX);
  join(RIGHT, &left, &right);
  *root = left;
}

void treeSplit(node **root, node **greater_or_equal,
               unsigned long long target) {
  if (*root == 0) return;

  splay(root, target);

  if (getValue(*root) < target) {
    *greater_or_equal = (*root)->child[RIGHT];
    if (*greater_or_equal) (*greater_or_equal)->parent = 0;
    (*root)->child[RIGHT] = 0;
  } else {
    *greater_or_equal = *root;
    *root = (*root)->child[LEFT];
    if (*root) (*root)->parent = 0;
    (*greater_or_equal)->child[LEFT] = 0;
  }

  treeCalcSum(root);
  treeCalcSum(greater_or_equal);
}

void treeMerge(node **left_tree, node **right_tree) {
  if (*right_tree == 0) return;
  if (*left_tree == 0) {
    *left_tree = *right_tree;
    return;
  }

  splay(left_tree, ULLONG_MAX);
  join(RIGHT, left_tree, right_tree);
}

node *find(node *root, unsigned long long value) {
  node *previous;
  previous = 0;
  while (1) {
    if (root == 0) {
      return previous;
    }
    if (root->value == value) {
      return root;
    }
    if (root->value > value) {
      previous = root;
      root = root->child[LEFT];
    } else {
      previous = root;
      root = root->child[RIGHT];
    }
  }
}

static int empty(node *pointer) { return pointer == 0; }

unsigned long long treeSumRange(node **root, unsigned long long left_bound,
                                unsigned long long right_bound) {
  unsigned long long result;
  node *left, *right;
  result = 0;
  left = right = 0;

  if (empty(*root) || left_bound > right_bound) return result;

  treeSplit(root, &left, left_bound);
  treeSplit(&left, &right, right_bound);
  result += getSum(left);

  if (empty(left) && getValue(right) < left_bound) {
    return result;
  }

  if (getValue(left) < left_bound) {
    result -= getValue(left);
  }

  if (getValue(right) <= right_bound) {
    result += getValue(right);
  }

  treeMerge(&left, &right);
  treeMerge(root, &left);

  return result;
}

void treeDestroy(node **root) {
  while (*root != 0) {
    treeRemove(root, (*root)->value);
  }
}
