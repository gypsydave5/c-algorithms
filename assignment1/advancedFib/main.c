#include "fibModNaive.h"
#include <stdio.h>

int main() {
  unsigned long long a;
  unsigned long long m;
  unsigned long long result;
  scanf("%lld %lld", &a, &m);

  result = fibModNaive(a, m);
  printf("%lld\n", result);
}
