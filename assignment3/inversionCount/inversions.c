#include <stdio.h>
#include <stdlib.h>
#include "inversions.h"

int merge_inversions(int array[], int array_start, int middle, int array_end) {
  int i, first_index, second_index, temp_index, array_length, inversion_count;
  array_length = array_end - array_start + 1;
  inversion_count = 0;
  int* temporary_array = malloc(array_length * sizeof(int));

  for (first_index = array_start, second_index = middle, temp_index = 0;
       temp_index < array_length; temp_index++) {
    if (first_index > middle) {
      temporary_array[temp_index] = array[first_index];
      second_index += 1;
    } else if (second_index > array_end) {
      temporary_array[temp_index] = array[first_index];
      first_index += 1;
    } else if (array[first_index] <= array[second_index]) {
      temporary_array[temp_index] = array[first_index];
      first_index += 1;
    } else {
      temporary_array[temp_index] = array[second_index];
      second_index += 1;
    }
  }

  for (second_index = middle; second_index <= array_end; second_index++) {
    for (first_index = middle - 1; first_index >= array_start; first_index--) {
      if (array[first_index] > array[second_index]) {
        inversion_count++;
      }
    }
  }

  for (i = 0; i < array_length; i++) {
    array[i + array_start] = temporary_array[i];
  }

  free(temporary_array);

  return inversion_count;
}

int m_sort_inversion(int array[], int l, int r) {
  if (r == l) {
    return 0;
  }
  int m, il, ir, inv;
  m = ((l + r) / 2) + 1;

  il = m_sort_inversion(array, l, m - 1);
  ir = m_sort_inversion(array, m, r);
  inv = merge_inversions(array, l, m, r);
  return il + ir + inv;
}

int merge_sort_inversion(int array[], int array_length) {
  return m_sort_inversion(array, 0, array_length - 1);
}
