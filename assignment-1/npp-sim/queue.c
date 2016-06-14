#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void queue_init(queue *q) {
  q->head = NULL;
  q->tail = NULL;
  q->capacity = -1;
  q->size = 0;
}

void queue_init_capacity(queue *q, long long capacity) {
  q->head = NULL;
  q->tail = NULL;
  q->capacity = capacity;
  q->size = 0;
}

static void add_node_to_empty_queue(queue *empty_queue, node **n) {
  empty_queue->head = *n;
  empty_queue->tail = *n;
}

static void add_node_to_non_empty_queue(queue *q, node **n) {
  (*n)->next = q->tail;
  q->tail->prev = *n;
  q->tail = *n;
}

static void add_node_to_queue(queue *q, node **n) {
  if (q->head == NULL) {
    add_node_to_empty_queue(q, n);
  } else {
    add_node_to_non_empty_queue(q, n);
  }
}

static node *new_node_for_packet(packet *p) {
  node *n;
  n = malloc(sizeof(node));
  n->data = p;
  return n;
}

int queue_empty(queue *q) { return q->size == 0 ? 1 : 0; }

int queue_push(queue *q, packet *p) {
  if (q->size == q->capacity) {
    return 1;
  }
  q->size++;
  node *n;
  n = new_node_for_packet(p);
  add_node_to_queue(q, &n);
  return 0;
}

packet *queue_pop(queue *q) {
  packet *p;
  p = q->head->data;

  if (q->size > 1) {
    q->head = q->head->prev;
    free(q->head->next);
    q->head->next = NULL;
  } else {
    free(q->head);
    q->head = NULL;
    q->tail = NULL;
  }
  q->size--;
  return p;
}
