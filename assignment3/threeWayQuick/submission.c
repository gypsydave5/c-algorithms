#include <stdio.h>
#include <stdlib.h>

static void swap(int *a, int *b) {
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

static void partition3(int a[], int l, int r, int *ml, int *mr) {
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

static void randomQS_three_way(int a[], int l, int r) {
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

int main() {
  int len;
  scanf("%d\n", &len);

  int array[len], i;
  for (i = 0; i < len; i++) {
    scanf("%d", &array[i]);
  }

  randomQS_three_way(array, 0, len - 1);

  for (i = 0; i < len - 1; i++) {
    printf("%d ", array[i]);
  }
  printf("%d\n", array[len - 1]);
}
