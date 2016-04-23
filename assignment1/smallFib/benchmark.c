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
  t1 = benchmark(smallFibRecursion, 20000);
  t2 = benchmark(smallFibArray, 20000);
  printf("RecursionTime: %lldmicroseconds\n", t1);
  printf("ArrayTime: %lldmicroseconds\n", t1);
}