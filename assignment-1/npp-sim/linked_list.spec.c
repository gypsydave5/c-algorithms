#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "packet.h"
#include "queue.h"

void testListConstruction() {
  node *head;
  node *second;
  node *third;

  head = malloc(sizeof(node));
  second = malloc(sizeof(node));
  third = malloc(sizeof(node));

  packet one;
  packet two;
  packet three;

  one.id = 1;
  two.id = 2;
  three.id = 3;

  head->data = &one;
  head->next = second;
  head->prev = NULL;
  second->data = &two;
  second->next = third;
  second->prev = head;
  third->data = &three;
  third->next = NULL;
  third->prev = second;

  assert(head->data->id == 1);
  assert(head->next->data->id == 2);
  assert(head->next->next->data->id == 3);
  assert(third->prev->prev->data->id == 1);
}

void testQueuePush() {
  queue q;
  queue_init(&q);

  packet one;
  packet two;
  packet three;

  one.id = 1;
  two.id = 2;
  three.id = 3;

  int err;
  err = queue_push(&q, &one);
  assert(!err);
  err = queue_push(&q, &two);
  assert(!err);
  err = queue_push(&q, &three);
  assert(!err);

  assert(q.head->data->id == 1);
  assert(q.tail->data->id == 3);
  assert(q.tail->next->data->id == 2);
}

void testQueuePop() {
  queue q;
  queue_init(&q);

  packet one;
  packet two;
  packet three;

  one.id = 1;
  two.id = 2;
  three.id = 3;

  queue_push(&q, &one);
  queue_push(&q, &two);
  queue_push(&q, &three);

  packet *pop1;
  packet *pop2;
  pop1 = queue_pop(&q);
  pop2 = queue_pop(&q);

  assert(pop1->id == 1);
  assert(pop2->id == 2);
  assert(q.head->data->id == 3);
  assert(q.tail->data->id == 3);
}

void TestQueueCapacity() {
  queue q;
  int err;
  queue_init_capacity(&q, 2);

  packet one;
  packet two;
  packet three;

  one.id = 1;
  two.id = 2;
  three.id = 3;

  err = queue_push(&q, &one);
  assert(!err);

  err = queue_push(&q, &two);
  assert(!err);

  err = queue_push(&q, &three);
  assert(err == 1);

  queue_pop(&q);

  err = queue_push(&q, &three);
  assert(!err);
}

void TestQueueEmtpy() {
  queue q;
  queue_init_capacity(&q, 2);

  assert(queue_empty(&q));

  packet p;

  queue_push(&q, &p);
  assert(!queue_empty(&q));
  queue_pop(&q);
  assert(queue_empty(&q));
}

int main() {
  testListConstruction();
  testQueuePush();
  testQueuePop();
  TestQueueCapacity();
  TestQueueEmtpy();
  printf("All tests pass\n");
}
