#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void queue_init(queue *q) {
  q->head = NULL;
  q->tail = NULL;
  q->capacity = 0;
  q->size = -1;
}

void queue_init_capacity(queue *q, int capacity) {
  q->head = NULL;
  q->tail = NULL;
  q->capacity = capacity;
  q->size = 0;
}

int queue_push(queue *q, packet *p) {
  if (q->size == q->capacity) {
    return 1;
  }
  if (q->capacity) {
    q->size++;
  }
  node *n;
  n = malloc(sizeof(node));
  n->data = p;
  if (q->head == NULL) {
    q->head = n;
    q->tail = n;
    return 0;
  }
  n->next = q->tail;
  q->tail->prev = n;
  q->tail = n;
  return 0;
}

packet *queue_pop(queue *q) {
  packet *p;
  p = q->head->data;

  q->head = q->head->prev;
  free(q->head->next);
  q->head->next = NULL;
  if (q->capacity) {
    q->size--;
  }
  return p;
}
