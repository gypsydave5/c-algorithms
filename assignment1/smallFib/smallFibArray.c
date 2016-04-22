#include "smallFibArray.h"
#include <stdio.h>

long long smallFibArray(int f) {
  int i;
  int arrayLength;
  arrayLength = f + 1;
  long long fibs[arrayLength];

  fibs[0] = 0;
  fibs[1] = 1;
  for (i = 2; i < arrayLength; i++) {
    fibs[i] = fibs[i - 1] + fibs[i - 2];
  }
  return fibs[f];
}
