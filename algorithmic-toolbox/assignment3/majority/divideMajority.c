#include "divideMajority.h"
#include <stdio.h>

int isMajorityDivide(int list[], int low, int high, int candidate) {
  int i, count, maj;
  count = 0;
  maj = (high - low + 1) / 2;

  for (i = low; i <= high; i++) {
    if (list[i] == candidate) {
      count++;
    }
    if (count > (high - low + 1) / 2) {
      return 1;
    }
  }

  return 0;
}

// returns index of majority member
// or -1 if one is not found
int recurMajority(int list[], int low, int high) {
  int lowCand, highCand, mid;

  if (low == high) {
    return high;
  }

  mid = (low + high) / 2;

  lowCand = recurMajority(list, low, mid);
  highCand = recurMajority(list, mid + 1, high);

  if (lowCand != -1 && isMajorityDivide(list, low, high, list[lowCand])) {
    return lowCand;
  }

  if (highCand != -1 && isMajorityDivide(list, low, high, list[highCand])) {
    return highCand;
  }

  return -1;
}

int divideMajority(int list[], int listSize) {
  int res;
  res = recurMajority(list, 0, listSize - 1);

  if (res == -1) {
    return 0;
  } else {
    return 1;
  }
}
