#include <stdio.h>
#include <stdlib.h>
#include "bwt.h"

int main() {
  char read_in[1000000];

  unsigned char c = '\0';
  int len = 0;

  while (c != '\n') {
    c = getc(stdin);
    read_in[len] = c;
    len++;
  }

  char result[len];
  result[len - 1] = '\0';

  // len is the char count including the newline / null char, so less one for
  // the algorithm.
  bwt(len - 1, read_in, result);

  printf("%s\n", result);
}
