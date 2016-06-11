#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void darray_push(darray *da, node *n) {
  da->top++;
  if (da->capacity - 1 < da->top) {
    darray_grow(da);
  }
  da->array[da->top] = n;
}

node *darray_pop(darray *da) {
  node *n;
  n = darray_get(da, da->top);
  darray_set(da, da->top, NULL);
  da->top -= 1;
  return n;
}

void darray_init(darray *da) {
  da->capacity = 0;
  da->top = -1;
  da->array = NULL;
}

void darray_null_range(darray *da, long long start, long long stop) {
  long long i;
  for (i = start; i < stop; i++) {
    da->array[i] = NULL;
  }
}

node *darray_get(darray *da, long long index) { return da->array[index]; }

void darray_set(darray *da, long long index, node *n) {
  if ((da->capacity - 1) < index) {
    darray_grow(da);
    darray_set(da, index, n);
    return;
  }
  darray_null_range(da, da->top + 1, index);
  da->array[index] = n;
}

void darray_grow(darray *da) {
  if (da->capacity == 0) {
    da->capacity = 1;
    da->array = malloc(sizeof(node));
    return;
  }

  node **resized_array;
  long long i;
  resized_array = malloc(2 * (da->capacity) * sizeof(node));
  for (i = 0; i < da->capacity; i++) {
    resized_array[i] = da->array[i];
  }
  free(da->array);
  da->capacity = 2 * da->capacity;
  da->array = resized_array;
}
