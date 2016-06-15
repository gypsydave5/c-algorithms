#include <stdio.h>
#include <stdlib.h>
#include "heap-array.h"

int main() {
  int size, i;
  scanf("%d\n", &size);

  int *input_array;
  input_array = malloc(size * sizeof(int));

  log logs;
  log_init(&logs, size * 4);

  for (i = 0; i < size; i++) {
    scanf("%d\n", &input_array[i]);
  }

  build_heap_log(input_array, size, &logs);

  printf("%d\n", logs.size);
  for (i = 0; i < logs.size; i++) {
    printf("%d %d\n", logs.logs[i].i, logs.logs[i].j);
  }

  free(input_array);
}
