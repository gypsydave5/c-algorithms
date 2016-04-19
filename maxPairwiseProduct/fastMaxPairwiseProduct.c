#include "fastMaxPairwiseProduct.h"

long long fastMaxPairwiseProduct(int len, int numbers[]) {
  int i;
  long long max, nextmax;
  max = nextmax = -1;
  for (i = 0; i < len; i++) {
    if (numbers[i] >= max) {
      nextmax = max;
      max = numbers[i];
    } else if (numbers[i] >= nextmax) {
      nextmax = numbers[i];
    }
  }
  return max * nextmax;
}
