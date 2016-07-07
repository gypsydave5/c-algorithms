#include "pointsAndSegments.h"
#include <stdio.h>
#include <stdlib.h>

int orderPoints(const void *a, const void *b) {
  struct point *pA = (struct point *)a;
  struct point *pB = (struct point *)b;

  if (pA->value == pB->value) {
    return pA->type - pB->type;
  }
  return pA->value - pB->value;
}

void createPoints(struct point line[], int points[], int pCount) {
  for (int i = 0; i < pCount; i++) {
    line[i].type = 'p';
    line[i].value = points[i];
    line[i].index = i;
  }
}

void createSegmentPoints(struct point line[], struct segment segments[],
                         int sCount, int pCount) {
  for (int i = 0; i < sCount; i++) {
    int lIndex = pCount + (i * 2);
    int rIndex = pCount + (i * 2) + 1;

    line[lIndex].type = 'l';
    line[lIndex].value = segments[i].start;
    line[lIndex].index = -1;
    line[rIndex].type = 'r';
    line[rIndex].value = segments[i].end;
    line[rIndex].index = -1;
  }
}

void sortedPointsAndSegments(struct segment segments[], int sCount,
                             int points[], int pCount, int result[]) {

  int lineLength = pCount + (2 * sCount);
  struct point theLine[lineLength];

  createPoints(theLine, points, pCount);
  createSegmentPoints(theLine, segments, sCount, pCount);
  qsort(theLine, lineLength, sizeof(struct point), orderPoints);

  int segsCovering = 0;
  for (int i = 0; i < lineLength; i++) {
    if (theLine[i].type == 'l') {
      segsCovering = segsCovering + 1;
    }
    if (theLine[i].type == 'r') {
      segsCovering = segsCovering - 1;
    }
    if (theLine[i].type == 'p') {
      result[theLine[i].index] = segsCovering;
    }
  }
}
