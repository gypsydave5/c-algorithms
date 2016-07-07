#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "stack.h"

elt *stack_init() { return NULL; }

void stack_destroy(elt **head) {
  elt *current, *next;
  current = *head;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}

void stack_push(elt **head, node *n) {
  elt *new_el;
  new_el = malloc(sizeof(elt));
  new_el->node = n;
  new_el->next = *head;
  *head = new_el;
}

node *stack_pop(elt **head) {
  node *n;
  n = (*head)->node;
  elt *new_head;
  new_head = (*head)->next;
  free(*head);
  *head = new_head;
  return n;
}

node *stack_peek(elt *head) { return head->node; }