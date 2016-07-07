#include "fibModNaive.h"
#include "fibModPisano.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long benchmark(unsigned long long (*f)(unsigned long long,
                                                     unsigned long long),
                             int iterations) {

  long long startTime, endTime;
  startTime = (long long)clock();

  for (int i = 0; i < iterations; i++) {
    (*f)((rand() % 5000) + 1, (rand() % 500) + 2);
  }

  endTime = (unsigned long long)clock();
  return (endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
}

int main() {
  unsigned long long t1, t2;
  t1 = benchmark(fibModNaive, 100000);
  t2 = benchmark(fibModPisano, 100000);
  printf("Naive : %lld microseconds\n", t1);
  printf("Pisano: %lld microseconds\n", t2);
}