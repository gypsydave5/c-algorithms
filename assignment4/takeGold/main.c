#include <stdio.h>
#include "non_rep_knapsack.h"

int main() {
  int capacity, bar_count, i, result;
  scanf("%d %d\n", &capacity, &bar_count);
  int bars[bar_count];

  for (i = 0; i < bar_count; i++) {
    scanf("%d", &bars[i]);
  }

  result = non_rep_knapsack(capacity, bars, bar_count);

  printf("%d\n", result);
}