#include "btree.h"
#include "splay.h"

void splay(node **root, int value) {
  node *target, *temp;
  target = find(*root, value);

  while (target->parent) {
    if (target->parent->parent) {
      // zig zig or zig zag
      int direction, grandparentD;
      direction = target->parent->value < target->value;
      grandparentD = target->parent->parent->value < target->parent->value;

      if (direction == grandparentD) {
        // zig zig
        node *x, *y, *z, *a, *b, *c, *d;
        x = target;
        y = target->parent;
        z = target->parent->parent;
        a = target->child[direction];
        b = target->child[!direction];
        c = target->parent->child[!direction];
        d = target->parent->parent->child[!direction];

        if (z->parent) {
          z->parent->child[z->parent->value < z->value] = x;
        }
        x->parent = z->parent;

        x->child[!direction] = y;
        y->parent = x;

        y->child[direction] = b;
        b->parent = y;

        y->child[!direction] = z;
        z->parent = y;

        z->child[direction] = c;
        c->parent = z;
      } else {
        // zig zig
        node *x, *y, *z, *a, *b, *c, *d;
        x = target;
        y = target->parent;
        z = target->parent->parent;
        a = target->parent->child[!direction];
        b = target->child[!direction];
        c = target->child[direction];
        d = target->parent->parent->child[direction];

        if (z->parent) {
          z->parent->child[z->parent->value < z->value] = x;
        }
        x->parent = z->parent;

        x->child[direction] = z;
        z->parent = x;

        x->child[!direction] = y;
        y->parent = x;

        y->child[direction] = b;
        b->parent = y;

        y->child[!direction] = a;
        a->parent = y;

        z->child[direction] = d;
        d->parent = z;

        z->child[!direction] = c;
        c->parent = x;
      }
    } else {
      // zig
      int direction = target->parent->value < value;
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
