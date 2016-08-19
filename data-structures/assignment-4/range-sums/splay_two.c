#include "btree.h"
#include "splay.h"

static void smallRotation(node *target) {
  node *parent = target->parent;
  if (parent == 0) return;

  node *grandparent = target->parent->parent;
  if (parent->child[LEFT] == target) {
    node *m = target->child[RIGHT];
    target->child[RIGHT] = parent;
    parent->child[LEFT] = m;
  } else {
    node *m = target->child[LEFT];
    target->child[LEFT] = parent;
    parent->child[RIGHT] = m;
  }
  update(parent);
  update(target);

  target->parent = grandparent;
  if (grandparent != 0) {
    if (grandparent->child[LEFT] == parent) {
      grandparent->child[LEFT] = target;
    } else {
      grandparent->child[RIGHT] = target;
    }
  }
}

static void bigRotation(node *target) {
  if (target->parent->child[LEFT] == target &&
      target->parent->parent->child[LEFT] == target->parent) {
    smallRotation(target->parent);
    smallRotation(target);
  } else if (target->parent->child[RIGHT] == target &&
             target->parent->parent->child[RIGHT] == target->parent) {
    smallRotation(target->parent);
    smallRotation(target);
  } else {
    smallRotation(target);
    smallRotation(target);
  }
}

void splay(node **root, unsigned long long value) {
  if (*root == 0) return;
  node *target;
  target = find(*root, value);

  while (target->parent != 0) {
    if (target->parent->parent == 0) {
      smallRotation(target);
      break;
    }
    bigRotation(target);
  }
  *root = target;
}
