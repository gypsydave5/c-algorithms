#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

static node *generateTree(unsigned long long inputs[], int length) {
  int i;
  node *root;
  root = 0;

  for (i = 0; i < length; i++) {
    treeInsert(&root, inputs[i]);
  }

  return root;
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

  treeDestroy(&x);
}

void testJoinLeft() {
  node *x, *y;
  x = malloc(sizeof(node));
  y = malloc(sizeof(node));

  treeInit(&x, 5);
  treeInit(&y, 6);

  join(LEFT, &y, &x);

  assert(x->parent = y);
  assert(y->child[LEFT] = x);

  treeDestroy(&x);
}

void testJoinRight() {
  node *x, *y;
  x = malloc(sizeof(node));
  y = malloc(sizeof(node));

  treeInit(&x, 5);
  treeInit(&y, 4);

  join(RIGHT, &y, &x);

  assert(x->parent = y);
  assert(y->child[RIGHT] = x);

  treeDestroy(&x);
}

void testTreeDestroy() {
  node *x, *y, *z, *a;
  x = malloc(sizeof(node));
  y = malloc(sizeof(node));
  z = malloc(sizeof(node));
  a = malloc(sizeof(node));

  treeInit(&x, 5);
  treeInit(&y, 4);
  treeInit(&z, 3);
  treeInit(&a, 2);

  join(RIGHT, &x, &a);
  join(LEFT, &x, &y);
  join(LEFT, &y, &z);

  treeDestroy(&x);

  assert(x == 0);
  // all the other pointers are freed, but dangling and cannot be nulled from
  // within the destroy function. Well, not without adding another layer of
  // indirection anyway...
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

  treeDestroy(&x);
}

void testInsertOne() {
  node *root;
  root = 0;
  treeInsert(&root, 99);
  assert(root->value == 99);

  treeDestroy(&root);
}

void testInsertTwo() {
  node *root;
  root = 0;
  treeInsert(&root, 12);
  assert(root->value == 12);

  treeInsert(&root, 18);
  assert(root->value == 18);
  assert(root->child[LEFT]->value == 12);

  treeDestroy(&root);
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

  treeDestroy(&root);
}

void testInsertNoDuplicates() {
  node *root;
  root = 0;
  treeInsert(&root, 12);
  assert(root->value == 12);
  assert(root->sum == 12);

  treeInsert(&root, 12);
  assert(root->sum == 12);
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

  treeDestroy(&root);
}

void testContainsEmpty() {
  node *root;
  root = 0;

  assert(!treeContains(&root, 10));
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

  treeDestroy(&root);
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

  treeDestroy(&root);
  treeDestroy(&greater_and_equal);
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
  assert(treeContains(&left_tree, 10));
  assert(treeContains(&left_tree, 6));
  assert(treeContains(&left_tree, 1));

  treeDestroy(&left_tree);
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

  treeDestroy(&left_tree);
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

  treeDestroy(&left_tree);
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
  assert(treeContains(&root, 5));

  treeDestroy(&root);
}

void testTreeSumRangeEmpty() {
  int sum;
  node *root;
  root = 0;

  sum = treeSumRange(&root, 2, 4);
  assert(sum == 0);
}

void testTreeSumRangeMax() {
  int sum;
  node *root;
  root = 0;

  treeInsert(&root, 1000000000);
  treeInsert(&root, 999999999);
  sum = treeSumRange(&root, 999999999, 1000000000);
  assert(sum == 1999999999);
}

void testTreeSumRangeInexact() {
  int sum;
  unsigned long long numbers[] = {10, 20, 30, 40, 50};
  node *root;
  root = generateTree(numbers, 5);

  sum = treeSumRange(&root, 25, 45);
  assert(sum == 70);
  assert(treeContains(&root, 50));

  sum = treeSumRange(&root, 0, 100);
  assert(sum == root->sum);

  treeDestroy(&root);
}

void testTreeSumRangeTooSmall() {
  int sum;
  unsigned long long numbers[] = {10, 20};
  node *root;
  root = generateTree(numbers, 2);

  sum = treeSumRange(&root, 12, 18);
  assert(sum == 0);
}

void testTreeSumRangeNoRange() {
  int sum;
  node *root;
  unsigned long long numbers[] = {55};
  root = generateTree(numbers, 1);

  sum = treeSumRange(&root, 55, 55);

  assert(sum == 55);
}

void testTreeSumRangeBoundsOver() {
  int sum;
  node *root;
  unsigned long long numbers[] = {55};
  root = generateTree(numbers, 1);

  sum = treeSumRange(&root, 744291401, 940449494);

  assert(sum == 0);
}

void testTreeSumRangeBoundsUnder() {
  int sum;
  node *root;
  unsigned long long numbers[] = {497631873};
  root = generateTree(numbers, 1);

  sum = treeSumRange(&root, 291401, 449494);

  assert(sum == 0);
}

void testEdgeCaseSum() {
  int sum;
  node *root;
  unsigned long long numbers[] = {300, 600, 400};
  root = generateTree(numbers, 3);

  sum = treeSumRange(&root, 350, 900);
  assert(sum == 1000);
}

int main() {
  testJoinLeft();
  testJoinRight();
  testTreeDestroy();
  testInit();
  testFind();
  testInsertOne();
  testInsertTwo();
  testInsertThree();
  testInsertNoDuplicates();
  testContains();
  testContainsEmpty();
  testRemove();
  testSplit();
  testMerge();
  testMergeEmptyLeft();
  testMergeEmptyRight();
  testTreeSumRange();
  testTreeSumRangeInexact();
  testTreeSumRangeEmpty();
  testTreeSumRangeMax();
  testTreeSumRangeTooSmall();
  testTreeSumRangeNoRange();
  testTreeSumRangeBoundsOver();
  testTreeSumRangeBoundsUnder();

  testEdgeCaseSum();
  printf("\t\x1b[32mBinary tree tests pass\x1b[0m\n");
}
