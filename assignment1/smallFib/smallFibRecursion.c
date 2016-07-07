#include "smallFibRecursion.h"
#include <stdio.h>

long long fibStep(long long a, long long b, int i) {
  if (i == 0) {
    return a + b;
  }
  return fibStep(b, a + b, --i);
}

long long smallFibRecursion(int i) {
  if (i == 0) {
    return 0;
  }
  if (i == 1) {
    return 1;
  }
  return fibStep(0, 1, i - 2);
}