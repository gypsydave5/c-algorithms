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

  char text[len];
  text[len] = '\0';

  char result[len];
  result[len] = '\0';

  for (int i = 0; i < len; i++) {
    text[i] = read_in[i];
  }

  // len is the char count including the newline / null char, so less one for
  // the algorithm.
  bwt(len - 1, text, result);

  printf("%s\n", result);
}
