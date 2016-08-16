#pragma once
#define LEFT 0
#define RIGHT 1

typedef struct node {
  struct node *parent;
  struct node *child[2];
  int value;
  int sum;
} node;

void join(int direction, node **parent, node **rightChild);
void treeInit(node **n, int value);
node *find(node *root, int target);
void treeInsert(node **root, int value);
int treeContains(node **root, int target);
void treeRemove(node **root, int target);
void treeSplit(node **root, node **greater_or_equal, int target);
void treeMerge(node **tree_one, node **tree_two);
void treeCalcSum(node **root);
