#include "max_value.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long benchmark(int (*f)(int nums[], int len_nums, char ops[]),
                             int iterations) {

  long long startTime, endTime;
  startTime = (long long)clock();

  for (int i = 0; i < iterations; i++) {
    int len_nums, j;
    char op_set[3] = {'+', '-', '*'};

    len_nums = ((rand() % 6) + 1) * 2;
    int nums[len_nums];
    char ops[len_nums - 1];

    for (j = 0; j < len_nums; j++) {
      nums[j] = rand() % 10;
    }

    for (j = 0; j < (len_nums - 1); j++) {
      ops[j] = op_set[rand() % 3];
    }

    (*f)(nums, len_nums, ops);
  }

  endTime = (unsigned long long)clock();
  return (endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
}

int main() {
  unsigned long long t1, t2;
  t1 = benchmark(naive_max_value, 10);
  t2 = benchmark(dynamic_max_value, 10);
  printf("Naive : %lld microseconds\n", t1);
  printf("Dynamic: %lld microseconds\n", t2);
}
