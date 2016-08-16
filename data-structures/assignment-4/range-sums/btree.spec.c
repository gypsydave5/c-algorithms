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

  treeInit(&x, 5);

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

  treeInit(&x, 5);
  treeInit(&y, 4);
  treeInit(&z, 3);
  treeInit(&a, 20);

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
  treeInsert(&root, 99);
  assert(root->value == 99);
}

void testInsertTwo() {
  node *root;
  root = 0;
  treeInsert(&root, 12);
  assert(root->value == 12);

  treeInsert(&root, 18);
  assert(root->value == 18);
  assert(root->child[LEFT]->value == 12);
}

void testInsertThree() {
  node *root;
  root = 0;
  treeInsert(&root, 12);
  assert(root->value == 12);

  treeInsert(&root, 18);
  assert(root->value == 18);
  assert(root->child[LEFT]->value == 12);

  treeInsert(&root, 10);
  assert(root->value == 10);
  assert(root->child[RIGHT]->value == 12);
  assert(root->child[RIGHT]->child[RIGHT] != 0);
}

void testContains() {
  node *root;
  root = 0;
  treeInsert(&root, 12);
  assert(root->value == 12);
  treeInsert(&root, 18);
  assert(root->value == 18);
  assert(root->child[LEFT]->value == 12);
  treeInsert(&root, 10);
  assert(root->value == 10);
  assert(root->child[RIGHT]->value == 12);
  assert(root->child[RIGHT]->child[RIGHT] != 0);

  treeInsert(&root, 50);
  assert(root->child[RIGHT] == 0);
  assert(root->value == 50);
  assert(root->child[LEFT]->value == 18);
  assert(root->child[LEFT]->child[LEFT]->value == 12);
  assert(root->child[LEFT]->child[LEFT]->child[LEFT]->value == 10);

  treeInsert(&root, 5);
  assert(root->value == 5);
  assert(root->child[LEFT] == 0);
  assert(root->child[RIGHT]->value == 10);
  assert(root->child[RIGHT]->child[RIGHT]->value == 50);
  assert(root->child[RIGHT]->child[RIGHT]->child[LEFT]->value == 12);
  assert(root->child[RIGHT]->child[RIGHT]->child[LEFT]->child[RIGHT]->value ==
         18);

  treeInsert(&root, 20);
  assert(root->value == 20);
  assert(root->child[LEFT]->value == 18);
  assert(root->child[RIGHT]->value == 50);

  assert(treeContains(&root, 10));
  assert(root->value == 10);
  assert(!treeContains(&root, 59));
  assert(root->value == 50);
}

void testRemove() {
  node *root;
  root = 0;
  treeInsert(&root, 12);
  treeInsert(&root, 20);
  treeInsert(&root, 70);
  treeInsert(&root, 15);

  treeRemove(&root, 70);
  assert(root->value == 20);
  assert(root->child[LEFT]->value == 15);
  assert(root->child[RIGHT] == 0);
  assert(!treeContains(&root, 70));
  assert(treeContains(&root, 12));
  assert(treeContains(&root, 20));
  assert(treeContains(&root, 15));
}

void testSplit() {
  node *root, *greater_and_equal;
  root = 0;
  treeInsert(&root, 1);
  treeInsert(&root, 2);
  treeInsert(&root, 3);
  treeInsert(&root, 4);
  treeInsert(&root, 5);

  treeSplit(&root, &greater_and_equal, 3);
  assert(greater_and_equal->value == 3);
  assert(greater_and_equal->parent == 0);
  assert(greater_and_equal->child[RIGHT]->value == 4);
  assert(greater_and_equal->child[RIGHT]->child[RIGHT]->value == 5);

  assert(root->value == 2);
  assert(root->parent == 0);
  assert(root->child[LEFT]->value == 1);
}

void testMerge() {
  node *root_one, *root_two;
  root_one = root_two = 0;

  treeInsert(&root_one, 1);
  treeInsert(&root_one, 2);
  treeInsert(&root_one, 3);
  treeInsert(&root_one, 4);
  treeInsert(&root_one, 5);

  treeInsert(&root_two, 10);
  treeInsert(&root_two, 9);
  treeInsert(&root_two, 8);
  treeInsert(&root_two, 7);
  treeInsert(&root_two, 6);

  treeMerge(&root_one, &root_two);
  assert(root_one->value == 5);
  assert(treeContains(&root_one, 10));
  assert(treeContains(&root_one, 6));
  assert(treeContains(&root_one, 1));
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
  testRemove();
  testSplit();
  testMerge();
  printf("\t\x1b[32mBinary tree tests pass\x1b[0m\n");
}

