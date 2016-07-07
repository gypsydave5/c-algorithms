#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "stack.h"

void testStackInit() {
  elt *head;
  head = stack_init();
  assert(head == NULL);
}

void testStackPush() {
  elt *head;
  head = stack_init();
  node n;
  n.value = 50;
  stack_push(&head, &n);
  assert(head->node->value == 50);
  assert(head->next == NULL);
}

void testStackPop() {
  elt *head;
  head = stack_init();
  node n;
  n.value = 17;
  stack_push(&head, &n);
  node *p;
  p = stack_pop(&head);
  assert(head == NULL);
  assert(p->value == 17);
}

void testStackPeek() {
  elt *head;
  head = stack_init();
  node n;
  n.value = 88;
  stack_push(&head, &n);
  node *p;
  p = stack_peek(head);
  assert(head->node->value == 88);
  assert(p->value == 88);
}

void testStackMultiplePush() {
  elt *head;
  head = stack_init();
  node n1;
  n1.value = 1;
  node n2;
  n2.value = 2;
  node n3;
  n3.value = 3;
  stack_push(&head, &n1);
  stack_push(&head, &n2);
  stack_push(&head, &n3);

  node *p;
  p = stack_pop(&head);
  assert(p->value == 3);
  p = stack_pop(&head);
  assert(p->value == 2);
  p = stack_pop(&head);
  assert(p->value == 1);
}

void testStackFun() {
  elt *head;
  head = stack_init();
  node n1;
  n1.value = 1;
  node n2;
  n2.value = 2;
  node n3;
  n3.value = 3;
  stack_push(&head, &n1);
  stack_push(&head, &n2);
  stack_push(&head, &n3);

  node *p;

  p = stack_pop(&head);
  assert(p->value == 3);
  p = stack_pop(&head);
  assert(p->value == 2);
  p = stack_pop(&head);
  assert(p->value == 1);
}

int main() {
  testStackInit();
  testStackPush();
  testStackPop();
  testStackPeek();
  testStackFun();
  printf("[1;32m\tStack tests all pass\n[0;m");
}
