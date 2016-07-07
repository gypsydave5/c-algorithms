#include "sorting.h"
#include <stdlib.h>

int partition2(int a[], int l, int r) {
  int x = a[l];
  int j = l;

  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(&a[i], &a[j]);
    }
  }

  swap(&a[l], &a[j]);
  return j;
}

void randomQS(int a[], int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(&a[l], &a[k]);
  int m = partition2(a, l, r);

  randomQS(a, l, m - 1);
  randomQS(a, m + 1, r);
}