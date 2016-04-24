#include <stdio.h>

int main() {
  int a, b, c;

  scanf("%d %d", &a, &b);

  if (a > b) {
    c = a;
  } else {
    c = b;
  }

  for (; c > 0; --c) {
    if ((a % c == 0) && (b % c == 0)) {
      break;
    }
  }

  printf("%d\n", c);
}