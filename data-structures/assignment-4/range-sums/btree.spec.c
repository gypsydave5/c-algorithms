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

  join(LEFT, &y, &x);

  assert(x->parent = y);
  assert(y->child[LEFT] = x);
}

void testJoinRight() {
  node *x, *y;
  x = malloc(sizeof(node));
  y = malloc(sizeof(node));

  x->value = 5;
  y->value = 4;

  join(RIGHT, &y, &x);

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

  join(RIGHT, &x, &a);
  join(LEFT, &x, &y);
  join(LEFT, &y, &z);

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
  assert(greater_and_equal->sum == 12);
  assert(greater_and_equal->parent == 0);
  assert(greater_and_equal->child[RIGHT]->value == 4);
  assert(greater_and_equal->child[RIGHT]->child[RIGHT]->value == 5);

  assert(root->value == 2);
  assert(root->sum == 3);
  assert(root->parent == 0);
  assert(root->child[LEFT]->value == 1);
}

void testMerge() {
  node *left_tree, *right_tree;
  left_tree = right_tree = 0;

  treeInsert(&left_tree, 1);
  treeInsert(&left_tree, 2);
  treeInsert(&left_tree, 3);
  treeInsert(&left_tree, 4);
  treeInsert(&left_tree, 5);

  treeInsert(&right_tree, 10);
  treeInsert(&right_tree, 9);
  treeInsert(&right_tree, 8);
  treeInsert(&right_tree, 7);
  treeInsert(&right_tree, 6);

  treeMerge(&left_tree, &right_tree);
  assert(left_tree->value == 5);
  assert(left_tree->sum == 55);
  assert(treeContains(&left_tree, 10));
  assert(treeContains(&left_tree, 6));
  assert(treeContains(&left_tree, 1));
}

void testMergeEmptyRight() {
  node *left_tree, *right_tree;
  left_tree = right_tree = 0;

  treeInsert(&left_tree, 1);
  treeInsert(&left_tree, 2);
  treeInsert(&left_tree, 3);
  treeInsert(&left_tree, 4);
  treeInsert(&left_tree, 5);

  treeMerge(&left_tree, &right_tree);
  assert(left_tree->value == 5);
  assert(left_tree->sum == 15);
}

void testMergeEmptyLeft() {
  node *left_tree, *right_tree;
  left_tree = right_tree = 0;

  treeInsert(&right_tree, 4);
  treeInsert(&right_tree, 5);
  treeInsert(&right_tree, 6);
  treeInsert(&right_tree, 7);
  treeInsert(&right_tree, 8);

  treeMerge(&left_tree, &right_tree);
  assert(left_tree->value == 8);
  assert(left_tree->sum == 30);
}

void testTotal() {
  node *root;
  root = 0;

  treeInsert(&root, 5);
  assert(root->sum == 5);

  treeInsert(&root, 10);
  assert(root->sum == 15);

  treeInsert(&root, 20);
  assert(root->sum == 35);

  treeInsert(&root, 2);
  assert(root->sum == 37);

  treeInsert(&root, 8);
  assert(root->sum == 45);

  treeInsert(&root, 11);
  assert(root->sum == 56);

  treeRemove(&root, 20);
  assert(root->sum == 36);

  treeRemove(&root, 12);
  assert(root->sum == 36);

  treeRemove(&root, 5);
  assert(root->sum == 31);
}

void testTreeSumRange() {
  int sum;
  node *root;
  root = 0;
  treeInsert(&root, 1);
  treeInsert(&root, 2);
  treeInsert(&root, 3);
  treeInsert(&root, 4);
  treeInsert(&root, 5);

  sum = treeSumRange(&root, 2, 4);
  assert(sum == 9);
  assert(root->value == 1);
  assert(root->sum == 15);
  assert(treeContains(&root, 5));
}

void testTreeSumRangeInexact() {
  int sum;
  node *root;
  root = 0;
  treeInsert(&root, 10);
  treeInsert(&root, 20);
  treeInsert(&root, 30);
  treeInsert(&root, 40);
  treeInsert(&root, 50);

  sum = treeSumRange(&root, 25, 45);
  assert(sum == 70);
  assert(root->value == 10);
  assert(root->sum == 150);
  assert(treeContains(&root, 50));

  sum = treeSumRange(&root, 55, 45);
  assert(sum == 0);

  sum = treeSumRange(&root, 30, 30);
  assert(sum == 30);
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
  testMergeEmptyLeft();
  testMergeEmptyRight();
  testTotal();
  testTreeSumRange();
  testTreeSumRangeInexact();
  printf("\t\x1b[32mBinary tree tests pass\x1b[0m\n");
}

