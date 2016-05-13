#include "naivePointsAndSegments.h"
#include <stdio.h>

int main() {
  int sCount, pCount, i;
  scanf("%d %d\n", &sCount, &pCount);
  struct segment segments[sCount];
  int points[pCount], result[pCount];

  for (i = 0; i < sCount; i++) {
    scanf("%d %d\n", &segments[i].start, &segments[i].end);
  }

  for (i = 0; i < pCount; i++) {
    scanf("%d", &points[i]);
  }

  naivePointsAndSegments(segments, sCount, points, pCount, result);

  for (i = 0; i < pCount - 1; i++) {
    printf("%d ", result[i]);
  }

  printf("%d\n", result[pCount - 1]);
}
