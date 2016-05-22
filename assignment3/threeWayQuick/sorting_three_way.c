#include "sorting.h"
#include <stdlib.h>

void partition3(int a[], int l, int r, int *ml, int *mr) {
  int x = a[l];
  int n = r - l;
  *ml = *mr = l;

  while (*mr <= n) {
    if (a[*mr] < x) {
      swap(&a[*ml], &a[*mr]);
      *ml += 1;
      *mr += 1;
    } else if (a[*mr] > x) {
      swap(&a[*mr], &a[n]);
      n -= 1;
    } else {
      *mr += 1;
    }
  }
}

void randomQS_three_way(int a[], int l, int r) {
  if (l >= r) {
    return;
  }
  int ml, mr, k;

  k = l + rand() % (r - l + 1);
  swap(&a[l], &a[k]);
  partition3(a, l, r, &ml, &mr);

  randomQS_three_way(a, l, ml - 1);
  randomQS_three_way(a, mr + 1, r);
}
