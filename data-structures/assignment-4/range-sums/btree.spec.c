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

void testInit() {
  node *x;
  x = malloc(sizeof(node));

  init(&x, 5);

  assert(x->value == 5);
  assert(x->child[LEFT] == NULL);
  assert(x->child[RIGHT] == NULL);
  assert(x->parent == NULL);
  assert(x->sum == 5);
}

void testFind() {
  node *x, *y, *z, *a, *found;
  x = malloc(sizeof(node));
  y = malloc(sizeof(node));
  z = malloc(sizeof(node));
  a = malloc(sizeof(node));

  init(&x, 5);
  init(&y, 4);
  init(&z, 3);
  init(&a, 20);

  joinRight(&x, &a);
  joinLeft(&x, &y);
  joinLeft(&y, &z);

  found = find(x, 3);
  assert(found == z);

  found = find(x, 20);
  assert(found == a);

  found = find(x, 1);
  assert(found == z);

  found = find(x, 22);
  assert(found == a);

  found = find(x, 18);
  assert(found == a);
}

int main() {
  testJoinLeft();
  testJoinRight();
  testFind();
  printf("\t\x1b[32mBinary tree tests pass\x1b[0m");
}

