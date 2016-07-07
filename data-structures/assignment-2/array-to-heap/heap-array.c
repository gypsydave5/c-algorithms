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

static void sift_down_log(int array[], int size, int index, log *l) {
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
    l->logs[l->size].i = index - 1;
    l->logs[l->size].j = min_index - 1;
    l->size++;
    swap(&array[index - 1], &array[min_index - 1]);
    sift_down_log(array, size, min_index, l);
  }
}

void build_heap(int array[], int size) {
  int i;
  for (i = size / 2; i >= 1; i--) {
    sift_down(array, size, i);
  }
}

void build_heap_log(int array[], int size, log *l) {
  int i;
  for (i = size / 2; i >= 1; i--) {
    sift_down_log(array, size, i, l);
  }
}