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

  long double o_left, o_right, o_index;
  o_left = (1.0 * left_t->finish_time) + (0.1 * left_t->index);
  o_right = (1.0 * right_t->finish_time) + (0.1 * right_t->index);
  o_index = (1.0 * index_t->finish_time) + (0.1 * index_t->index);

  if (right <= size && o_right < o_index) {
    max_index = right;
  }

  if (left <= size && o_left < o_index) {
    max_index = left;
  }

  if (left <= size && right <= size) {
    if (o_left < o_right && o_left < o_index) {
      max_index = left;
    }
    if (o_right < o_left && o_right < o_index) {
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