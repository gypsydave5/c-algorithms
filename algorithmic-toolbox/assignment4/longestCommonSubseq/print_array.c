#include <stdio.h>
#include "print_array.h"

void print_array(int array[], int len) {
  int i;
  for (i = 0; i < len - 1; i++) {
    printf("%d ", array[i]);
  }
  printf("%d\n", array[i]);
}

void print_array_range(int array[], int l, int r) {
  for (; l <= r; l++) {
    printf("%d ", array[l]);
  }
  printf("\n");
}
