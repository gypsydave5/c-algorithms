#include <stdio.h>
#include <stdlib.h>
#include "inversions.h"

int merge_inversions(int array[], int array_start, int middle, int array_end) {
  int i, j, inversions;
  inversions = 0;
  for (i = array_start; i <= array_end; i++) {
    for (j = i + 1; j <= array_end; j++) {
      if (array[i] > array[j]) {
        inversions++;
      }
    }
  }
  return inversions;
}

int m_sort_inversion(int array[], int l, int r) {
  int m, inv;
  m = ((l + r) / 2) + 1;

  inv = merge_inversions(array, l, m, r);
  return inv;
}

int merge_sort_inversion(int array[], int array_length) {
  return m_sort_inversion(array, 0, array_length - 1);
}
