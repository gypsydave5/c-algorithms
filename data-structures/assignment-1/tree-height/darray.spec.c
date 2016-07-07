#include <assert.h>
#include <stdio.h>
#include "node.h"

void testDynamicArrayCanBePushedTo() {
  darray da;
  darray_init(&da);

  node n;
  n.id = 66;

  darray_push(&da, &n);
  assert(da.array[0]->id == 66);
  assert(da.top == 0);
  assert(da.capacity == 1);
}

void testDynamicArrayCanBeAccessed() {
  darray da;
  darray_init(&da);
  node n;
  n.id = 55;
  node* n_pointer;

  darray_push(&da, &n);
  n_pointer = darray_get(&da, 0);
  assert(n_pointer->id == 55);
}

void testDynamicArrayCanBeSet() {
  darray da;
  darray_init(&da);

  node n;
  n.id = 44;
  node* n_pointer;

  darray_set(&da, 5, &n);
  n_pointer = darray_get(&da, 5);
  assert(n_pointer->id == 44);

  n_pointer = darray_get(&da, 4);
  assert(n_pointer == NULL);
}

void testDynamicArrayPop() {
  darray da;
  darray_init(&da);
  node n, m;
  node *np_a, *np_b;
  node_init(&n);
  node_init(&m);
  n.id = 1;
  m.id = 2;

  darray_push(&da, &n);
  darray_push(&da, &m);
  assert(darray_get(&da, 0)->id == 1);
  assert(darray_get(&da, 1)->id == 2);
  assert(da.top == 1);

  np_a = darray_pop(&da);
  assert(np_a->id == 2);
  assert(da.top == 0);

  np_b = darray_pop(&da);
  assert(np_b->id == 1);
  assert(da.top == -1);
}

void testNodeAddChild() {
  node p, c;
  node_init(&p);
  node_init(&c);
  p.id = 22;
  c.id = 9;

  node_add_child(&c, &p);

  assert(c.parent->id == 22);
  assert(darray_get(&p.children, 0)->id == 9);
  assert(p.childCount == 1);
}

void testTreeDepth() {
  node root, c1, c2, c22;
  long long depth;
  node_init(&root);
  node_init(&c1);
  node_init(&c2);
  node_init(&c22);

  root.id = 0;
  c1.id = 1;
  c2.id = 2;
  c22.id = 22;

  node_add_child(&c1, &root);
  node_add_child(&c2, &root);
  node_add_child(&c22, &c2);

  depth = tree_depth_r(&root);
  assert(depth == 3);

  depth = tree_depth_i(&root);
  printf("dep_i: %lld\n", depth);
  assert(depth == 3);
}

int main() {
  testDynamicArrayCanBePushedTo();
  testDynamicArrayCanBeAccessed();
  testDynamicArrayCanBeSet();
  testDynamicArrayPop();
  testNodeAddChild();
  testTreeDepth();
  printf("All the tests passed.\n");
}
