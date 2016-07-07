#include <stdio.h>
#include "print_array.h"
#include "three_common.h"

static void read_sequence(int a[], int l) {
  int i;
  for (i = 0; i < l; i++) {
    scanf("%d", &a[i]);
  }
}

int main() {
  int l_1, l_2, l_3, i, result;
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

  scanf("%d\n", &l_3);
  int seq_3[l_3];

  for (i = 0; i < l_3; i++) {
    scanf("%d", &seq_3[i]);
  }

  result = longest_common_three(seq_1, l_1, seq_2, l_2, seq_3, l_3);
  printf("%d\n", result);
}