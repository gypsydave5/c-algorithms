#include "btree.h"
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

void init(node **n, int value) {
  (*n)->value = value;
  (*n)->sum = value;
  (*n)->child[LEFT] = 0;
  (*n)->child[RIGHT] = 0;
  (*n)->parent = 0;
}

void insert(node **root, int new_value) {
  node *new_node;
  new_node = malloc(sizeof(node));
  init(&new_node, new_value);

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

int contains(node **root, int value) {
  splay(root, value);
  return *root != 0 && (*root)->value == value;
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

