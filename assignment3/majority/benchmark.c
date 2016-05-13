#include "divideMajority.h"
#include "mooreMajority.h"
#include "naiveMajority.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long benchmark(int (*f)(int list[], int size), int iterations) {

  long long startTime, endTime;
  startTime = (long long)clock();

  for (int i = 0; i < iterations; i++) {
    int size, j;
    size = (rand() % 1000) + 1;
    int array[size];

    for (j = 0; j < size; j++) {
      array[j] = (rand() % 1000);
    }

    (*f)(array, size);
  }

  endTime = (unsigned long long)clock();
  return (endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
}

int main() {
  unsigned long long t1, t2, t3;
  t1 = benchmark(naiveMajority, 1000);
  t2 = benchmark(divideMajority, 1000);
  t3 = benchmark(mooreMajority, 1000);
  printf("Naive : %lld microseconds\n", t1);
  printf("Divide&Conquer : %lld microseconds\n", t2);
  printf("Moore's Algorithm: %lld microseconds\n", t3);
}
