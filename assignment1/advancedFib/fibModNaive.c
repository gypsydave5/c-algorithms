#include "fibModNaive.h"
#include <stdio.h>

unsigned long long fibModNaive(unsigned long long n, unsigned long long m) {
  int i;
  int arrayLength;
  arrayLength = n + 1;
  unsigned long long fibs[arrayLength];

  fibs[0] = 0;
  fibs[1] = 1;
  for (i = 2; i < arrayLength; i++) {
    fibs[i] = fibs[i - 1] + fibs[i - 2];
  }
  return fibs[n] % m;
}
