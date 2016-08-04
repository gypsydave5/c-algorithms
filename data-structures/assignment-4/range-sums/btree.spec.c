#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

void testJoinLeft() {
  node *x, *y;
  x = malloc(sizeof(node));
  y = malloc(sizeof(node));

  x->value = 5;
  y->value = 6;

  joinLeft(&y, &x);

  assert(x->parent = y);
  assert(y->child[LEFT] = x);
}

void testJoinRight() {
  node *x, *y;
  x = malloc(sizeof(node));
  y = malloc(sizeof(node));

  x->value = 5;
  y->value = 4;

  joinRight(&y, &x);

  assert(x->parent = y);
  assert(y->child[RIGHT] = x);
}

int main() {
  testJoinLeft();
  testJoinRight();
  printf("\t\x1b[32mBinary tree tests pass\x1b[0m");
}
