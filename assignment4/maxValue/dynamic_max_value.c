#include "max_value.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int add(int a, int b) { return a + b; }
static int subtract(int a, int b) { return a - b; }
static int multiply(int a, int b) { return a * b; }
static int less_than(int a, int b) { return a < b; }
static int greater_than(int a, int b) { return a > b; }

int minBy(int (*op)(int, int), int a_size, int r, int i, int j,
          int mins[a_size][a_size], int maxs[a_size][a_size]) {
  int v[4], k;
  printf("mins[%d][%d] = %d, maxs[%d][%d] = %d\n", i, j, mins[i][j], i, j,
         mins[i][j]);
  v[0] = (*op)(mins[i][j], mins[i][j]);
  v[1] = (*op)(maxs[i][j], mins[i][j]);
  v[2] = (*op)(mins[i][j], maxs[i][j]);
  v[3] = (*op)(maxs[i][j], maxs[i][j]);
  for (k = 0; k < 4; k++) {
    printf("v[%d] = %d\n", k, v[k]);
    r = v[k] < r ? v[k] : r;
  }
  return r;
}

int maxBy(int (*op)(int, int), int a_size, int r, int i, int j,
          int mins[a_size][a_size], int maxs[a_size][a_size]) {
  int v[4], k;
  printf("mins[%d][%d] = %d, maxs[%d][%d] = %d\n", i, j, mins[i][j], i, j,
         mins[i][j]);
  v[0] = (*op)(mins[i][j], mins[i][j]);
  v[1] = (*op)(maxs[i][j], mins[i][j]);
  v[2] = (*op)(mins[i][j], maxs[i][j]);
  v[3] = (*op)(maxs[i][j], maxs[i][j]);
  for (k = 0; k < 4; k++) {
    printf("v[%d] = %d\n", k, v[k]);
    r = v[k] > r ? v[k] : r;
  }
  return r;
}

static void min_max(int a_size, int i, int j, int mins[a_size][a_size],
                    int maxs[a_size][a_size], char ops[]) {
  int k;
  int min = INFINITY;
  int max = -INFINITY;
  for (k = i; k <= j; k++) {
    printf("op: %c\n", ops[k - 1]);
    if (ops[k - 1] == '+') {
      min = minBy(add, a_size, min, i, k, mins, maxs);
      max = maxBy(add, a_size, max, k + 1, j, mins, maxs);
    }
    if (ops[k - 1] == '-') {
      min = minBy(subtract, a_size, min, i, k, mins, maxs);
      max = maxBy(subtract, a_size, max, k + 1, j, mins, maxs);
    }
    if (ops[k - 1] == '*') {
      min = minBy(multiply, a_size, min, i, k, mins, maxs);
      max = maxBy(multiply, a_size, max, k + 1, j, mins, maxs);
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
    mins[i - 1][0] = 0;
    mins[0][i - 1] = 0;
    maxs[i - 1][0] = 0;
    maxs[0][i - 1] = 0;
    mins[i][i] = nums[i - 1];
    maxs[i][i] = nums[i - 1];
  }

  /*for (i = 1; i <= len_nums; i++) {*/
  /*printf("mins[%d][%d] = %d\n", i, i, mins[i][i]);*/
  /*printf("maxs[%d][%d] = %d\n", i, i, maxs[i][i]);*/
  /*}*/

  for (s = 1; s <= (len_nums - 1); s++) {
    for (i = 1; i <= (len_nums - s); i++) {
      int j = i + s;
      min_max(a_size, i, j, mins, maxs, ops);
    }
  }

  printf("mins\n");
  for (s = 0; s < a_size; s++) {
    for (i = 0; i < a_size; i++) {
      printf("%d ", mins[s][i]);
    }
    printf("\n");
  }

  printf("maxs\n");
  for (s = 0; s < a_size; s++) {
    for (i = 0; i < a_size; i++) {
      printf("%d ", maxs[s][i]);
    }
    printf("\n");
  }
  result = maxs[1][len_nums];
  free(maxs);
  free(mins);
  return result;
}
