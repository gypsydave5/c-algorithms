#include <stdlib.h>
#include "pp.h"

static int t_less_than(thread *a, thread *b) {
  long double rank_a, rank_b;
  rank_a = (1.0 * a->finish_time) + (0.1 * a->index);
  rank_b = (1.0 * b->finish_time) + (0.1 * b->index);

  return rank_a < rank_b;
}

static int thread_comparison(const void *a, const void *b) {
  thread t_a = *(const thread *)a;
  thread t_b = *(const thread *)b;

  long double rank_a, rank_b;
  rank_a = (1.0 * t_a.finish_time) + (0.1 * t_a.index);
  rank_b = (1.0 * t_b.finish_time) + (0.1 * t_b.index);

  if (rank_a < rank_b) return -1;
  if (rank_b < rank_a) return 1;
  return 0;
}

void pp_sort(thread t[], long long t_count, long long jobs[], long long j_count,
             thread log[]) {
  long long i;
  for (i = 0; i < j_count; i++) {
    log[i].finish_time = t[0].finish_time;
    log[i].index = t[0].index;
    t[0].finish_time += jobs[i];
    qsort(t, t_count, sizeof(thread), thread_comparison);
  }
}
