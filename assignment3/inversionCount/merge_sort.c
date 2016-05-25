#include <stdio.h>
#include <stdlib.h>
#include "inversions.h"

void merge(int array[], int l, int m, int r) {
  int i, j, k, len;
  len = r - l + 1;
  int* temp = malloc(len * sizeof(int));
  for (i = l, j = m, k = 0; k < len; k++) {
    if (i > m) {
      temp[k] = array[j];
      j++;
    } else if (j > r) {
      temp[k] = array[i];
      i++;
    } else if (array[i] < array[j]) {
      temp[k] = array[i];
      i++;
    } else {
      temp[k] = array[j];
      j++;
    }
  }

  for (i = 0; i < len; i++) {
    array[i + l] = temp[i];
  }

  free(temp);
}

void m_sort(int array[], int l, int r) {
  if (r == l) {
    return;
  }
  int m;
  m = ((l + r) / 2) + 1;

  m_sort(array, l, m - 1);
  m_sort(array, m, r);
  merge(array, l, m, r);
}

void merge_sort(int array[], int array_length) {
  m_sort(array, 0, array_length - 1);
}
