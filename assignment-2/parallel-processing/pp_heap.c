#include "pp.h"

static void swap(thread *a, thread *b) {
  thread temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

static int t_less_than(thread *a, thread *b) {
  long double rank_a, rank_b;
  rank_a = (1.0 * a->finish_time) + (0.1 * a->index);
  rank_b = (1.0 * b->finish_time) + (0.1 * b->index);

  return rank_a < rank_b;
}

static long long left_child(long long index) { return index * 2; }
static long long right_child(long long index) { return index * 2 + 1; }
static void sift_down(thread array[], long long size, long long index) {
  long long max_index, left, right;
  thread *left_t, *right_t, *index_t;
  left = left_child(index);
  right = right_child(index);
  left_t = &array[left - 1];
  right_t = &array[right - 1];
  index_t = &array[index - 1];
  max_index = index;

  /*printf("starting sift down...\n");*/
  /*for (long long i = 0; i < size; i++) {*/
  /*printf("position: %lld, finish_time: %lld, index: %lld\n", i,*/
  /*array[i].finish_time, array[i].index);*/
  /*}*/
  /*printf("\n");*/

  if (right <= size && t_less_than(right_t, index_t)) {
    max_index = right;
  }

  if (left <= size && t_less_than(left_t, index_t)) {
    max_index = left;
  }

  if (left <= size && right <= size) {
    if (t_less_than(left_t, index_t) && t_less_than(left_t, right_t)) {
      max_index = left;
    }
    if (t_less_than(right_t, index_t) && t_less_than(right_t, left_t)) {
      max_index = right;
    }
  }

  if (index != max_index) {
    swap(&array[index - 1], &array[max_index - 1]);
    sift_down(array, size, max_index);
  }
}

void pp_heap(thread t[], long long t_count, long long jobs[], long long j_count,
             thread log[]) {
  long long i;
  for (i = 0; i < j_count; i++) {
    log[i].finish_time = t[0].finish_time;
    log[i].index = t[0].index;
    t[0].finish_time += jobs[i];
    sift_down(t, t_count, 1);
  }
}
