#include <stdio.h>

unsigned long long gcdBinary(unsigned long long a, unsigned long long b) {
  if (a == b) {
    return a;
  }
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }

  if (~a & 1) {
    if (~b & 1) {
      return gcdBinary(a >> 1, b >> 1) << 1;
    } else {
      return gcdBinary(a >> 1, b);
    }
  }
  if (~b & 1) {
    return gcdBinary(a, b >> 1);
  }
  if (a < b) {
    return gcdBinary((b - a) >> 1, a);
  } else {
    return gcdBinary((a - b) >> 1, b);
  }
}


