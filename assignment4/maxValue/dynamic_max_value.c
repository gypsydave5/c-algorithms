#include "max_value.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int add(int a, int b) { return a + b; }
static int subtract(int a, int b) { return a - b; }
static int multiply(int a, int b) { return a * b; }

static void min_max(int a_size, int i, int j, int mins[a_size][a_size],
                    int maxs[a_size][a_size], char ops[]) {
  int k, l;
  int min = INT_MAX;
  int max = INT_MIN;
  int r[4];
  for (k = i; k < j; k++) {
    if (ops[k - 1] == '+') {
      r[0] = maxs[i][k] + maxs[k + 1][j];
      r[1] = maxs[i][k] + mins[k + 1][j];
      r[2] = mins[i][k] + maxs[k + 1][j];
      r[3] = mins[i][k] + mins[k + 1][j];
    }
    if (ops[k - 1] == '-') {
      r[0] = maxs[i][k] - maxs[k + 1][j];
      r[1] = maxs[i][k] - mins[k + 1][j];
      r[2] = mins[i][k] - maxs[k + 1][j];
      r[3] = mins[i][k] - mins[k + 1][j];
    }
    if (ops[k - 1] == '*') {
      r[0] = maxs[i][k] * maxs[k + 1][j];
      r[1] = maxs[i][k] * mins[k + 1][j];
      r[2] = mins[i][k] * maxs[k + 1][j];
      r[3] = mins[i][k] * mins[k + 1][j];
    }
    for (l = 0; l < 4; l++) {
      min = r[l] < min ? r[l] : min;
      max = r[l] > max ? r[l] : max;
    }
  }
  mins[i][j] = min;
  maxs[i][j] = max;
}

int dynamic_max_value(int nums[], int len_nums, char ops[]) {
  int i, s, a_size, result;
  a_size = len_nums + 1;
  int(*mins)[a_size] = malloc(a_size * a_size * sizeof(int));
  int(*maxs)[a_size] = malloc(a_size * a_size * sizeof(int));

  for (i = 1; i <= len_nums; i++) {
    mins[i][i] = nums[i - 1];
    maxs[i][i] = nums[i - 1];
  }

  for (s = 1; s <= len_nums; s++) {
    for (i = 1; i <= (len_nums - s); i++) {
      int j = i + s;
      min_max(a_size, i, j, mins, maxs, ops);
    }
  }

  result = maxs[1][len_nums];
  free(maxs);
  free(mins);
  return result;
}
