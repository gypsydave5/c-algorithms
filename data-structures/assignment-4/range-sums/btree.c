#include <limits.h>
#include <stdlib.h>
#include "btree.h"
#include "splay.h"

static int getSum(node *node) {
  if (node == 0) {
    return 0;
  }
  return node->sum;
}

static int getValue(node *node) {
  if (node == 0) return 0;
  return node->value;
}

void join(int direction, node **parent, node **child) {
  (*parent)->child[direction] = *child;
  if (*child != 0) {
    (*child)->parent = *parent;
  }
}

void treeCalcSum(node **root) {
  int new_sum;
  new_sum = 0;
  if (*root == 0) return;

  new_sum += getSum((*root)->child[LEFT]);
  new_sum += getSum((*root)->child[RIGHT]);
  (*root)->sum = new_sum + (*root)->value;
}

void treeInit(node **n, int value) {
  (*n)->value = value;
  (*n)->sum = value;
  (*n)->child[LEFT] = 0;
  (*n)->child[RIGHT] = 0;
  (*n)->parent = 0;
}

void treeInsert(node **root, int new_value) {
  int direction;
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

  treeCalcSum(&new_node->child[direction]);
  treeCalcSum(&new_node);
  *root = new_node;
}

int treeContains(node **root, int value) {
  splay(root, value);
  return *root != 0 && (*root)->value == value;
}

void treeRemove(node **root, int target) {
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
    treeCalcSum(&right);
    right->parent = 0;
    *root = right;
    return;
  }

  splay(&left, INT_MAX);
  join(RIGHT, &left, &right);
  treeCalcSum(&left);
  *root = left;
}

void treeSplit(node **root, node **greater_or_equal, int target) {
  splay(root, target);
  *greater_or_equal = *root;
  *root = (*root)->child[LEFT];

  if (*root) {
    (*root)->parent = 0;
  }

  (*greater_or_equal)->child[LEFT] = 0;
  treeCalcSum(root);
  treeCalcSum(greater_or_equal);
}

void treeMerge(node **left_tree, node **right_tree) {
  if (*left_tree == 0) {
    *left_tree = *right_tree;
    return;
  }
  if (*right_tree == 0) {
    return;
  }

  splay(left_tree, INT_MAX);
  join(RIGHT, left_tree, right_tree);
  treeCalcSum(left_tree);
}

node *find(node *root, int value) {
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

int treeSumRange(node **root, int left_bound, int right_bound) {
  int result;
  result = 0;

  if (left_bound > right_bound) {
    return result;
  }

  node *greater_than_left, *greater_than_right;
  treeSplit(root, &greater_than_left, left_bound);
  treeSplit(&greater_than_left, &greater_than_right, right_bound);
  result += getSum(greater_than_left);

  if (getValue(greater_than_left) < left_bound) {
    result -= getValue(greater_than_left);
  }

  if (getValue(greater_than_right) <= right_bound) {
    result += getValue(greater_than_right);
  }

  treeMerge(&greater_than_left, &greater_than_right);
  treeMerge(root, &greater_than_left);

  return result;
}

void treeDestroy(node **root) {
  while (*root != 0) {
    treeRemove(root, (*root)->value);
  }
}
