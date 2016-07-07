#include "naiveMajority.h"
#include <stdio.h>

int main() {
  int listSize, i;
  scanf("%d\n", &listSize);
  int list[listSize];

  for (i = 0; i < listSize; i++) {
    scanf("%d", &list[i]);
  }

  printf("%d\n", naiveMajority(list, listSize));
}