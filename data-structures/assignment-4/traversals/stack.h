#pragma once
#include "btree.h"

typedef struct elt {
  struct elt* next;
  node* node;
} elt;

void stack_push(elt** head, node* n);
node* stack_pop(elt** head);
node* stack_peek(elt* head);
elt* stack_init();
