#include "max_value.h"
#include <stdio.h>

int get_max_int(int array[], int length) {
  int result = array[0];
  for (int i = 1; i < length; i++) {
    result = result < array[i] ? array[i] : result;
  }
  return result;
}

int get_min_int(int array[], int length) {
  int result = array[0];
  for (int i = 1; i < length; i++) {
    result = result > array[i] ? array[i] : result;
  }
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
    int variants[4];

    left_min = recur(get_min_int, nums, num_start, mid_point, ops);
    left_max = recur(get_max_int, nums, num_start, mid_point, ops);
    right_min = recur(get_min_int, nums, mid_point + 1, num_end, ops);
    right_max = recur(get_max_int, nums, mid_point + 1, num_end, ops);

    if (ops[op_index] == '+') {
      variants[0] = left_min + right_min;
      variants[1] = left_max + right_min;
      variants[2] = left_min + right_max;
      variants[3] = left_max + right_max;
    }
    if (ops[op_index] == '-') {
      variants[0] = left_min - right_min;
      variants[1] = left_max - right_min;
      variants[2] = left_min - right_max;
      variants[3] = left_max - right_max;
    }
    if (ops[op_index] == '*') {
      variants[0] = left_min * right_min;
      variants[1] = left_max * right_min;
      variants[2] = left_min * right_max;
      variants[3] = left_max * right_max;
    }
    result[i] = filter(variants, 4);
  }
  r = filter(result, op_count);
  return r;
}

int naive_max_value(int nums[], int len_nums, char ops[]) {
  return recur(get_max_int, nums, 0, len_nums - 1, ops);
}
