#include "lcmNaive.h"
unsigned long long lcmNaive(unsigned long long a, unsigned long long b) {
  unsigned long long lcm;

  if (a > b) {
    lcm = a;
  } else {
    lcm = b;
  }

  while (1) {
    if (((lcm % a) == 0) && ((lcm % b) == 0)) {
      break;
    } else {
      lcm++;
    }
  }

  return lcm;
}