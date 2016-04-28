#include "fibModPisano.h"
#include "pisano.h"
#include <stdio.h>
unsigned long long fibMod(unsigned long long x, unsigned long long m);

unsigned long long fibModPisano(unsigned long long n, unsigned long long m) {
  unsigned long long p, firstFib;
  p = pisano(m);
  firstFib = n % p;
  return fibMod(firstFib, m);
}

unsigned long long fibMod(unsigned long long x, unsigned long long m) {
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
