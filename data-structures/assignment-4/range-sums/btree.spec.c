#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

void testBtreeNode() {
  node h;
  h.value = 0;
  h.height = 3;
  h.parent = NULL;
  h.child[LEFT] = NULL;
  h.child[RIGHT] = NULL;

  assert(h.value == 0);
  assert(h.height == 3);
}

void testNodeInit() {
  node h;
  node_init(&h);
  assert(h.value == -1);
  assert(h.height == -1);
  assert(h.parent == NULL);
  assert(h.child[LEFT] == NULL);
  assert(h.child[RIGHT] == NULL);
}

void testNodeCopy() {
  node source, target;
  node_init(&source);
  node_init(&target);

  source.value = 55;
  source.height = 77;
  source.parent = NULL;
  source.child[LEFT] = NULL;
  source.child[RIGHT] = NULL;
  node_copy(&source, &target);

  assert(target.value == source.value);
  assert(target.height == source.height);
  assert(target.parent == source.parent);
}

void testBtreeFind() {
  node *root, *lefty, *res;
  root = malloc(sizeof(node));
  lefty = malloc(sizeof(node));
  node_init(root);
  node_init(lefty);

  lefty->value = 55;
  root->value = 66;
  root->child[LEFT] = lefty;
  lefty->parent = root;

  res = find(root, 66);
  assert(res == root);
  res = find(root, 55);
  assert(res == lefty);
  res = find(root, 13);
  assert(res == lefty);

  free(root);
  free(lefty);
}

void testBtreeFindEmpty() {
  node *root, *res;
  root = malloc(sizeof(node));
  res = find(root, 66);
  assert(res == NULL);
}

void testBtreeDestroy() {
  node *root, *lefty, *righty;
  root = malloc(sizeof(node));
  lefty = malloc(sizeof(node));
  righty = malloc(sizeof(node));

  node_init(root);
  node_init(lefty);
  node_init(righty);

  lefty->value = 55;
  root->value = 66;
  righty->value = 77;

  root->child[LEFT] = lefty;
  lefty->parent = root;
  root->child[RIGHT] = righty;
  righty->parent = root;

  btree_destroy(&root);

  assert(root == NULL);
}

void testBtreeInsert() {
  node *root;
  root = malloc(sizeof(*root));
  node_init(root);
  root->value = 66;

  insert(root, 44);
  insert(root, 33);
  insert(root, 55);
  insert(root, 88);

  assert(root->child[LEFT]->value == 44);
  assert(root->child[RIGHT]->value == 88);
  assert(root->child[LEFT]->child[LEFT]->value == 33);
  assert(root->child[LEFT]->child[RIGHT]->value == 55);

  assert(root->child[LEFT]->parent == root);
  assert(root->child[RIGHT]->parent == root);

  btree_destroy(&root);
}

void testBtreeNext() {
  node *root, *start, *n_next;
  root = malloc(sizeof(*root));
  node_init(root);

  insert(root, 66);
  insert(root, 33);
  insert(root, 55);
  insert(root, 88);
  insert(root, 77);
  insert(root, 99);

  start = find(root, 33);
  n_next = next(start);
  assert(n_next->value == 55);
  n_next = next(n_next);
  assert(n_next->value == 66);
  n_next = next(n_next);
  assert(n_next->value == 77);
  n_next = next(n_next);
  assert(n_next->value == 88);
  n_next = next(n_next);
  assert(n_next->value == 99);
  n_next = next(n_next);
  assert(n_next == NULL);

  btree_destroy(&root);
}

void testBtreeDelete() {
  node *root, *target;
  root = malloc(sizeof(*root));
  node_init(root);

  insert(root, 9);
  insert(root, 1);
  insert(root, 6);
  insert(root, 2);
  insert(root, 7);
  insert(root, 4);

  target = find(root, 1);
  delete_node(&root, target);

  target = find(root, 1);
  assert(target->value == 2);

  target = find(root, 9);
  assert(target->child[LEFT]->value == 2);

  target = find(root, 6);
  assert(target->child[LEFT]->value == 4);

  btree_destroy(&root);
}

void testDeleteSomeMore() {
  node *root, *target;
  root = malloc(sizeof(*root));
  node_init(root);

  insert(root, 2);
  insert(root, 3);
  insert(root, 1);

  assert(root->value == 2);
  assert(root->child[LEFT]->value == 1);
  assert(root->child[RIGHT]->value == 3);

  target = find(root, 2);
  delete_node(&root, target);

  assert(root->value == 3);
}

void testBtreeParanoidDelete() {
  node *root, *target;
  root = malloc(sizeof(*root));
  node_init(root);

  insert(root, 9);
  insert(root, 1);
  insert(root, 6);
  insert(root, 2);
  insert(root, 7);
  insert(root, 4);

  target = find(root, 9);
  delete_node(&root, target);

  target = find(root, 9);
  assert(target == NULL);
  target = find(root, 1);
  assert(target);
  target = find(root, 6);
  assert(target);
  target = find(root, 2);
  assert(target);
  target = find(root, 7);
  assert(target);
  target = find(root, 4);
  assert(target);

  btree_destroy(&root);
}

void testEvenMoreParanoidDelete() {
  node *root, *target;
  root = malloc(sizeof(*root));
  node_init(root);

  insert(root, 9);
  insert(root, 20);
  insert(root, 8);
  insert(root, 21);
  insert(root, 18);

  target = find(root, 9);
  delete_node(&root, target);

  assert(root->value == 18);

  btree_destroy(&root);
}

void testRangeSum() {
  node *root;
  root = malloc(sizeof(*root));
  node_init(root);

  insert(root, 1);
  insert(root, 2);
  insert(root, 3);
  insert(root, 4);
  insert(root, 5);
  insert(root, 6);
  insert(root, 7);

  int x;
  x = btree_range_sum(&root, 3, 5);

  assert(x == (3 + 4 + 5));

  btree_destroy(&root);
}

void testRangeSumMissingStart() {
  node *root;
  root = malloc(sizeof(*root));
  node_init(root);

  insert(root, 10);
  insert(root, 20);
  insert(root, 30);
  insert(root, 40);
  insert(root, 50);
  insert(root, 60);
  insert(root, 70);

  int x;
  x = btree_range_sum(&root, 15, 50);

  assert(x == (20 + 30 + 40 + 50));

  btree_destroy(&root);
}

void testRangeSumMissingEnd() {
  node *root;
  root = malloc(sizeof(*root));
  node_init(root);

  insert(root, 10);
  insert(root, 20);
  insert(root, 30);
  insert(root, 40);
  insert(root, 50);
  insert(root, 60);
  insert(root, 70);

  int x;
  x = btree_range_sum(&root, 29, 49);

  assert(x == (30 + 40));

  btree_destroy(&root);
}

int main() {
  testBtreeNode();
  testNodeInit();
  testNodeCopy();
  testBtreeFind();
  testBtreeFindEmpty();
  testBtreeInsert();
  testBtreeNext();
  testBtreeDelete();
  testBtreeParanoidDelete();
  testEvenMoreParanoidDelete();
  testBtreeDestroy();
  testRangeSum();
  testRangeSumMissingStart();
  testRangeSumMissingEnd();
  printf("[1;32m\tBinary tree unit tests pass\n[0;m");
}
