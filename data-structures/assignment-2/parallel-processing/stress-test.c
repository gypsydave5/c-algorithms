#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pp.h"

int main() {
  long long thread_count, job_count, i;
  srand(time(0));
  while (1) {
    thread_count = (rand() % 100000) + 1;
    job_count = (rand() % 100000) + 1;

    long long jobs[job_count];
    thread log_a[job_count];
    thread log_b[job_count];

    for (i = 0; i < job_count; i++) {
      jobs[i] = (rand() % 1000000000);
    }

    thread threads[thread_count];
    for (i = 0; i < thread_count; i++) {
      threads[i].finish_time = 0;
      threads[i].index = i;
    }

    pp_heap(threads, thread_count, jobs, job_count, log_a);
    pp_sort(threads, thread_count, jobs, job_count, log_b);

    for (i = 0; i < job_count; i++) {
      if (log_a[i].index != log_b[i].index &&
          log_b[i].finish_time != log_b[i].finish_time) {
        printf("FAIL!\n");
        printf("Jobs: ");
        for (i = 0; i < job_count; i++) {
          printf("%lld ", jobs[i]);
        }
        printf("\n");
        return 1;
      } else {
        printf("OK!\n");
      }
    }
  }
}
