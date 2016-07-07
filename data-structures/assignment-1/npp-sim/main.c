#include <stdio.h>
#include "packet.h"
#include "queue.h"

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