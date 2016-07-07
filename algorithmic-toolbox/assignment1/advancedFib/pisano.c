#include "pisano.h"
int isZeroAndOne(unsigned long long a, unsigned long long b);

unsigned long long pisano(unsigned long long m) {
  unsigned long long current, last, swap, count;
  count = 0;
  last = 0;
  current = 1;

  if (m == 1) {
    return 1;
  }

  while (1) {
    swap = current;
    current = (current + last) % m;
    last = swap;
    count++;
    if (isZeroAndOne(last, current)) {
      break;
    }
  }

  return count;
}

int isZeroAndOne(unsigned long long a, unsigned long long b) {
  if ((a == 0) && (b == 1)) {
    return 1;
  } else {
    return 0;
  }
}
