#include <stdio.h>
#include <stdlib.h>

int compareInts(const void *a, const void *b) {
  const long long *ia = (const long long *)a;
  const long long *ib = (const long long *)b;
  return *ia - *ib;
}

int reverseInts(const void *a, const void *b) {
  const long long *ia = (const long long *)a;
  const long long *ib = (const long long *)b;
  return *ib - *ia;
}

int main() {
  long long n, result, i;
  result = 0;

  scanf("%lld\n", &n);
  long long listOne[n], listTwo[n];

  for (i = 0; i < n; i++) {
    scanf("%lld", &listOne[i]);
  }

  for (i = 0; i < n; i++) {
    scanf("%lld", &listTwo[i]);
  }

  qsort(listOne, n, sizeof(long long), compareInts);
  qsort(listTwo, n, sizeof(long long), reverseInts);

  for (i = 0; i < n; i++) {
    result += listOne[i] * listTwo[i];
  }

  printf("%lld\n", result);
}
