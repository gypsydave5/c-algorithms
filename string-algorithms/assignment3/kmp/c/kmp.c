#include <stdio.h>
#include <stdlib.h>
#include "prefix.h"
int find_pattern(int pattern_len, char pattern[], int text_len, char text[],
                 int **matches) {
  int total_len = pattern_len + 1 + text_len;
  char pattern_and_text[total_len];

  int prefix_array[2000002];

  for (int i = 0; i < pattern_len; ++i) {
    pattern_and_text[i] = pattern[i];
  }

  pattern_and_text[pattern_len] = '$';

  for (int i = 0; i < text_len; ++i) {
    pattern_and_text[pattern_len + i + 1] = text[i];
  }

  prefix(total_len, pattern_and_text, prefix_array);

  int result_count = 0;

  for (int i = 0; i < total_len; ++i) {
    if (prefix_array[i] == pattern_len) {
      result_count++;
    }
  }

  *matches = malloc(result_count * (sizeof(int)));

  int match_pointer = 0;
  for (int i = 0; i < total_len; ++i) {
    if (prefix_array[i] == pattern_len) {
      (*matches)[match_pointer] = (i - (2 * pattern_len));
      match_pointer++;
    }
  }

  return result_count;
}
