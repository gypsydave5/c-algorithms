#include "gcdEuclid.h"
#include "lcmEuclid.h"
#include <stdio.h>

unsigned long long lcmEuclid(unsigned long long a, unsigned long long b) {
  return (a * b) / gcdEuclid(a, b);
}
