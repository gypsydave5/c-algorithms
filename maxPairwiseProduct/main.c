#include <stdio.h>

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

int main() {
  int len, i, n;
  long long result;

  scanf("%d", &len);
  int inputs[len];

  for (i = 0; i < len; i++) {
    scanf("%d", &n);
    inputs[i] = n;
  }

  result = fastMaxPairwiseProduct(len, inputs);
  printf("%lld\n", result);
}