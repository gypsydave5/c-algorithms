#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
  int m = a;
  if (m > b) {
    m = b;
  }
  if (m > c) {
    m = c;
  }
  return m;
}

int editDistanceDP(char fw[], int fwLen, char sw[], int swLen) {
  int matrix[fwLen + 1][swLen + 1], i, j;
  int insertion, deletion, match, mismatch;

  for (i = 0; i <= fwLen; i++) {
    matrix[i][0] = i;
  }

  for (j = 0; j <= swLen; j++) {
    matrix[0][j] = j;
  }

  for (i = 1; i <= fwLen; i++) {
    for (j = 1; j <= swLen; j++) {
      insertion = matrix[i][j - 1] + 1;
      deletion = matrix[i - 1][j] + 1;
      match = matrix[i - 1][j - 1];
      mismatch = matrix[i - 1][j - 1] + 1;

      if (fw[i - 1] == sw[j - 1]) {
        matrix[i][j] = min(insertion, deletion, match);
      } else {
        matrix[i][j] = min(insertion, deletion, mismatch);
      }
    }
  }

  return matrix[fwLen][swLen];
}

int main() {
  char firstWord[100], secondWord[100];
  int fwLen, swLen, ed;

  scanf("%s", firstWord);
  scanf("%s", secondWord);

  fwLen = strlen(firstWord);
  swLen = strlen(secondWord);

  ed = editDistanceDP(firstWord, fwLen, secondWord, swLen);

  printf("%d\n", ed);
}
