#include <stdio.h>
#include "print_array.h"

static void read_sequence(int a[], int l) {
  int i;
  for (i = 0; i < l; i++) {
    scanf("%d", &a[i]);
  }
}

int main() {
  int l_1, l_2, l_3, i;
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

  print_array(seq_1, l_1);
  print_array(seq_2, l_2);
  print_array(seq_3, l_3);
}