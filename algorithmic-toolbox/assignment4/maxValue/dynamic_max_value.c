#include "max_value.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int add(int a, int b) { return a + b; }
static int subtract(int a, int b) { return a - b; }
static int multiply(int a, int b) { return a * b; }

static void apply(int (*operation)(int, int), int i, int k, int j, int r[4],
                  int a_size, int mins[a_size][a_size],
                  int maxs[a_size][a_size]) {
  r[0] = (*operation)(maxs[i][k], maxs[k + 1][j]);
  r[1] = (*operation)(maxs[i][k], mins[k + 1][j]);
  r[2] = (*operation)(mins[i][k], maxs[k + 1][j]);
  r[3] = (*operation)(mins[i][k], mins[k + 1][j]);
}

static void min_max(int a_size, int start_num, int end_num,
                    int mins[a_size][a_size], int maxs[a_size][a_size],
                    char operators[]) {
  int mid_num, results[4], min, max, i;
  char current_operator;
  min = 82;
  max = -82;
  for (mid_num = start_num; mid_num < end_num; mid_num++) {
    current_operator = operators[mid_num - 1];
    switch (current_operator) {
    case '+':
      apply(add, start_num, mid_num, end_num, results, a_size, mins, maxs);
      break;
    case '-':
      apply(subtract, start_num, mid_num, end_num, results, a_size, mins, maxs);
      break;
    case '*':
      apply(multiply, start_num, mid_num, end_num, results, a_size, mins, maxs);
      break;
    }
    for (i = 0; i < 4; i++) {
      min = results[i] < min ? results[i] : min;
      max = results[i] > max ? results[i] : max;
    }
  }
  mins[start_num][end_num] = min;
  maxs[start_num][end_num] = max;
}

int dynamic_max_value(int nums[], int len_nums, char ops[]) {
  int start_num, diff, a_size, result, i;
  a_size = len_nums + 1;
  int(*mins)[a_size] = malloc(a_size * a_size * sizeof(int));
  int(*maxs)[a_size] = malloc(a_size * a_size * sizeof(int));

  for (i = 1; i <= len_nums; i++) {
    mins[i][i] = nums[i - 1];
    maxs[i][i] = nums[i - 1];
  }

  for (diff = 1; diff <= len_nums; diff++) {
    for (start_num = 1; start_num <= (len_nums - diff); start_num++) {
      int end_num = start_num + diff;
      min_max(a_size, start_num, end_num, mins, maxs, ops);
    }
  }

  result = maxs[1][len_nums];
  free(maxs);
  free(mins);
  return result;
}
