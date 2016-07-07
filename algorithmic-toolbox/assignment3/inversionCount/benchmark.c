#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inversions.h"

unsigned long long benchmark(int (*f)(int array[], int len), int iterations) {
  long long startTime, endTime;
  startTime = (long long)clock();

  for (int i = 0; i < iterations; i++) {
    int len, j;
    len = (rand() % 10000) + 1;
    int array[len];

    for (j = 0; j < len; j++) {
      array[i] = (rand() % 100) + 1;
    }

    (*f)(array, len);
  }

  endTime = (unsigned long long)clock();
  return (endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
}

int main() {
  unsigned long long t1, t2;
  t1 = benchmark(merge_sort_inversion, 100);
  t2 = benchmark(merge_sort_inversion_better, 100);
  printf("Naive: %lld microseconds\n", t1);
  printf("Merge: %lld microseconds\n", t2);
}
