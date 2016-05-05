#include <stdio.h>
#include <stdlib.h>

int compareInts(const void *a, const void *b) {
  const int *ia = (const int *)a;
  const int *ib = (const int *)b;
  return *ia - *ib;
}

int reverseInts(const void *a, const void *b) {
  const int *ia = (const int *)a;
  const int *ib = (const int *)b;
  return *ib - *ia;
}

int main() {
  int n, result, i;
  result = 0;

  scanf("%d\n", &n);
  int listOne[n], listTwo[n];

  for (i = 0; i < n; i++) {
    scanf("%d", &listOne[i]);
  }

  for (i = 0; i < n; i++) {
    scanf("%d", &listTwo[i]);
  }

  qsort(listOne, n, sizeof(int), compareInts);
  qsort(listTwo, n, sizeof(int), reverseInts);

  for (i = 0; i < n; i++) {
    result += listOne[i] * listTwo[i];
  }

  printf("%d\n", result);
}
