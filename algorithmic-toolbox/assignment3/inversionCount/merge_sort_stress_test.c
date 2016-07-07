#include <stdio.h>
#include <stdlib.h>
#include "inversions.h"

int compare_ints(const void* a, const void* b) {
  int arg1 = *(const int*)a;
  int arg2 = *(const int*)b;

  if (arg1 < arg2) return -1;
  if (arg1 > arg2) return 1;
  return 0;
}

int are_same_arrays(int a1[], int a2[], int len) {
  int i;
  for (i = 0; i < len; i++) {
    if (a1[i] != a2[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int i, len;

  while (1) {
    len = (rand() % 10) + 1;
    int array1[len], array2[len], original[len];
    for (i = 0; i < len; i++) {
      array1[i] = array2[i] = original[i] = (rand() % 10) + 1;
    }

    merge_sort(array1, len);
    qsort(array2, len, sizeof(int), compare_ints);

    if (!are_same_arrays(array1, array2, len)) {
      printf("ERROR!\n");
      printf("Merge: ");
      print_array(array1, len);
      printf("QSort: ");
      print_array(array2, len);
      printf("Original: ");
      print_array(original, len);
      break;
    }
    printf("OK!\n");
  }
}
