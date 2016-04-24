#include "dumbLastDigit.h"
#include <stdio.h>

int dumbLastDigit(long long f) {
  long long i, arrayLength;
  arrayLength = f + 1;
  long long fibs[arrayLength];

  fibs[0] = 0;
  fibs[1] = 1;
  for (i = 2; i < arrayLength; i++) {
    fibs[i] = (fibs[i - 1] + fibs[i - 2]) % 10;
  }
  return fibs[f];
}
