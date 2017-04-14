#include "kmp.h"
#include <assert.h>
#include <stdlib.h>

void test_find_pattern_abra_abracadabra() {
  int pattern_len = 4;
  int text_len = 11;
  char pattern[] = "abra";
  char text[] = "abracadabra";
  int *matches = NULL;
  int match_count =
      find_pattern(pattern_len, pattern, text_len, text, &matches);
  assert(match_count == 2);
  assert(matches[0] == 0);
  assert(matches[1] == 7);
}

int main() { test_find_pattern_abra_abracadabra(); }
