#include "sorting.h"
#include <assert.h>
#include <stdio.h>

void testSwap() {
  int array[2] = {1, 10};
  swap(&array[0], &array[1]);
  assert(array[0] == 10);
  assert(array[1] == 1);
}

int main() {
  testSwap();
  printf("All tests pass!\n");
}
