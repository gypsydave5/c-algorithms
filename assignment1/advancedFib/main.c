#include "fibModNaive.h"
#include "fibModPisano.h"
#include <stdio.h>

int main() {
  unsigned long long resultN, resultP, a, m;
  scanf("%lld %lld", &a, &m);

  resultN = fibModNaive(a, m);
  resultP = fibModPisano(a, m);
  printf("%lld\n", resultN);
  printf("%lld\n", resultP);
}
