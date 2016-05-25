#include <assert.h>
#include <stdio.h>
#include "inversions.h"

void test_merge() {
  int array[] = {2, 1};
  merge(array, 0, 1, 1);
  assert(array[0] == 1);
  assert(array[1] == 2);
}

int main() {
  test_merge();
  printf("All tests passed\n");
}
