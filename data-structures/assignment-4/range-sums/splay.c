#include "btree.h"
#include "splay.h"

void splay(node **root, int value) {
  if (!*root) {
    return;
  }
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
        if (y) {
          y->parent = x;
        }

        y->child[direction] = b;
        if (b) {
          b->parent = y;
        }

        y->child[!direction] = z;
        if (z) {
          z->parent = y;
        }

        z->child[direction] = c;
        if (c) {
          c->parent = z;
        }
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
        if (z) {
          z->parent = x;
        }

        x->child[!direction] = y;
        if (y) {
          y->parent = x;
        }

        y->child[direction] = b;
        if (b) {
          b->parent = y;
        }

        y->child[!direction] = a;
        if (a) {
          a->parent = y;
        }

        z->child[direction] = d;
        if (d) {
          d->parent = z;
        }

        z->child[!direction] = c;
        if (c) {
          c->parent = x;
        }
      }
    } else {
      // zig
      int direction = target->parent->value < target->value;
      temp = target->child[!direction];

      target->child[!direction] = target->parent;
      target->child[!direction]->parent = target;
      target->parent = 0;

      target->child[!direction]->child[direction] = temp;
      if (temp) {
        temp->parent = target->child[!direction];
      }
    }
  }
  *root = target;
}