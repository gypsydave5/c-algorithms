#include "gcdNaive.h"
#include <stdio.h>

unsigned long long gcdNaive(unsigned long long a, unsigned long long b) {
  unsigned long long c;

  if (a > b) {
    c = a;
  } else {
    c = b;
  }

  for (; c > 0; --c) {
    if ((a % c == 0) && (b % c == 0)) {
      break;
    }
  }

  return c;
}