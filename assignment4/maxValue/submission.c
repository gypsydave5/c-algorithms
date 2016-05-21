#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static long long add(long long a, long long b) { return a + b; }
static long long subtract(long long a, long long b) { return a - b; }
static long long multiply(long long a, long long b) { return a * b; }

static void apply(long long (*operation)(long long, long long), long long i,
                  long long k, long long j, long long r[4], long long a_size,
                  long long mins[a_size][a_size],
                  long long maxs[a_size][a_size]) {
  r[0] = (*operation)(maxs[i][k], maxs[k + 1][j]);
  r[1] = (*operation)(maxs[i][k], mins[k + 1][j]);
  r[2] = (*operation)(mins[i][k], maxs[k + 1][j]);
  r[3] = (*operation)(mins[i][k], mins[k + 1][j]);
}

static void min_max(long long a_size, long long start_num, long long end_num,
                    long long mins[a_size][a_size],
                    long long maxs[a_size][a_size], char operators[]) {
  long long mid_num, results[4], min, max, i;
  char current_operator;
  min = INT_MAX;
  max = INT_MIN;
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

long long dynamic_max_value(long long nums[], long long len_nums, char ops[]) {
  long long start_num, diff, a_size, result, i;
  a_size = len_nums + 1;
  long long(*mins)[a_size] = malloc(a_size * a_size * sizeof(long long));
  long long(*maxs)[a_size] = malloc(a_size * a_size * sizeof(long long));

  for (i = 1; i <= len_nums; i++) {
    mins[i][i] = nums[i - 1];
    maxs[i][i] = nums[i - 1];
  }

  for (diff = 1; diff <= len_nums; diff++) {
    for (start_num = 1; start_num <= (len_nums - diff); start_num++) {
      long long end_num = start_num + diff;
      min_max(a_size, start_num, end_num, mins, maxs, ops);
    }
  }

  result = maxs[1][len_nums];
  free(maxs);
  free(mins);
  return result;
}

int main() {
  long long numbers[15], len_nums, result, i;
  char operators[14], c;

  for (i = 0; (c = getchar()) != EOF; i++) {
    if (i % 2 == 0) {
      numbers[i / 2] = c - 48;
    } else {
      operators[(i - 1) / 2] = c;
    }
  }

  len_nums = i / 2;

  result = dynamic_max_value(numbers, len_nums, operators);
  printf("%lld\n", result);
}