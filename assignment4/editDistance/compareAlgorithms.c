#include "editDistance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int ed1, ed2, len, i;
  len = 6;
  char firstWord[len], secondWord[len];
  firstWord[len] = secondWord[len] = '\0';

  while (1) {
    for (i = 0; i < len; i++) {
      char c1 = 'a' + (random() % 26);
      char c2 = 'a' + (random() % 26);
      firstWord[i] = c1;
      secondWord[i] = c2;
    }
    ed1 = editDistanceNaive(firstWord, len, secondWord, len);
    ed2 = editDistanceDP(firstWord, len, secondWord, len);

    if (ed1 != ed2) {
      printf("ERROR! - Naive %d, DP: %d\n", ed1, ed2);
      printf("firstWord: %s, secondWord: %s\n", firstWord, secondWord);
      break;
    } else {
      printf("OK!\n");
    }
  }
}
