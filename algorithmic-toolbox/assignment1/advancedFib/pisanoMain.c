#include "pisano.h"
#include <stdio.h>

int main() {
  unsigned long long m;
  unsigned long long result;
  scanf("%lld", &m);

  result = pisano(m);
  printf("%lld\n", result);
}
