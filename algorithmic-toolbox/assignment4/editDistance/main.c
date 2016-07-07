#include "editDistance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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