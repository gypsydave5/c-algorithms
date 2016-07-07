#include <stdio.h>
#include <stdlib.h>

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

void darray_init(darray *da) {
  da->capacity = 0;
  da->top = -1;
  da->array = NULL;
}

void node_init(node *n) {
  darray da;
  darray_init(&da);

  n->parent = NULL;
  n->id = -1;
  n->childCount = 0;
  n->children = da;
}

void darray_grow(darray *da) {
  if (da->capacity == 0) {
    da->capacity = 1;
    da->array = malloc(sizeof(node));
    return;
  }

  node **resized_array;
  long long i;
  resized_array = malloc(2 * (da->capacity) * sizeof(node));
  for (i = 0; i < da->capacity; i++) {
    resized_array[i] = da->array[i];
  }
  free(da->array);
  da->capacity = 2 * da->capacity;
  da->array = resized_array;
}

void darray_push(darray *da, node *n) {
  da->top++;
  if (da->capacity - 1 < da->top) {
    darray_grow(da);
  }
  da->array[da->top] = n;
}

void node_add_child(node *child, node *parent) {
  child->parent = parent;
  darray_push(&parent->children, child);
  parent->childCount++;
}

node *darray_get(darray *da, long long index) { return da->array[index]; }

long long tree_depth_i(node *root) {
  long long depth, i, j;
  darray current_level;
  darray_init(&current_level);
  darray_push(&current_level, root);
  depth = 0;

  while (current_level.top != -1) {
    darray next_level;
    darray_init(&next_level);

    for (i = 0; i <= current_level.top; i++) {
      node *current_node;
      current_node = darray_get(&current_level, i);

      if (current_node->childCount > 0) {
        for (j = 0; j < current_node->childCount; j++) {
          darray_push(&next_level, darray_get(&current_node->children, j));
        }
      }
    }

    depth++;
    current_level = next_level;
  }
  return depth;
}

int main() {
  long long nodeCount, i, depth;
  scanf("%lld\n", &nodeCount);
  node tree[nodeCount];
  node *root;

  for (i = 0; i < nodeCount; i++) {
    node_init(&tree[i]);
    tree[i].id = i;
  }

  for (i = 0; i < nodeCount; i++) {
    long long parentIndex;

    scanf("%lld", &parentIndex);
    if (parentIndex == -1) {
      root = &tree[i];
    } else {
      node_add_child(&tree[i], &tree[parentIndex]);
    }
  }

  depth = tree_depth_i(root);
  printf("%lld\n", depth);
}
