#include "naiveMaxPairwiseProduct.h"

long long naiveMaxPairwiseProduct(int len, int numbers[]) {
  int i, j;
  long long max;
  max = -1;
  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      if (numbers[i] * numbers[j] > max) {
        max = numbers[i] * numbers[j];
      }
    }
  }
  return max;
}
