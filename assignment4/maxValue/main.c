#include "max_value.h"
#include <stdio.h>

int main() {
  int numbers[15], len_nums, result, i;
  char operators[14], c;

  for (i = 0; (c = getchar()) != EOF; i++) {
    if (i % 2 == 0) {
      numbers[i / 2] = c - 48;
    } else {
      operators[(i - 1) / 2] = c;
    }
  }

  len_nums = i / 2;

  result = dynamic_max_value(numbers, len_nums, operators);
  printf("%d\n", result);
}