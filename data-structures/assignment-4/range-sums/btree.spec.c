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
  assert(res == NULL);

  free(root);
  free(lefty);
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
  free(root);
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
}

int main() {
  testBtreeNode();
  testNodeInit();
  testNodeCopy();
  testBtreeFind();
  testBtreeInsert();
  testBtreeNext();
  printf("[1;32m\tBinary tree unit tests pass\n[0;m");
}
