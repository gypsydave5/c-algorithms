#include "editDistance.h"

int editDistanceNaive(char fw[], int fwLen, char sw[], int swLen) {
  int a, b, c;

  if (!fwLen) {
    return swLen;
  }
  if (!swLen) {
    return fwLen;
  }

  if (fw[fwLen - 1] == sw[swLen - 1]) {
    return editDistanceNaive(fw, fwLen - 1, sw, swLen - 1);
  }

  a = editDistanceNaive(fw, fwLen - 1, sw, swLen - 1);
  b = editDistanceNaive(fw, fwLen, sw, swLen - 1);
  c = editDistanceNaive(fw, fwLen - 1, sw, swLen);

  if (a > b) {
    a = b;
  }
  if (a > c) {
    a = c;
  }

  return a + 1;
}
