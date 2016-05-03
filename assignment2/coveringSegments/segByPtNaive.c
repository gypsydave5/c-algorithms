#include "segment.h"

int segByPtsNaive(int len, struct segment segs[len]) {
  int max, min;
  max = min = 0;
  for (int i = 0; i < len; i++) {
    if (segs[i].end > max) {
      max = segs[i].end;
    }
    if (min == 0 || min > segs[i].start) {
      min = segs[i].start;
    }
  }
}