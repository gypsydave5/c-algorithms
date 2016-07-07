#include "defs.h"
#include <stdio.h>

int binarySearchIterative(int array[], int high, int key);

void binarySearchListIterative(int list[], int listSize, int query[],
                               int querySize, int results[]) {
  int i;
  for (i = 0; i < querySize; i++) {
    results[i] = binarySearchIterative(list, listSize - 1, query[i]);
  }
}

int binarySearchIterative(int array[], int high, int key) {
  int low = 0;
  while (low <= high) {
    int m = (low + high) / 2;
    if (array[m] > key) {
      high = m - 1;
    }
    if (array[m] < key) {
      low = m + 1;
    }
    if (array[m] == key) {
      return m;
    }
  }
  return -1;
}
