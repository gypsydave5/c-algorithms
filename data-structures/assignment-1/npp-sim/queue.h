#pragma once
#include "linked_list.h"

typedef struct queue {
  node *head;
  node *tail;
  long long capacity;
  long long size;
} queue;

void queue_init(queue *q);
void queue_init_capacity(queue *q, long long capacity);
int queue_push(queue *q, packet *p);
packet *queue_pop(queue *q);
int queue_empty(queue *q);
