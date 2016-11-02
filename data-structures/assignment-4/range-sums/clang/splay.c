#include "splay.h"
#include "btree.h"

void splay(node **root, unsigned long long value) {
  if (!*root) {
    return;
  }
  node *target, *temp;
  target = find(*root, value);

  while (target->parent) {
    if (target->parent->parent) {
      // zig zig or zig zag
      unsigned long long direction, grandparentD;
      direction = target->parent->value < target->value;
      grandparentD = target->parent->parent->value < target->parent->value;
      node *x, *y, *z, *a, *b, *c, *d;

      if (direction == grandparentD) {
        // zig zig
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

        join(!direction, &x, &y);
        join(direction, &y, &b);
        join(!direction, &y, &z);
        join(direction, &z, &c);
      } else {
        // zig zag
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

        join(direction, &x, &z);
        join(!direction, &x, &y);
        join(direction, &y, &b);
        join(!direction, &y, &a);
        join(direction, &z, &d);
        join(!direction, &z, &c);
      }

      treeCalcSum(&z);
      treeCalcSum(&y);
      treeCalcSum(&x);
    } else {
      // zig
      unsigned long long direction = target->parent->value < target->value;
      temp = target->child[!direction];

      join(!direction, &target, &target->parent);
      target->parent = 0;

      join(direction, &target->child[!direction], &temp);
      treeCalcSum(&target->child[!direction]);
      treeCalcSum(&target);
    }
  }
  *root = target;
}
