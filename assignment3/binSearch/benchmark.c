#include "defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long benchmark(void (*f)(int l[], int, int q[], int, int r[]),
                             int iterations) {

  long long startTime, endTime;
  startTime = (long long)clock();

  for (int i = 0; i < iterations; i++) {
    int j, l;
    l = (rand() % 1000) + 1;
    int array[l], q[l], r[l];

    for (j = 0; j < l; j++) {
      array[j] = (rand() % 1000);
      q[j] = (rand() % 1000);
    }

    (*f)(array, l, q, l, r);
  }

  endTime = (unsigned long long)clock();
  return (endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
}

int main() {
  unsigned long long t1, t2, t3;
  t1 = benchmark(naiveSearch, 100000);
  t2 = benchmark(binarySearchList, 100000);
  t3 = benchmark(binarySearchListIterative, 100000);
  printf("Naive : %lld microseconds\n", t1);
  printf("Recursive: %lld microseconds\n", t2);
  printf("Iterative: %lld microseconds\n", t3);
}
