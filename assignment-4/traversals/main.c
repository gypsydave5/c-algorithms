#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "stack.h"

void print_int(int i) { printf("%d ", i); }

int main() {
  int node_count, i;
  scanf("%d\n", &node_count);

  node nodes[node_count];

  for (i = 0; i < node_count; i++) {
    int value, left, right;
    node_init(&nodes[i]);

    scanf("%d %d %d", &value, &left, &right);
    nodes[i].value = value;

    if (left != -1) {
      nodes[i].left = &nodes[left];
      nodes[left].parent = &nodes[i];
    }

    if (right != -1) {
      nodes[i].right = &nodes[right];
      nodes[right].parent = &nodes[i];
    }
  }

  inorder(&nodes[0], print_int);
  printf("\n");
  pre_order(&nodes[0], print_int);
  printf("\n");
  post_order(&nodes[0], print_int);
  printf("\n");
}
