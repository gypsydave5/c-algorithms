#include "btree.h"
#include "splay.h"

void splay(node **root, int value) {
  node* target;
  target = find(*root, value);

  while (target->parent) {
    if (target->parent->parent == 0) {
      int direction = target->parent->value < value;
      node *temp;
      temp = target->child[!direction];

      target->child[!direction] = target->parent;
      target->child[!direction]->parent = target;
      target->parent = 0;

      target->child[!direction]->child[direction] = temp;
      temp->parent = target->child[!direction];
    }
  }
  *root = target;
}
