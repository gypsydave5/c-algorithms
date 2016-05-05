#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned long long n, l, i;
  l = 1;

  scanf("%lld", &n);

  while (n > 2 * l) {
    n -= l;
    l++;
  }

  printf("%lld\n", l);

  for (i = 1; i < l; i++) {
    printf("%lld ", i);
  }

  printf("%lld\n", n);
}
