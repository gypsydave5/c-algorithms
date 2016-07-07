#include <assert.h>
#include <stdio.h>
#include "inversions.h"

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

void test_more_inversions_again() {
  int array[10] = {1, 1, 3, 3, 3, 1, 1, 3, 4, 6};
  int result;
  result = merge_inversions(array, 0, 5, 9);
  if (result != 6) {
    printf("test_more_inversions failed: Expected %d, got %d\n", 6, result);
  }
}

void test_better_inversions() {
  int array[10] = {1, 1, 3, 3, 3, 1, 1, 3, 4, 6};
  int result;
  result = merge_inversions_better(array, 0, 5, 9);
  if (result != 6) {
    printf("test_better_inversions failed: Expected %d, got %d\n", 6, result);
  }
}

int main() {
  test_merge_inversions();
  test_more_inversions_again();
  test_better_inversions();
  printf("All tests passed\n");
}
