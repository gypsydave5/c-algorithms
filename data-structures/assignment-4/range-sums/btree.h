#pragma once
#define LEFT 0
#define RIGHT 1
#define NUM_CHILDREN 2

typedef struct node {
  int value;
  int height;
  struct node *parent;
  struct node *child[NUM_CHILDREN];
} node;

void node_init(node *n);
void node_copy(node *source, node *destination);
void pre_order(node *n, void (*f)(int));
void inorder(node *n, void (*f)(int));
void post_order(node *n, void (*f)(int));
node* find(node *root, int target);
void insert(node *root, int value);
node* next(node *n);
void delete_node(node **root, node *target);
void btree_destroy(node **root);
