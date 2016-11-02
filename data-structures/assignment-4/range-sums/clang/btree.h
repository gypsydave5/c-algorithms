#pragma once
#define LEFT 0
#define RIGHT 1

typedef struct node {
  struct node *parent;
  struct node *child[2];
  unsigned long long value;
  unsigned long long sum;
} node;

void join(unsigned long long direction, node **parent, node **rightChild);
void update(node *n);
void treeDestroy(node **root);
void treeInit(node **n, unsigned long long value);
node *find(node *root, unsigned long long target);
void treeInsert(node **root, unsigned long long value);
unsigned long long treeContains(node **root, unsigned long long target);
void treeRemove(node **root, unsigned long long target);
void treeSplit(node **root, node **greater_or_equal, unsigned long long target);
void treeMerge(node **tree_one, node **tree_two);
void treeCalcSum(node **root);
unsigned long long treeSumRange(node **root, unsigned long long left_bound,
                                unsigned long long right_bound);
