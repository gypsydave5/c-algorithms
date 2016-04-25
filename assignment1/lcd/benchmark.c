#include "gcdEuclid.h"
#include "gcdNaive.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long benchmark(unsigned long long (*f)(unsigned long long,
                                                     unsigned long long),
                             int iterations) {

  long long startTime, endTime;
  startTime = (long long)clock();

  for (int i = 0; i < iterations; i++) {
    (*f)(rand() % 100000, rand() % 100000);
  }

  endTime = (unsigned long long)clock();
  return (endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
}

int main() {
  unsigned long long t1, t2;
  t1 = benchmark(gcdNaive, 100);
  t2 = benchmark(gcdEuclid, 100);
  printf("Naive: %lldmicroseconds\n", t1);
  printf("Euclid: %lldmicroseconds\n", t2);
}