#include "sorting.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_swap() {
  int array[2] = {1, 10};
  swap(&array[0], &array[1]);
  assert(array[0] == 10);
  assert(array[1] == 1);
}

void test_partition3() {
  int array[10] = {4, 7, 9, 8, 10, 10, 4, 4, 1, 1};
  int expected[10] = {1, 1, 4, 4, 4, 10, 10, 8, 9, 7};
  int ml, mr, i = 0;
  partition3(array, 0, 9, &ml, &mr);
  assert(ml == 2);
  assert(mr == 5);
  for (i = 0; i < 10; i++) {
    assert(array[i] == expected[i]);
  }
}

int main() {
  test_swap();
  test_partition3();
  printf("All tests pass!\n");
}
