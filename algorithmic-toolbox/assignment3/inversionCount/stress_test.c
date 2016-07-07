#include <stdio.h>
#include <stdlib.h>
#include "inversions.h"

int main() {
  int i, len, r1, r2;

  while (1) {
    len = (rand() % 7) + 1;
    int array1[len], array2[len], original[len];
    for (i = 0; i < len; i++) {
      array1[i] = array2[i] = original[i] = (rand() % 9) + 1;
    }

    r1 = merge_sort_inversion(array1, len);
    r2 = merge_sort_inversion_better(array2, len);

    if (r1 != r2) {
      printf("ERROR!\n Naive: %d, Better: %d\n", r1, r2);
      printf("Array: ");
      for (i = 0; i < len; i++) {
        printf("%d ", original[i]);
      }
      break;
    }
    printf("OK!\n");
  }
}
