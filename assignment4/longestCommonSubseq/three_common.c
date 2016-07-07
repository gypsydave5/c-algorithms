#include <stdio.h>
#include "max.h"
#include "three_common.h"

int longest_common_three(int array_one[], int len_one, int array_two[],
                         int len_two, int array_three[], int len_three) {
  int matrix[len_one + 1][len_two + 1][len_three + 1], i, j, k;
  int drop_one, drop_two, drop_three, drop_one_two, drop_two_three,
      drop_one_three, match, mismatch;

  for (i = 0; i <= len_one; i++) {
    for (j = 0; j <= len_two; j++) {
      for (k = 0; k <= len_three; k++) {
        matrix[i][j][k] = 0;
      }
    }
  }

  for (i = 1; i <= len_one; i++) {
    for (j = 1; j <= len_two; j++) {
      for (k = 1; k <= len_three; k++) {
        drop_one = matrix[i - 1][j][k];
        drop_two = matrix[i][j - 1][k];
        drop_three = matrix[i][j][k - 1];
        drop_one_two = matrix[i - 1][j - 1][k];
        drop_two_three = matrix[i][j - 1][k - 1];
        drop_one_three = matrix[i - 1][j][k - 1];
        match = matrix[i - 1][j - 1][k - 1] + 1;
        mismatch = matrix[i - 1][j - 1][k - 1];

        if ((array_one[i - 1] == array_two[j - 1]) &&
            (array_two[j - 1] == array_three[k - 1])) {
          matrix[i][j][k] =
              max_int_seven(drop_one, drop_two, drop_three, drop_one_two,
                            drop_two_three, drop_one_three, match);
        } else {
          matrix[i][j][k] =
              max_int_seven(drop_one, drop_two, drop_three, drop_one_two,
                            drop_two_three, drop_one_three, mismatch);
        }
      }
    }
  }
  return matrix[len_one][len_two][len_three];
}