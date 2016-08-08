#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "splay.h"

void testSplayZig() {
  node *root, *x, *a, *b, *c;
  root = malloc(sizeof(node));
  x = malloc(sizeof(node));
  a = malloc(sizeof(node));
  b = malloc(sizeof(node));
  c = malloc(sizeof(node));

  init(&root, 10);
  init(&x, 5);
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
  assert(root->parent == 0);

  assert(root->child[LEFT]->value == 1);
  assert(root->child[LEFT]->parent == root);

  assert(root->child[RIGHT]->value == 10);
  assert(root->child[RIGHT]->parent == root);

  assert(root->child[RIGHT]->child[LEFT]->value == 7);
  assert(root->child[RIGHT]->child[LEFT]->parent == root->child[RIGHT]);

  assert(root->child[RIGHT]->child[RIGHT]->value == 15);
  assert(root->child[RIGHT]->child[RIGHT]->parent == root->child[RIGHT]);

  // ... and then the other
  splay(&root, 10);
  assert(root->value == 10);
  assert(root->parent == 0);

  assert(root->child[LEFT]->value == 5);
  assert(root->child[LEFT]->parent == root);

  assert(root->child[RIGHT]->value == 15);
  assert(root->child[RIGHT]->parent == root);

  assert(root->child[LEFT]->child[LEFT]->value == 1);
  assert(root->child[LEFT]->child[LEFT]->parent == root->child[LEFT]);

  assert(root->child[LEFT]->child[RIGHT]->value == 7);
  assert(root->child[LEFT]->child[RIGHT]->parent == root->child[LEFT]);
}

void testSplayZigZig() {
  node *root, *x, *y, *a, *b, *c, *d;
  root = malloc(sizeof(node));
  x = malloc(sizeof(node));
  y = malloc(sizeof(node));
  a = malloc(sizeof(node));
  b = malloc(sizeof(node));
  c = malloc(sizeof(node));
  d = malloc(sizeof(node));

  init(&root, 50);
  init(&x, 30);
  init(&y, 40);
  init(&a, 25);
  init(&b, 35);
  init(&c, 45);
  init(&d, 55);

  joinLeft(&root, &y);
  joinRight(&root, &d);
  joinLeft(&y, &x);
  joinRight(&y, &c);
  joinLeft(&x, &a);
  joinRight(&x, &b);

  // test one way...
  splay(&root, 30);
  assert(root->value == 30);
  assert(root->parent == 0);

  assert(root->child[LEFT]->value == 25);
  assert(root->child[LEFT]->parent == root);

  assert(root->child[RIGHT]->value == 40);
  assert(root->child[RIGHT]->parent == root);

  assert(root->child[RIGHT]->child[LEFT]->value == 35);
  assert(root->child[RIGHT]->child[LEFT]->parent == root->child[RIGHT]);

  assert(root->child[RIGHT]->child[RIGHT]->value == 50);
  assert(root->child[RIGHT]->child[RIGHT]->parent == root->child[RIGHT]);

  assert(root->child[RIGHT]->child[RIGHT]->child[RIGHT]->value == 55);
  assert(root->child[RIGHT]->child[RIGHT]->child[RIGHT]->parent ==
         root->child[RIGHT]->child[RIGHT]);

  assert(root->child[RIGHT]->child[RIGHT]->child[LEFT]->value == 45);
  assert(root->child[RIGHT]->child[RIGHT]->child[LEFT]->parent ==
         root->child[RIGHT]->child[RIGHT]);

  // ... test the other way
  splay(&root, 50);
  assert(root->value == 50);
  assert(root->parent == 0);

  assert(root->child[LEFT]->value == 40);
  assert(root->child[LEFT]->parent == root);

  assert(root->child[RIGHT]->value == 55);
  assert(root->child[RIGHT]->parent == root);

  assert(root->child[LEFT]->child[LEFT]->value == 30);
  assert(root->child[LEFT]->child[LEFT]->parent == root->child[LEFT]);

  assert(root->child[LEFT]->child[RIGHT]->value == 45);
  assert(root->child[LEFT]->child[RIGHT]->parent == root->child[LEFT]);

  assert(root->child[LEFT]->child[LEFT]->child[LEFT]->value == 25);
  assert(root->child[LEFT]->child[LEFT]->child[LEFT]->parent ==
         root->child[LEFT]->child[LEFT]);

  assert(root->child[LEFT]->child[LEFT]->child[RIGHT]->value == 35);
  assert(root->child[LEFT]->child[LEFT]->child[RIGHT]->parent ==
         root->child[LEFT]->child[LEFT]);
}

void testSplayZigZag(){
  node *root, *x, *y, *a, *b, *c, *d;
  root = malloc(sizeof(node));
  x = malloc(sizeof(node));
  y = malloc(sizeof(node));
  a = malloc(sizeof(node));
  b = malloc(sizeof(node));
  c = malloc(sizeof(node));
  d = malloc(sizeof(node));

  init(&root, 50);
  init(&x, 45);
  init(&y, 40);
  init(&a, 30);
  init(&b, 42);
  init(&c, 47);
  init(&d, 55);

  joinLeft(&root, &y);
  joinRight(&root, &d);
  joinLeft(&y, &a);
  joinRight(&y, &x);
  joinLeft(&x, &b);
  joinRight(&x, &c);

  splay(&root, 45);
  assert(root->value == 45);
  assert(root->parent == 0);
  assert(root->child[LEFT]->value == 40);
  assert(root->child[RIGHT]->value == 50);
  assert(root->child[LEFT]->child[LEFT]->value == 30);
  assert(root->child[LEFT]->child[RIGHT]->value == 42);
  assert(root->child[RIGHT]->child[LEFT]->value == 47);
  assert(root->child[RIGHT]->child[RIGHT]->value == 55);
}

int main() {
  testSplayZig();
  testSplayZigZig();
  testSplayZigZag();
  printf("\t\x1b[32mSplay tests pass\x1b[0m\n");
}

