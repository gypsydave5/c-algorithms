#include "fastMaxPairwiseProduct.h"
#include "naiveMaxPairwiseProduct.h"
#include <stdio.h>

int main() {
  int len, i, n;
  long long result;

  scanf("%d", &len);
  int inputs[len];

  for (i = 0; i < len; i++) {
    scanf("%d", &n);
    inputs[i] = n;
  }

  result = naiveMaxPairwiseProduct(len, inputs);
  printf("%lld\n", result);
  result = fastMaxPairwiseProduct(len, inputs);
  printf("%lld\n", result);
}