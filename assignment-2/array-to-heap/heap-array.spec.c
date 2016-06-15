#include <assert.h>
#include <stdio.h>
#include "heap-array.h"

void test_parent() {
  int array[5] = {1, 2, 3, 4, 5};
  assert(parent(array, 2) == 1);
  assert(parent(array, 5) == 2);
}

void test_left_child() {
  int array[5] = {10, 20, 30, 40, 50};
  assert(left_child(array, 1) == 2);
  assert(left_child(array, 2) == 4);
}

void test_right_child() {
  int array[5] = {10, 20, 30, 40, 50};
  assert(right_child(array, 1) == 3);
  assert(right_child(array, 2) == 5);
}

void test_sift_down() {
  int array[7] = {50, 40, 30, 20, 10, 2, 5};
  sift_down(array, 7, 1);
  assert(array[0] == 30);
  assert(array[5] == 50);
}

void test_swap() {
  int array[5] = {2, 4, 6, 8, 10};
  swap(&array[0], &array[4]);
  assert(array[0] == 10);
  assert(array[4] == 2);
}

void test_build_heap() {
  int array[5] = {5, 4, 3, 2, 1};
  build_heap(array, 5);
  assert(array[0] == 1);
  assert(array[1] == 2);
  assert(array[2] == 3);
  assert(array[3] == 5);
  assert(array[4] == 4);
}

int main() {
  test_parent();
  test_left_child();
  test_right_child();
  test_swap();
  test_sift_down();
  test_build_heap();
  printf("All tests pass");
}
