#include "gcdEuclid.h"
#include "gcdNaive.h"
#include <stdio.h>

int main() {
  unsigned long long a, b, res;
  scanf("%lld %lld", &a, &b);

  res = gcdEuclid(a, b);

  printf("%lld\n", res);
}
