#include <stdio.h>
#include <stdlib.h>

typedef struct packet {
  long long id;
  long long t_process;
  long long t_received;
  long long t_start;
  long long t_finish;
} packet;

typedef struct node {
  packet *data;
  struct node *next;
  struct node *prev;
} node;

typedef struct queue {
  node *head;
  node *tail;
  long long capacity;
  long long size;
} queue;

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
int main() {
  long long capacity, packet_count, i;
  scanf("%lld %lld\n", &capacity, &packet_count);
  packet packet_list[packet_count];

  queue process_queue;
  queue_init_capacity(&process_queue, capacity);

  for (i = 0; i < packet_count; i++) {
    packet *p;
    p = &packet_list[i];
    scanf("%lld %lld\n", &p->t_received, &p->t_process);
  }

  for (i = 0; i < packet_count; i++) {
    int err;
    packet *p;
    p = &packet_list[i];

    if (!queue_empty(&process_queue)) {
      while (!queue_empty(&process_queue) &&
             (p->t_received >= process_queue.head->data->t_finish)) {
        packet *pp;
        pp = queue_pop(&process_queue);
      }
    }

    if (queue_empty(&process_queue)) {
      p->t_start = p->t_received;
      p->t_finish = p->t_received + p->t_process;
    } else {
      p->t_start = process_queue.tail->data->t_finish;
      p->t_finish = p->t_start + p->t_process;
    }

    err = queue_push(&process_queue, p);
    if (err) {
      p->t_start = -1;
    }
  }

  for (i = 0; i < packet_count; i++) {
    printf("%lld\n", packet_list[i].t_start);
  }
}
