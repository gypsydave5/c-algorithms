#include "defs.h"
#include <stdio.h>

int main() {
  int listSize, i;
  scanf("%d", &listSize);
  int list[listSize];

  for (i = 0; i < listSize; i++) {
    scanf("%d", &list[i]);
  }

  int querySize;
  scanf("%d", &querySize);
  int query[querySize];
  int results[querySize];

  for (i = 0; i < querySize; i++) {
    scanf("%d", &query[i]);
  }

  binarySearchList(list, listSize, query, querySize, results);

  for (i = 0; i < querySize - 1; i++) {
    printf("%d ", results[i]);
  }
  printf("%d\n", results[i]);
}
