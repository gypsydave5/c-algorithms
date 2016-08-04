#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "splay.h"

void testSplayZig() {
  node *x, *root, *a, *b, *c;
  x = malloc(sizeof(node));
  root = malloc(sizeof(node));
  a = malloc(sizeof(node));
  b = malloc(sizeof(node));
  c = malloc(sizeof(node));

  init(&x, 5);
  init(&root, 10);
  init(&a, 1);
  init(&b, 7);
  init(&c, 15);

  joinLeft(&root, &x);
  joinRight(&root, &c);
  joinLeft(&x, &a);
  joinRight(&x, &b);

  // splay one way...
  splay(&root, 5);
  assert(root->value == 5);
  assert(root->child[LEFT]->value == 1);
  assert(root->child[RIGHT]->value == 10);
  assert(root->child[RIGHT]->child[LEFT]->value == 7);
  assert(root->child[RIGHT]->child[RIGHT]->value == 15);

  // ... and then the other
  splay(&root, 10);
  assert(root->value == 10);
  assert(root->child[LEFT]->value == 5);
  assert(root->child[RIGHT]->value == 15);
  assert(root->child[LEFT]->child[LEFT]->value == 1);
  assert(root->child[LEFT]->child[RIGHT]->value == 7);
}

int main() {
  testSplayZig();
  printf("\t\x1b[32mSplay tests pass\x1b[0m\n");
}


