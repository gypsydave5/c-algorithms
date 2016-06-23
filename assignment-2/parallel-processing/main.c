#include <stdio.h>
#include "pp.h"

int main() {
  long long thread_count, job_count, i;
  scanf("%lld %lld\n", &thread_count, &job_count);

  long long jobs[job_count];
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
  /*pp_sort(threads, thread_count, jobs, job_count, log);*/

  for (i = 0; i < job_count; i++) {
    printf("%lld %lld\n", log[i].index, log[i].finish_time);
  }
}