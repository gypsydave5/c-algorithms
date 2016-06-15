#include <stdio.h>
#include "heap-array.h"

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int parent(int array[], int index) { return index / 2; }
int left_child(int array[], int index) { return index * 2; }
int right_child(int array[], int index) { return index * 2 + 1; }
void sift_down(int array[], int size, int index) {
  int min_index, left, right;
  min_index = index;
  left = left_child(array, index);
  right = right_child(array, index);
  if (left <= size && array[left - 1] < array[min_index - 1]) {
    min_index = left;
  }
  if (right <= size && array[right - 1] < array[min_index - 1]) {
    min_index = right;
  }
  if (index != min_index) {
    swap(&array[index - 1], &array[min_index - 1]);
    sift_down(array, size, min_index);
  }
}