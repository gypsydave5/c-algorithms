#include <stdio.h>
#include <stdlib.h>
#include "inversions.h"

int merge_inversions_better(int array[], int array_start, int middle,
                            int array_end) {
  int i, first_index, second_index, temp_index, array_length, inversion_count;
  array_length = array_end - array_start + 1;
  inversion_count = 0;
  int* temporary_array = malloc(array_length * sizeof(int));

  for (first_index = array_start, second_index = middle, temp_index = 0;
       temp_index < array_length; temp_index++) {
    printf("first_index: %d, second_index: %d\n", first_index, second_index);
    printf("array[%d]: %d, array[%d]: %d\n", first_index, array[first_index],
           second_index, array[second_index]);
    if (first_index >= middle) {
      temporary_array[temp_index] = array[second_index];
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
      inversion_count = inversion_count + (middle - first_index);
    }
  }

  for (i = 0; i < array_length; i++) {
    printf("array[%d]: %d\n", i + array_start, temporary_array[i]);
    array[i + array_start] = temporary_array[i];
  }

  free(temporary_array);

  return inversion_count;
}

int m_sort_inversion_better(int array[], int l, int r) {
  if (r == l) {
    return 0;
  }
  int m, il, ir, inv;
  m = ((l + r) / 2) + 1;
  il = m_sort_inversion_better(array, l, m - 1);
  ir = m_sort_inversion_better(array, m, r);
  print_array_range(array, l, r);
  inv = merge_inversions_better(array, l, m, r);
  printf("inversion: %d\n", il + ir + inv);
  return il + ir + inv;
}

int merge_sort_inversion_better(int array[], int array_length) {
  return m_sort_inversion_better(array, 0, array_length - 1);
}
