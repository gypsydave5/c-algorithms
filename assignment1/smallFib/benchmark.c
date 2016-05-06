#include "smallFibArray.h"
#include "smallFibRecursion.h"
#include <stdio.h>
#include <time.h>

long long benchmark(long long (*f)(int), int iterations) {
  long long startTime, endTime;
  startTime = (long long)clock();

  for (int i = 0; i < iterations; i++) {
    (*f)(i);
  }

  endTime = (long long)clock();
  return (endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
}

int main() {
  long long t1, t2;
  t1 = benchmark(smallFibRecursion, 40000);
  t2 = benchmark(smallFibArray, 40000);
  printf("RecursionTime: %lld microseconds\n", t1);
  printf("ArrayTime: %lld microseconds\n", t2);
}