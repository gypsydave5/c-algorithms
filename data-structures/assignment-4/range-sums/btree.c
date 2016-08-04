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
  (*n)->child[LEFT] = 0;
  (*n)->child[RIGHT] = 0;
  (*n)->parent = 0;
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

