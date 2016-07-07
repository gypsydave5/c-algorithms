#include <stdio.h>

int makeChange(int);

int main() {
  int n, result;
  scanf("%d\n", &n);

  result = makeChange(n);
  printf("%d\n", result);
}

int makeChange(int n) {
  int coins;
  coins = 0;

  while ((n - 10) >= 0) {
    n -= 10;
    coins++;
  }

  while ((n - 5) >= 0) {
    n -= 5;
    coins++;
  }

  coins += n;
  return coins;
}