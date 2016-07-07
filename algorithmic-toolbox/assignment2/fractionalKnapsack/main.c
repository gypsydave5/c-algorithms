#include <stdio.h>
#include <stdlib.h>

struct item {
  long double value;
  long double weight;
};

int orderByValue(const void *a, const void *b) {
  const struct item *ia = (const struct item *)a;
  const struct item *ib = (const struct item *)b;
  long double r = (ib->value / ib->weight) - (ia->value / ia->weight);
  if (r > 0) {
    return 1;
  }
  if (r < 0) {
    return -1;
  }
  return 0;
}

int main() {
  int n, capacity, i;
  long double result;
  result = 0;

  scanf("%d %d", &n, &capacity);
  struct item items[n];

  for (i = 0; i < n; i++) {
    scanf("%Lf %Lf", &items[i].value, &items[i].weight);
  }

  qsort(items, n, sizeof(struct item), orderByValue);

  for (i = 0; i < n; i++) {
    if (items[i].weight >= capacity) {
      result += capacity * (items[i].value / items[i].weight);
      break;
    } else {
      capacity -= items[i].weight;
      result += items[i].value;
    }
  }

  printf("%.4Lf\n", result);
}
