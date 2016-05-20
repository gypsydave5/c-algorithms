#include "maxValue.h"
#include <stdio.h>

int recur_min(int nums[], int num_start, int num_end, char ops[]);
int recur_max(int nums[], int num_start, int num_end, char ops[]);

int get_max_int(int array[], int length) {
  int result = array[0];
  printf("values: %d ", array[0]);
  for (int i = 1; i < length; i++) {
    printf("%d ", array[i]);
    result = result < array[i] ? array[i] : result;
  }
  printf("\nwinner: %d\n", result);
  return result;
}

int get_min_int(int array[], int length) {
  int result = array[0];
  printf("values: %d ", array[0]);
  for (int i = 1; i < length; i++) {
    printf("%d ", array[i]);
    result = result > array[i] ? array[i] : result;
  }
  printf("\nwinner: %d\n", result);
  return result;
}

int recur(int (*filter)(int a[], int l), int nums[], int num_start, int num_end,
          char ops[]) {
  if (num_end == num_start) {
    return nums[num_end];
  }

  int op_count = num_end - num_start;
  int result[op_count], r;

  for (int i = 0; i < op_count; i++) {
    int mid_point = num_start + i;
    int op_index = num_start + i;
    int left_min, left_max, right_min, right_max;

    printf("(%d, %d) %c (i: %d) (%d, %d)\n", num_start, mid_point,
           ops[op_index], op_index, mid_point + 1, num_end);

    left_min = recur(get_min_int, nums, num_start, mid_point, ops);
    left_max = recur(get_max_int, nums, num_start, mid_point, ops);
    right_min = recur(get_min_int, nums, mid_point + 1, num_end, ops);
    right_max = recur(get_max_int, nums, mid_point + 1, num_end, ops);

    printf("lmin: %d, rmin: %d\n", left_min, right_min);
    printf("lmax: %d, rmax: %d\n", left_max, right_max);

    if (ops[op_index] == '+') {
      result[i] = left_max + right_max;
    }
    if (ops[op_index] == '-') {
      result[i] = left_max - right_min;
    }
    if (ops[op_index] == '*') {
      int mins, maxs;
      mins = left_min * right_min;
      maxs = left_max * right_max;
      result[i] = mins > maxs ? mins : maxs;
    }
    printf("res[%d]: %d\n", i, result[i]);
  }
  r = filter(result, op_count);
  return r;
}

int naive_max_value(int nums[], int len_nums, char ops[]) {
  return recur(get_max_int, nums, 0, len_nums - 1, ops);
}
