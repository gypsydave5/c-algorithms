#include <stdio.h>

long long fibStep(long long a, long long b, int i) {
  if (i == 0) {
    return a + b;
  }
  return fibStep(b, a + b, --i);
}

long long smallFib(int i) { return fibStep(0, 1, i); }

int main() {
  int i;
  scanf("%d", &i);
  if (i == 1) {
    printf("1\n");
  } else {
    printf("%lld\n", smallFib(i - 2));
  }
}