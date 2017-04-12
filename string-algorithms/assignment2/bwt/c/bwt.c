#include "bwt.h"
#include <stdlib.h>
#include <string.h>

// TODO: use `strncpy` with a doubled version of the string
// TODO: use pointers instead of `strncpy`

void bwt_cycles(int len, char text[len], char matrix[len][len]) {
  char double_text[len * 2];
  strncpy(double_text, text, len);
  strncpy(double_text + len, text, len);

  for (int i = 0; i < len; i++) {
    strncpy(matrix[i], double_text + i, len);
  }
}

int compare(void *plen, const void *pa, const void *pb) {
  int len = *(int *)plen;
  const char *a = (const char *)pa;
  const char *b = (const char *)pb;

  return strncmp(a, b, len);
}

void bwt_sort(int len, char matrix[len][len]) {
  qsort_r(matrix, len, sizeof matrix[0], &len, &compare);
}

void bwt(int len, char text[len], char result[len]) {
  char matrix[len][len];
  bwt_cycles(len, text, matrix);
  bwt_sort(len, matrix);

  for (int i = 0; i < len; i++) {
    result[i] = matrix[i][len - 1];
  }
}
