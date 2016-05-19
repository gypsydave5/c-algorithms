#include "non_rep_knapsack.h"
#include <stdio.h>
#include <stdlib.h>
int non_rep_knapsack(int capacity, int bars[], int bar_count) {
  int(*value)[capacity + 1] =
      malloc((bar_count + 1) * (capacity + 1) * sizeof(int));
  // This is the equivallent of:
  //    int value[bar_count + 1][capacity + 1];
  // only allocated on the heap

  int i, w, val, candidate_bar, result;

  for (i = 0; i <= bar_count; i++) {
    value[i][0] = 0;
  }
  for (i = 0; i <= capacity; i++) {
    value[0][i] = 0;
  }

  for (i = 1; i <= bar_count; i++) {
    for (w = 1; w <= capacity; w++) {
      value[i][w] = value[i - 1][w];
      candidate_bar = bars[i - 1];

      if (candidate_bar <= w) {
        val = value[i - 1][w - candidate_bar] + candidate_bar;

        if (value[i][w] < val) {
          value[i][w] = val;
        }
      }
    }
  }
  result = value[bar_count][capacity];
  free(value);
  return result;
}
