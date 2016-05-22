#include "sorting.h"
#include <assert.h>
#include <stdio.h>

void test_swap() {
  int array[2] = {1, 10};
  swap(&array[0], &array[1]);
  assert(array[0] == 10);
  assert(array[1] == 1);
}

void test_partition3() {
  int array[10] = {4, 1, 1, 1, 10, 6, 4, 4, 4, 10};
  int ml, mr = 0;
  partition3(array, 0, 10, &ml, &mr);
  assert(ml == 3);
  assert(mr == 7);
}

int main() {
  test_swap();
  test_partition3();
  printf("All tests pass!\n");
}
