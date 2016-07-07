#include <stdio.h>
#include <stdlib.h>
#include "inversions.h"

int main() {
  int len, i, inversions;
  scanf("%d\n", &len);

  int* array = malloc(len * sizeof(int));

  for (i = 0; i < len; i++) {
    scanf("%d", &array[i]);
  }

  inversions = merge_sort_inversion(array, len);

  printf("%d\n", inversions);

  free(array);
}