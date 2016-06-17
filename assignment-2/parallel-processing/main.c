#include <stdio.h>

typedef struct thread {
  long long finish_time;
  long long index;
} thread;

void swap(thread *a, thread *b) {
  thread temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int t_less_than(thread *a, thread *b) {
  long double rank_a, rank_b;
  rank_a = (1.0 * a->finish_time) + (0.1 * a->index);
  rank_b = (1.0 * b->finish_time) + (0.1 * b->index);

  return rank_a < rank_b;
}

int left_child(int index) { return index * 2; }
int right_child(int index) { return index * 2 + 1; }
void sift_down(thread array[], long long size, long long index) {
  long long max_index, left, right;
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

int main() {
  long long thread_count, job_count, i;
  scanf("%lld %lld\n", &thread_count, &job_count);

  long long jobs[job_count];
  for (i = 0; i < job_count; i++) {
    scanf("%lld\n", &jobs[i]);
  }

  thread threads[thread_count];
  for (i = 0; i < thread_count; i++) {
    threads[i].finish_time = 0;
    threads[i].index = i;
  }

  for (i = 0; i < job_count; i++) {
    printf("%lld %lld\n", threads[0].index, threads[0].finish_time);
    threads[0].finish_time += jobs[i];
    sift_down(threads, thread_count, 1);
  }
}