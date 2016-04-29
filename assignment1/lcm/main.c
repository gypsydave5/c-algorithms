#include "lcmEuclid.h"
#include "lcmNaive.h"
#include <stdio.h>

int main() {
  unsigned long long a, b, result1, result2;

  scanf("%lld %lld", &a, &b);
  result1 = naiveLCM(a, b);
  result2 = lcmEuclid(a, b);
  printf("%lld\n", result1);
  printf("%lld\n", result2);
}
