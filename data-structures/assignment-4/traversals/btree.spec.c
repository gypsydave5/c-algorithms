#include <assert.h>
#include <stdio.h>
#include "btree.h"

void testBtreeNode() {
  node h;
  h.value = 0;
  h.height = 3;
  h.parent = NULL;
  h.left = NULL;
  h.right = NULL;

  assert(h.value == 0);
  assert(h.height == 3);
}

void testNodeInit() {
  node h;
  node_init(&h);
  assert(h.value == -1);
  assert(h.height == -1);
  assert(h.parent == NULL);
  assert(h.left == NULL);
  assert(h.left == NULL);
}

void testNodeCopy() {
  node source, target, *parent, *left, *right;
  node_init(&source);
  node_init(&target);
  source.value = 55;
  source.height = 77;
  source.parent = parent;
  source.left = left;
  source.right = right;
  node_copy(&source, &target);

  assert(target.value == source.value);
  assert(target.height == source.height);
  assert(target.parent == source.parent);
  assert(target.left == source.left);
  assert(target.right == source.right);
}

int main() {
  testBtreeNode();
  testNodeInit();
  testNodeCopy();
  printf("[1;32m\tBinary tree unit tests pass\n[0;m");
}
