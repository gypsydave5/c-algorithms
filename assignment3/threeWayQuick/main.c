#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int len;
  scanf("%d\n", &len);

  int array[len], i;
  for (i = 0; i < len; i++) {
    scanf("%d", &array[i]);
  }

  randomQS_three_way(array, 0, len - 1);

  for (i = 0; i < len - 1; i++) {
    printf("%d ", array[i]);
  }
  printf("%d\n", array[len - 1]);
}
