#include "max_value.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int len_nums, j, result1, result2, i;
  while (1) {
    char op_set[3] = {'+', '-', '*'};

    len_nums = ((rand() % 5) + 1) * 2;
    int nums[len_nums];
    char ops[len_nums - 1];

    for (j = 0; j < len_nums; j++) {
      nums[j] = rand() % 10;
    }

    for (j = 0; j < (len_nums - 1); j++) {
      ops[j] = op_set[rand() % 3];
    }

    result1 = dynamic_max_value(nums, len_nums, ops);
    result2 = naive_max_value(nums, len_nums, ops);

    printf("Expression: ");
    for (i = 0; i < (len_nums - 1); i++) {
      printf("%d%c", nums[i], ops[i]);
    }
    printf("%d\n", nums[i]);

    if (result1 != result2) {
      printf("ERROR! mismatch\n");
      printf("dynamic: %d, naive %d", result1, result2);
      break;
    }
    printf("OK!\n");
  }
}