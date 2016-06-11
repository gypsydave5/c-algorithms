#pragma once
struct node;

typedef struct darray {
  long long capacity;
  long long top;
  struct node **array;
} darray;

typedef struct node {
  long long id;
  long long childCount;
  struct node *parent;
  struct darray children;
} node;

void darray_push(darray *da, node *n);
void darray_init(darray *da);
void darray_set(darray *da, long long index, node *n);
node *darray_get(darray *da, long long index);
void darray_grow(darray *da);
void darray_null_range(darray *da, long long start, long long stop);
node *darray_pop(darray *da);

void node_init(node *n);
void node_add_child(node *child, node *parent);
long long tree_depth_r(node *root);
long long tree_depth_i(node *root);
