#include <assert.h>
#include <stdio.h>
#include "bwt.h"

void test_cycle_one_char() {
  int len = 2;
  char text[] = {'a'};
  char matrix[len][len];

  bwt_cycles(len, text, matrix);

  assert(matrix[0][0] == 'a');
}

void test_cycle_two_char() {
  int len = 2;
  char text[] = {'a', 'b'};
  char matrix[len][len];

  bwt_cycles(len, text, matrix);

  assert(matrix[0][0] == 'a');
  assert(matrix[0][1] == 'b');
  assert(matrix[1][0] == 'b');
  assert(matrix[1][1] == 'a');
}

void test_cycle_three_char() {
  int len = 3;
  char text[] = {'a', 'b', 'c'};
  char matrix[len][len];

  bwt_cycles(len, text, matrix);

  assert(matrix[0][0] == 'a');
  assert(matrix[0][1] == 'b');
  assert(matrix[0][2] == 'c');
  assert(matrix[1][0] == 'c');
  assert(matrix[1][1] == 'a');
  assert(matrix[1][2] == 'b');
  assert(matrix[2][0] == 'b');
  assert(matrix[2][1] == 'c');
  assert(matrix[2][2] == 'a');
}

void test_sort() {
  int len = 3;
  char matrix[3][3] = {{'c', 'a', 'b'}, {'b', 'c', 'a'}, {'a', 'b', 'c'}};

  bwt_sort(len, matrix);

  assert(matrix[0][0] == 'a');
  assert(matrix[0][1] == 'b');
  assert(matrix[0][2] == 'c');

  assert(matrix[1][0] == 'b');
  assert(matrix[1][1] == 'c');
  assert(matrix[1][2] == 'a');

  assert(matrix[2][0] == 'c');
  assert(matrix[2][1] == 'a');
  assert(matrix[2][2] == 'b');
}

void test_bwt() {
  int len = 3;
  char text[] = {'a', 'b', 'c'};
  char result[len];

  bwt(len, text, result);

  assert(result[0] == 'c');
  assert(result[1] == 'a');
  assert(result[2] == 'b');
}

int main() {
  test_cycle_one_char();
  test_cycle_two_char();
  test_sort();
  test_bwt();
}
