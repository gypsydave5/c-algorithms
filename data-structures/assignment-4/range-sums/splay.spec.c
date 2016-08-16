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

  treeInit(&root, 10);
  treeInit(&x, 5);
  treeInit(&a, 1);
  treeInit(&b, 7);
  treeInit(&c, 15);

  join(LEFT, &root, &x);
  join(RIGHT, &root, &c);
  join(LEFT, &x, &a);
  join(RIGHT, &x, &b);

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

  treeInit(&root, 50);
  treeInit(&x, 30);
  treeInit(&y, 40);
  treeInit(&a, 25);
  treeInit(&b, 35);
  treeInit(&c, 45);
  treeInit(&d, 55);

  join(LEFT, &root, &y);
  join(RIGHT, &root, &d);
  join(LEFT, &y, &x);
  join(RIGHT, &y, &c);
  join(LEFT, &x, &a);
  join(RIGHT, &x, &b);

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

void testSplayZigZag() {
  node *root, *x, *y, *a, *b, *c, *d;
  root = malloc(sizeof(node));
  x = malloc(sizeof(node));
  y = malloc(sizeof(node));
  a = malloc(sizeof(node));
  b = malloc(sizeof(node));
  c = malloc(sizeof(node));
  d = malloc(sizeof(node));

  treeInit(&root, 50);
  treeInit(&x, 45);
  treeInit(&y, 40);
  treeInit(&a, 30);
  treeInit(&b, 42);
  treeInit(&c, 47);
  treeInit(&d, 55);

  join(LEFT, &root, &y);
  join(RIGHT, &root, &d);
  join(LEFT, &y, &a);
  join(RIGHT, &y, &x);
  join(LEFT, &x, &b);
  join(RIGHT, &x, &c);

  splay(&root, 45);
  assert(root->value == 45);
  assert(root->parent == 0);
  assert(root->child[LEFT]->value == 40);
  assert(root->child[RIGHT]->value == 50);
  assert(root->child[LEFT]->child[LEFT]->value == 30);
  assert(root->child[LEFT]->child[RIGHT]->value == 42);
  assert(root->child[RIGHT]->child[LEFT]->value == 47);
  assert(root->child[RIGHT]->child[RIGHT]->value == 55);

  splay(&root, 50);
  assert(root->value == 50);
  assert(root->parent == 0);
}

void testSplayOne() {
  node *root, *x, *y, *a, *b, *c, *d;
  root = malloc(sizeof(node));
  x = malloc(sizeof(node));
  y = malloc(sizeof(node));
  a = malloc(sizeof(node));
  b = malloc(sizeof(node));
  c = malloc(sizeof(node));
  d = malloc(sizeof(node));

  treeInit(&root, 50);
  treeInit(&x, 40);
  treeInit(&y, 30);
  treeInit(&a, 20);
  treeInit(&b, 10);
  treeInit(&c, 25);
  treeInit(&d, 35);

  join(LEFT, &root, &x);
  join(LEFT, &x, &y);
  join(LEFT, &y, &a);
  join(LEFT, &a, &b);
  join(RIGHT, &a, &c);
  join(RIGHT, &y, &d);

  splay(&root, 10);
  assert(root->value == 10);
  assert(root->parent == 0);

  splay(&root, 20);
  assert(root->value == 20);
  assert(root->parent == 0);

  splay(&root, 40);
  assert(root->value == 40);
  assert(root->parent == 0);

  splay(&root, 33);
  assert(root->value == 35);
  assert(root->parent == 0);

  splay(&root, 50);
  assert(root->value == 50);
  assert(root->parent == 0);
}

void testSplayNull() {
  node *nullRoot;
  nullRoot = 0;
  splay(&nullRoot, 10);
  assert(nullRoot == 0);
}

void testSplayLessThan() {
  node *root, *x, *a, *b, *c;
  root = malloc(sizeof(node));
  x = malloc(sizeof(node));
  a = malloc(sizeof(node));
  b = malloc(sizeof(node));
  c = malloc(sizeof(node));

  treeInit(&root, 10);
  treeInit(&x, 5);
  treeInit(&a, 1);
  treeInit(&b, 7);
  treeInit(&c, 15);

  join(LEFT, &root, &x);
  join(RIGHT, &root, &c);
  join(LEFT, &x, &a);
  join(RIGHT, &x, &b);

  splay(&root, 4);
  assert(root->value == 1);
  assert(root->parent == 0);
}

int main() {
  testSplayZig();
  testSplayZigZig();
  testSplayZigZag();
  testSplayOne();
  testSplayNull();
  testSplayLessThan();
  printf("\t\x1b[32mSplay tests pass\x1b[0m\n");
}

