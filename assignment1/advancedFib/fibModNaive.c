#include "fibModNaive.h"
#include <stdio.h>

unsigned long long fibModNaive(unsigned long long x, unsigned long long m) {
  unsigned int toggle, a, b;
  toggle = a = 0;
  b = 1;

  for (; x > 0; --x) {
    if (toggle == 0) {
      toggle = 1;
      b = (a + b) % m;
    } else {
      toggle = 0;
      a = (a + b) % m;
    }
  }

  if (toggle == 0) {
    return a;
  } else {
    return b;
  }
}
