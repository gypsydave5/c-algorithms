#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000001

int main() {
  char read_in[1000000];
  char c = '\0';
  int bwt_length = 0;

  while (c != '\n') {
    c = getc(stdin);
    read_in[bwt_length] = c;
    bwt_length++;
  }

  char bwt[bwt_length];
  char sorted[bwt_length];

  for (int i = bwt_length; i > -1; --i) {
    bwt[i] = read_in[i];
    sorted[i] = read_in[i];
  }

  printf("%s", read_in);
  printf("%s", bwt);
}
