#include "dumbLastDigit.h"
#include <stdio.h>

int dumbLastDigit(unsigned long long f) {
  unsigned long long i, arrayLength;
  arrayLength = f + 1;
  unsigned long long fibs[arrayLength];

  fibs[0] = 0;
  fibs[1] = 1;
  for (i = 2; i < arrayLength; i++) {
    fibs[i] = (fibs[i - 1] + fibs[i - 2]) % 10;
  }
  return fibs[f];
}
