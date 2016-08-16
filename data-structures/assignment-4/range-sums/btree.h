#pragma once
#define LEFT 0
#define RIGHT 1

typedef struct node {
  struct node *parent;
  struct node *child[2];
  int value;
  int sum;
} node;

void joinLeft(node **parent, node **leftChild);
void joinRight(node **parent, node **rightChild);
void init(node **n, int value);
node *find(node *root, int value);
void insert(node **root, int value);
int contains(node **root, int value);
