#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

int array_differs(int a1[], int a2[], int len) {
  int i;
  for (i = 0; i < len; i++) {
    if (a1[i] != a2[i]) {
      return 1;
    }
  }
  return 0;
}

void print_array(int a[], int len) {
  int i;
  for (i = 0; i < (len - 1); i++) {
    printf("%d ", a[i]);
  }
  printf("%d\n", a[i]);
}

int main() {
  while (1) {
    int len = (rand() % 10) + 1;
    int i, original[len], array[len], array_copy[len];
    for (i = 0; i < len; i++) {
      original[i] = array[i] = array_copy[i] = (rand() % 10) + 1;
    }

    randomQS(array, 0, len - 1);
    randomQS_three_way(array_copy, 0, len - 1);

    if (array_differs(array, array_copy, len)) {
      printf("ERROR!\n");
      printf("original: ");
      print_array(original, len);
      printf("qs: ");
      print_array(array, len);
      printf("3w: ");
      print_array(array_copy, len);
      break;
    }

    printf("OK!");
  }
}