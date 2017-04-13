#include <stdio.h>
#include <stdlib.h>
#include "kmp.h"

int read_line(char a[]) {
  unsigned char c;
  int len = 0;

  while ((c = getc(stdin)) != '\n') {
    a[len] = c;
    len++;
  }

  a[len + 1] = '\0';
  return len;
}

int main() {
  int max_len = 1000001;
  char text[max_len];
  int text_len;

  char pattern[max_len];
  int pattern_len;

  pattern_len = read_line(pattern);
  text_len = read_line(text);

  int **matches = NULL;
  int total_matches = find_pattern(pattern, text, matches);

  printf("%s\n", text);
  printf("%s\n", pattern);
  printf("%d\n", total_matches);
}
