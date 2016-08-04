#include <stdlib.h>
#include "btree.h"

void joinLeft(node **parent, node **leftChild) {
  (*parent)->child[LEFT] = *leftChild;
  (*leftChild)->parent = *parent;
}
void joinRight(node **parent, node **rightChild) {
  (*parent)->child[RIGHT] = *rightChild;
  (*rightChild)->parent = *parent;
}

void init(node **n, int value) {
  (*n)->value = value;
  (*n)->sum = value;
  (*n)->child[LEFT] = NULL;
  (*n)->child[RIGHT] = NULL;
  (*n)->parent = NULL;
}

node *find(node *root, int value) {
  node *previous;
  previous = NULL;
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

