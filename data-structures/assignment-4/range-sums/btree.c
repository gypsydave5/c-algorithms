#include "btree.h"
#include <limits.h>
#include <stdlib.h>
#include "splay.h"

void joinLeft(node **parent, node **leftChild) {
  (*parent)->child[LEFT] = *leftChild;
  (*leftChild)->parent = *parent;
}
void joinRight(node **parent, node **rightChild) {
  (*parent)->child[RIGHT] = *rightChild;
  (*rightChild)->parent = *parent;
}

void treeInit(node **n, int value) {
  (*n)->value = value;
  (*n)->sum = value;
  (*n)->child[LEFT] = 0;
  (*n)->child[RIGHT] = 0;
  (*n)->parent = 0;
}

void treeInsert(node **root, int new_value) {
  node *new_node;
  new_node = malloc(sizeof(node));
  treeInit(&new_node, new_value);

  int direction;
  splay(root, new_value);
  if (*root == 0) {
    *root = new_node;
    return;
  }

  direction = (*root)->value > new_value;

  new_node->child[direction] = *root;
  (*root)->parent = new_node;

  new_node->child[!direction] = (*root)->child[!direction];
  if (new_node->child[!direction]) {
    new_node->child[!direction]->parent = new_node;
  }

  (*root)->child[!direction] = 0;
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
  if (left == 0) {
    *root = right;
    return;
  }

  splay(&left, INT_MAX);
  left->child[RIGHT] = right;
  if (right != 0) {
    right->parent = left;
  }
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
}

void treeMerge(node **tree_one, node **tree_two) {
  if (*tree_one == 0) {
    *tree_one = *tree_two;
    return;
  }
  if (*tree_two == 0) {
    return;
  }

  splay(tree_one, INT_MAX);
  (*tree_one)->child[RIGHT] = *tree_two;
  (*tree_two)->parent = *tree_one;
}

node *find(node *root, int value) {
  node *previous;
  previous = 0;
  while (1) {
    if (!root) {
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

