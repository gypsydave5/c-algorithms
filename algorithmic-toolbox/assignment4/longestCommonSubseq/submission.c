#include <stdio.h>

int max_int_seven(int a, int b, int c, int d, int e, int f, int g) {
  int result = a;
  result = b > result ? b : result;
  result = c > result ? c : result;
  result = d > result ? d : result;
  result = e > result ? e : result;
  result = f > result ? f : result;
  result = g > result ? g : result;
  return result;
}

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