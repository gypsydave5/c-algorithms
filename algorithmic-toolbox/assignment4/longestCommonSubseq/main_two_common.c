#include <stdio.h>
#include "print_array.h"
#include "two_common.h"

int main() {
  int l_1, l_2, i, res;
  scanf("%d\n", &l_1);

  int seq_1[l_1];

  for (i = 0; i < l_1; i++) {
    scanf("%d", &seq_1[i]);
  }

  scanf("%d\n", &l_2);
  int seq_2[l_2];

  for (i = 0; i < l_2; i++) {
    scanf("%d", &seq_2[i]);
  }

  res = longest_common_two(seq_1, l_1, seq_2, l_2);
  printf("%d\n", res);
}