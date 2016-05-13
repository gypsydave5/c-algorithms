#include "mooreMajority.h"

int getCandidate(int list[], int listSize) {
  int majorityIndex, count, i;
  majorityIndex = 0;
  count = 1;

  for (i = 1; i < listSize; i++) {
    if (list[i] == list[majorityIndex]) {
      count++;
    } else {
      count--;
    }
    if (count == 0) {
      majorityIndex = i;
      count = 1;
    }
  }

  return list[majorityIndex];
}

int isMajorityMoore(int list[], int listSize, int candidate) {
  int i, count;
  count = 0;

  for (i = 0; i < listSize; i++) {
    if (list[i] == candidate) {
      count++;
    }
    if (count > listSize / 2) {
      return 1;
    }
  }
  return 0;
}

int mooreMajority(int list[], int listSize) {
  int candidate = getCandidate(list, listSize);
  return isMajorityMoore(list, listSize, candidate);
}
