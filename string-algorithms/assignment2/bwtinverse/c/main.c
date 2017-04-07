#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000001

void sort_string(char target[], int count[256], int char_start_index[256]) {
  int index = 0;
  for (int c = 0; c <= 255; ++c) {
    for (int j = 0; j < count[c]; j++) {
      if (char_start_index[c] == -1) {
        char_start_index[c] = index;
      }

      target[index] = c;
      index++;
    }
  }

  target[index] = '\0';
}

int read_in_with_char_counts(char target[], int count[256]) {
  unsigned char c = '\0';
  int bwt_length = 0;

  while (c != '\n') {
    c = getc(stdin);
    if (c == '\n') break;

    target[bwt_length] = c;
    count[c]++;
    bwt_length++;
  }

  return bwt_length;
}

int main() {
  char read_in[1000000];
  int count[256];
  int char_start_index[256];

  for (int i = 0; i < 256; i++) {
    count[i] = 0;
    char_start_index[i] = -1;
  }

  int bwt_length = read_in_with_char_counts(read_in, count);

  char bwt[bwt_length + 1];
  char sorted[bwt_length + 1];
  char answer[bwt_length + 1];
  bwt[bwt_length] = '\0';
  sorted[bwt_length] = '\0';
  answer[bwt_length] = '\0';

  for (int i = bwt_length; i > -1; --i) {
    bwt[i] = read_in[i];
  }

  sort_string(sorted, count, char_start_index);

  answer[bwt_length - 1] = '$';
  int pos = 0;

  for (int i = 1; i < bwt_length; i++) {
    answer[bwt_length - 1 - i] = bwt[pos];
    unsigned char c = bwt[pos];
    pos = char_start_index[c] + count[c];
  }

  printf("len: %d\n", bwt_length);
  printf("%s\n", bwt);
  printf("%s\n", sorted);
}
