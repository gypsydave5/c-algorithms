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