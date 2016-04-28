#include "lcmNaive.h"
#include <stdio.h>

int main() {
  unsigned long long a, b, result;

  scanf("%lld %lld", &a, &b);
  result = naiveLCM(a, b);
  printf("%lld\n", result);
}
