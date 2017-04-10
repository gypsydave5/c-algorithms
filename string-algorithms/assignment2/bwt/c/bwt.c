#include "bwt.h"
#include <stdlib.h>
#include <string.h>

int LEN;

void bwt_cycles(int len, char text[len], char matrix[len][len]) {
  for (int i = 0; i < len; i++) {
    int index = 0;
    for (int j = i; j < len; j++) {
      matrix[i][j] = text[index];
      index++;
    }
    for (int k = 0; k < i; k++) {
      matrix[i][k] = text[index];
      index++;
    }
  }
}

int compare(const void *pa, const void *pb) {
  const char *a = (const char *)pa;
  const char *b = (const char *)pb;

  for (int i = 0; i < LEN; i++) {
    if (a[i] < b[i]) return -1;
    if (a[i] > b[i]) return 1;
  }

  return 0;
}

void bwt_sort(int len, char matrix[len][len]) {
  LEN = len;
  qsort(matrix, len, sizeof matrix[0], compare);
}

void bwt(int len, char text[len], char result[len]) {
  char matrix[len][len];
  bwt_cycles(len, text, matrix);
  bwt_sort(len, matrix);

  for (int i = 0; i < len; i++) {
    result[i] = matrix[i][len - 1];
  }
}
