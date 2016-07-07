#include <stdio.h>
#include <stdlib.h>

long long merge_inversions_better(long long array[], long long array_start,
                                  long long middle, long long array_end) {
  long long i, first_index, second_index, temp_index, array_length,
      inversion_count;
  array_length = array_end - array_start + 1;
  inversion_count = 0;
  long long* temporary_array = malloc(array_length * sizeof(long long));

  for (first_index = array_start, second_index = middle, temp_index = 0;
       temp_index < array_length; temp_index++) {
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
    array[i + array_start] = temporary_array[i];
  }

  free(temporary_array);

  return inversion_count;
}

long long m_sort_inversion_better(long long array[], long long l, long long r) {
  if (r == l) {
    return 0;
  }
  long long m, il, ir, inv;
  m = ((l + r) / 2) + 1;
  il = m_sort_inversion_better(array, l, m - 1);
  ir = m_sort_inversion_better(array, m, r);
  inv = merge_inversions_better(array, l, m, r);
  return il + ir + inv;
}

long long merge_sort_inversion_better(long long array[],
                                      long long array_length) {
  return m_sort_inversion_better(array, 0, array_length - 1);
}

int main() {
  long long len, i, inversions;
  scanf("%lld\n", &len);

  long long* array = malloc(len * sizeof(long long));

  for (i = 0; i < len; i++) {
    scanf("%lld", &array[i]);
  }

  inversions = merge_sort_inversion_better(array, len);

  printf("%lld\n", inversions);

  free(array);
}
