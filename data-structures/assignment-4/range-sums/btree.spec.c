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
  assert(x->child[LEFT] == 0);
  assert(x->child[RIGHT] == 0);
  assert(x->parent == 0);
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

void testInsertOne() {
  node *root;
  root = 0;
  insert(&root, 99);
  assert(root->value == 99);
}

void testInsertTwo() {
  node *root;
  root = 0;
  insert(&root, 12);
  assert(root->value == 12);

  insert(&root, 18);
  assert(root->value == 18);
  assert(root->child[LEFT]->value == 12);
}

void testInsertThree() {
  node *root;
  root = 0;
  insert(&root, 12);
  assert(root->value == 12);

  insert(&root, 18);
  assert(root->value == 18);
  assert(root->child[LEFT]->value == 12);

  insert(&root, 10);
  assert(root->value == 10);
  assert(root->child[RIGHT]->value == 12);
  assert(root->child[RIGHT]->child[RIGHT] != 0);
}

void testContains() {
  node *root;
  root = 0;
  insert(&root, 12);
  assert(root->value == 12);
  insert(&root, 18);
  assert(root->value == 18);
  assert(root->child[LEFT]->value == 12);
  insert(&root, 10);
  assert(root->value == 10);
  assert(root->child[RIGHT]->value == 12);
  assert(root->child[RIGHT]->child[RIGHT] != 0);

  insert(&root, 50);
  assert(root->child[RIGHT] == 0);
  assert(root->value == 50);
  assert(root->child[LEFT]->value == 18);
  assert(root->child[LEFT]->child[LEFT]->value == 12);
  assert(root->child[LEFT]->child[LEFT]->child[LEFT]->value == 10);

  insert(&root, 5);
  assert(root->value == 5);
  assert(root->child[LEFT] == 0);
  assert(root->child[RIGHT]->value == 10);
  assert(root->child[RIGHT]->child[RIGHT]->value == 50);
  assert(root->child[RIGHT]->child[RIGHT]->child[LEFT]->value == 12);
  assert(root->child[RIGHT]->child[RIGHT]->child[LEFT]->child[RIGHT]->value ==
         18);

  insert(&root, 20);
  assert(root->value == 20);
  assert(root->child[LEFT]->value == 18);
  assert(root->child[RIGHT]->value == 50);

  assert(contains(&root, 10));
  assert(root->value == 10);
  assert(!contains(&root, 59));
  assert(root->value == 50);
}

void testRemove() {
  node *root;
  root = 0;
  insert(&root, 12);
  insert(&root, 20);
  insert(&root, 70);
  insert(&root, 15);

  treeRemove(&root, 70);
  assert(root->value == 20);
  assert(root->child[LEFT]->value == 15);
  assert(root->child[RIGHT] == 0);
  assert(!contains(&root, 70));
  assert(contains(&root, 12));
  assert(contains(&root, 20));
  assert(contains(&root, 15));
}

int main() {
  testJoinLeft();
  testJoinRight();
  testInit();
  testFind();
  testInsertOne();
  testInsertTwo();
  testInsertThree();
  testContains();
  printf("\t\x1b[32mBinary tree tests pass\x1b[0m\n");
}

