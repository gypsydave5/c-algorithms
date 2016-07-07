#include "pointsAndSegments.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long benchmark(void (*f)(struct segment segments[], int sCount,
                                       int points[], int pCount, int result[]),
                             int iterations) {

  long long startTime, endTime;
  startTime = (long long)clock();

  for (int i = 0; i < iterations; i++) {
    int j, sl, pl;
    sl = (rand() % 1000) + 1;
    pl = (rand() % 1000) + 1;
    struct segment s[sl];
    int p[pl], r[pl];

    for (j = 0; j < sl; j++) {
      int start = (rand() % 1000);
      int end = (rand() % 1000) + start;
      s[j].start = start;
      s[j].end = end;
    }

    for (j = 0; j < pl; j++) {
      p[j] = (rand() % 1000);
    }

    (*f)(s, sl, p, pl, r);
  }

  endTime = (unsigned long long)clock();
  return (endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
}

int main() {
  unsigned long long t1, t2;
  t1 = benchmark(naivePointsAndSegments, 1000);
  t2 = benchmark(sortedPointsAndSegments, 1000);
  printf("Naive : %lld microseconds\n", t1);
  printf("Sorted: %lld microseconds\n", t2);
}
