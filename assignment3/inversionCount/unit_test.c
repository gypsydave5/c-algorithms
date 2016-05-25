#include <assert.h>
#include <stdio.h>
#include "inversions.h"

void test_merge() {
  int array[2] = {2, 1};
  merge(array, 0, 1, 1);
  assert(array[0] == 1);
  assert(array[1] == 2);
}

void test_merge_inversions() {
  int array[2] = {2, 1};
  int result;
  result = merge_inversions(array, 0, 1, 1);
  assert(result == 1);
}

void test_more_inversions() {
  int array[4] = {1, 2, 3, 4};
  int result;
  result = merge_inversions(array, 0, 2, 3);
  assert(result == 0);
}

int main() {
  test_merge();
  test_merge_inversions();
  printf("All tests passed\n");
}
