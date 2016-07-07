#include <stdio.h>
#include "defs.h"

void naiveSearch(int list[], int listSize, int query[], int querySize,
                 int results[]) {
  int i, j;
  for (i = 0; i < querySize; i++) {
    results[i] = -1;
    for (j = 0; j < listSize; j++) {
      if (query[i] == list[j]) {
        results[i] = j;
        break;
      }
    }
  }
}