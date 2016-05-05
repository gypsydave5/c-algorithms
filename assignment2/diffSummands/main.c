#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned long long *array;
  size_t used;
  size_t size;
} Vector;

void initVector(Vector *v, size_t initialSize) {
  v->array =
      (unsigned long long *)malloc(initialSize * sizeof(unsigned long long));
  v->used = 0;
  v->size = initialSize;
}

void insertVector(Vector *v, unsigned long long element) {
  if (v->used == v->size) {
    v->size *= 2;
    v->array = (unsigned long long *)realloc(
        v->array, v->size * sizeof(unsigned long long));
  }
  v->array[v->used++] = element;
}

int main() {
  unsigned long long n, l, i;
  Vector results;
  l = 1;

  initVector(&results, 10);
  scanf("%lld", &n);

  while (n > 2 * l) {
    insertVector(&results, l);
    n -= l;
    l++;
  }

  insertVector(&results, n);
  printf("%lld\n", l);

  for (i = 0; i < ((unsigned long long)results.used - 1); i++) {
    printf("%lld ", results.array[i]);
  }

  printf("%lld\n", results.array[(unsigned long long)results.used - 1]);
}
