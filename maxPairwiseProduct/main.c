#include "maxPairwiseProduct.h"
#include <stdio.h>

int main() {
  int len, result, n, i;

  scanf("%d", &len);
  int inputs[len];

  for (i = 0; i < len; i++) {
    scanf("%d", &n);
    inputs[i] = n;
  }
  result = MaxPairwiseProduct(len, inputs);
  printf("%d\n", result);
}