#include <stdio.h>

int MaxPairwiseProduct(int len, int numbers[]) {
  int i, j, max;
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