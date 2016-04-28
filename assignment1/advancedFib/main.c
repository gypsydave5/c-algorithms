#include "fibModNaive.h"
#include "fibModPisano.h"
#include <stdio.h>

int main() {
  unsigned long long resultP, a, m;
  scanf("%lld %lld", &a, &m);

  resultP = fibModPisano(a, m);
  printf("%lld\n", resultP);
}
