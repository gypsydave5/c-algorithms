#include "max.h"
#include "two_common.h"

int longest_common_two(int array_one[], int len_one, int array_two[],
                       int len_two) {
  int matrix[len_one + 1][len_two + 1], i, j;
  int insertion, deletion, match, mismatch;

  for (i = 0; i <= len_one; i++) {
    matrix[i][0] = 0;
  }

  for (j = 0; j <= len_two; j++) {
    matrix[0][j] = 0;
  }

  for (i = 1; i <= len_one; i++) {
    for (j = 1; j <= len_two; j++) {
      insertion = matrix[i][j - 1];
      deletion = matrix[i - 1][j];
      match = matrix[i - 1][j - 1] + 1;
      mismatch = matrix[i - 1][j - 1];

      if (array_one[i - 1] == array_two[j - 1]) {
        matrix[i][j] = max(insertion, deletion, match);
      } else {
        matrix[i][j] = max(insertion, deletion, mismatch);
      }
    }
  }
  return matrix[len_one][len_two];
}
