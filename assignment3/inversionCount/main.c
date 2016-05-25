#include <stdio.h>
#include <stdlib.h>
#include "inversions.h"

int main() {
  int len, i;
  scanf("%d\n", &len);

  int* array = malloc(len * sizeof(int));

  for (i = 0; i < len; i++) {
    scanf("%d", &array[i]);
  }

  merge_sort(array, len);

  for (i = 0; i < (len - 1); i++) {
    printf("%d ", array[i]);
  }
  printf("%d\n", array[i]);

  free(array);
}