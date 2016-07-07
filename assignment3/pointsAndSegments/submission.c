#include <stdio.h>
#include <stdlib.h>

struct segment {
  int start;
  int end;
};

struct point {
  char type;
  int value;
  int index;
};

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

  sortedPointsAndSegments(segments, sCount, points, pCount, result);

  for (i = 0; i < pCount - 1; i++) {
    printf("%d ", result[i]);
  }

  printf("%d\n", result[pCount - 1]);
}