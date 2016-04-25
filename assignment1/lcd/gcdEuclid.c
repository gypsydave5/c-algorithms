#include "gcdEuclid.h"
#include <stdio.h>

unsigned long long gcdEuclid(unsigned long long a, unsigned long long b) {
  if (b == 0) {
    return a;
  }
  a = a % b;
  return gcdEuclid(b, a);
}
