#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

// partition3 performs a Dutch National Flag sort against array of integres a[],
// starting at index l and ending at index r. It mutates the integers pointed to
// by *ml and *mr to give the index of the start of the middle portion (ml) and
// the start of the end portion (mr);
void partition3(int a[], int l, int r, int *ml, int *mr) {
  int x = a[l];
  int n = r;
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
  *mr -= 1;
}

// randoomQS_three_way sorts an array of integers a, starting at index l and
// ending at index r. It does so recursively, relying on the partition3
// algorithm above to do the correct positioning of identical integers
void randomQS_three_way(int a[], int l, int r) {
  if (l >= r) {
    return;
  }
  int ml, mr, k;

  k = l + rand() % (r - l + 1);
  swap(&a[l], &a[k]);
  partition3(a, l, r, &ml, &mr);

  randomQS_three_way(a, l, ml);
  randomQS_three_way(a, mr + 1, r);
}
