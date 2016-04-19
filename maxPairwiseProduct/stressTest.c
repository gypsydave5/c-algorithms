#include "fastMaxPairwiseProduct.h"
#include "naiveMaxPairwiseProduct.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  while (1) {
    int n = rand() % 20000 + 2;
    printf("%d\n", n);
    int a[n];

    for (int i = 0; i < n; i++) {
      a[i] = rand() % 20000;
    }
    for (int i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");

    long long res1 = fastMaxPairwiseProduct(n, a);
    long long res2 = naiveMaxPairwiseProduct(n, a);

    if (res1 != res2) {
      printf("Wrong answer! fast: %lld, naive: %lld\n", res1, res2);
      break;
    } else {
      printf("OK\n");
    }
  }
}
