#include "non_rep_knapsack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int capacity, bar_count, i, result;

  while (1) {
    capacity = (rand() % 100000) + 1;
    bar_count = (rand() % 300) + 1;

    int bars[bar_count];

    for (i = 0; i < bar_count; i++) {
      bars[i] = (rand() % 1000000) + 1;
    }

    result = non_rep_knapsack(capacity, bars, bar_count);

  }
}
