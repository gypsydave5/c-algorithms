#include <stdio.h>
#include "node.h"

int main() {
  long long nodeCount, i, depth;
  scanf("%lld\n", &nodeCount);
  node tree[nodeCount];
  node* root;

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