#pragma once

typedef struct node {
  int value;
  int height;
  struct node *parent;
  struct node *left;
  struct node *right;
} node;

void node_init(node *n);
void node_copy(node *source, node *destination);
void pre_order(node *n, void (*f)(int));
void inorder(node *n, void (*f)(int));
void post_order(node *n, void (*f)(int));