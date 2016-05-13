#include "naivePointsAndSegments.h"
#include <stdio.h>

void naivePointsAndSegments(struct segment segments[], int sCount, int points[],
                            int pCount, int result[]) {
  int pnt, seg, count;
  for (pnt = 0; pnt < pCount; pnt++) {
    count = 0;
    for (seg = 0; seg < sCount; seg++) {
      if ((points[pnt] >= segments[seg].start) &&
          (points[pnt] <= segments[seg].end)) {
        count++;
      }
    }
    result[pnt] = count;
  }
}
