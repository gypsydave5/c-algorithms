#include <stdio.h>

int isZeroAndOne(unsigned long long a, unsigned long long b);
unsigned long long pisano(unsigned long long m);
unsigned long long fibModPisano(unsigned long long n, unsigned long long m);
unsigned long long fibMod(unsigned long long x, unsigned long long m);

int main() {
  unsigned long long resultP, a, m;
  scanf("%lld %lld", &a, &m);

  resultP = fibModPisano(a, m);
  printf("%lld\n", resultP);
}

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
