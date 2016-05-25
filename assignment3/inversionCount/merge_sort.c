#include <stdio.h>
#include <stdlib.h>
#include "inversions.h"

void merge(int array[], int array_start, int middle, int array_end) {
  int i, first_index, second_index, temp_index, array_length;
  array_length = array_end - array_start + 1;
  int* temporary_array = malloc(array_length * sizeof(int));
  for (first_index = array_start, second_index = middle, temp_index = 0;
       temp_index < array_length; temp_index++) {
    if (first_index > middle) {
      temporary_array[temp_index] = array[first_index];
      second_index += 1;
    } else if (second_index > array_end) {
      temporary_array[temp_index] = array[first_index];
      first_index += 1;
    } else if (array[first_index] < array[second_index]) {
      temporary_array[temp_index] = array[first_index];
      first_index += 1;
    } else {
      temporary_array[temp_index] = array[second_index];
      second_index += 1;
    }
  }

  for (i = 0; i < array_length; i++) {
    array[i + array_start] = temporary_array[i];
  }

  free(temporary_array);
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
