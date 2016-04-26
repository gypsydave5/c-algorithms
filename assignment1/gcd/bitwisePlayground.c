#include <stdio.h>
#include <stdlib.h>

char *bin(unsigned int x) {
  int i;

  char *out = malloc(32 + 1);

  for (i = 0; i < 31; i++) {
    unsigned int n;

    n = 1 << (30 - i);

    if (x & n) {
      out[i] = '1';
    } else {
      out[i] = '0';
    }
  }

  return out;
}

int main() {
  printf("%s\n", bin(55));
  printf("%s\n", bin(~55));
  printf("%s\n", bin(~55 & 55));
  printf("%s\n", bin(~55 | 55));
}