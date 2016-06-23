#include <stdio.h>

typedef struct thread {
  unsigned long long finish_time;
  unsigned long long index;
} thread;

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

static unsigned long long left_child(unsigned long long index) {
  return index * 2;
}
static unsigned long long right_child(unsigned long long index) {
  return index * 2 + 1;
}
static void sift_down(thread array[], unsigned long long size,
                      unsigned long long index) {
  unsigned long long max_index, left, right;
  thread *left_t, *right_t, *index_t;
  left = left_child(index);
  right = right_child(index);
  left_t = &array[left - 1];
  right_t = &array[right - 1];
  index_t = &array[index - 1];
  max_index = index;

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

void pp_heap(thread t[], unsigned long long t_count, unsigned long long jobs[],
             unsigned long long j_count, thread log[]) {
  unsigned long long i;
  for (i = 0; i < j_count; i++) {
    log[i].finish_time = t[0].finish_time;
    log[i].index = t[0].index;
    t[0].finish_time += jobs[i];
    sift_down(t, t_count, 1);
  }
}

int main() {
  unsigned long long thread_count, job_count, i;
  scanf("%lld %lld\n", &thread_count, &job_count);

  unsigned long long jobs[job_count];
  thread log[job_count];
  for (i = 0; i < job_count; i++) {
    scanf("%lld\n", &jobs[i]);
  }

  thread threads[thread_count];
  for (i = 0; i < thread_count; i++) {
    threads[i].finish_time = 0;
    threads[i].index = i;
  }

  pp_heap(threads, thread_count, jobs, job_count, log);

  for (i = 0; i < job_count; i++) {
    printf("%lld %lld\n", log[i].index, log[i].finish_time);
  }
}
