#include "naiveMaxPairwiseProduct.h"
#include <stdio.h>

int main() {
  int len, i;
  long long n, result;

  scanf("%d", &len);
  long long inputs[len];

  for (i = 0; i < len; i++) {
    scanf("%lld", &n);
    inputs[i] = n;
  }

  result = naiveMaxPairwiseProduct(len, inputs);
  printf("%lld\n", result);
}