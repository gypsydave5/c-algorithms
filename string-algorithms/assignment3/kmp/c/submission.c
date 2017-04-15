#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int MAX_LEN = 2000000;

void prefix(unsigned long long len, char text[len],
            unsigned long long prefix_array[len]) {
  unsigned long long border = 0;
  prefix_array[0] = 0;

  for (unsigned long long i = 1; i < len; ++i) {
    while ((border > 0) && (text[i] != text[border])) {
      border = prefix_array[border - 1];
    }

    if (text[i] == text[border]) {
      border = border + 1;
    } else {
      border = 0;
    }

    prefix_array[i] = border;
  }
}

unsigned long long find_pattern(unsigned long long pattern_len, char pattern[],
                                unsigned long long text_len, char text[],
                                unsigned long long **matches) {
  unsigned long long total_len = pattern_len + 1 + text_len;
  char pattern_and_text[total_len];

  unsigned long long prefix_array[total_len];

  for (unsigned long long i = 0; i < pattern_len; ++i) {
    pattern_and_text[i] = pattern[i];
  }

  pattern_and_text[pattern_len] = '$';

  for (unsigned long long i = 0; i < text_len; ++i) {
    pattern_and_text[pattern_len + i + 1] = text[i];
  }

  prefix(total_len, pattern_and_text, prefix_array);

  unsigned long long result_count = 0;

  for (unsigned long long i = 0; i < total_len; ++i) {
    if (prefix_array[i] == pattern_len) {
      result_count++;
    }
  }

  *matches =
      (unsigned long long *)malloc(result_count * (sizeof(unsigned long long)));

  unsigned long long match_pointer = 0;
  for (unsigned long long i = 0; i < total_len; ++i) {
    if (prefix_array[i] == pattern_len) {
      (*matches)[match_pointer] = (i - (2 * pattern_len));
      match_pointer++;
    }
  }
  return result_count;
}

unsigned long long read_line(char a[]) {
  unsigned char c;
  unsigned long long len = 0;

  while ((c = getc(stdin)) != '\n') {
    a[len] = c;
    len++;
  }

  a[len + 1] = '\0';
  return len;
}

void print_line_array(unsigned long long len, unsigned long long a[len]) {
  if (len < 1) {
    return;
  }

  for (unsigned long long i = 0; i < (len - 1); ++i) {
    printf("%lld ", a[i]);
  }
  printf("%lld\n", a[len - 1]);
}

int main() {
  unsigned long long max_len = MAX_LEN;
  char text[max_len];
  unsigned long long text_len;

  char pattern[max_len];
  unsigned long long pattern_len;

  pattern_len = read_line(pattern);
  text_len = read_line(text);

  unsigned long long *matches = NULL;
  unsigned long long total_matches =
      find_pattern(pattern_len, pattern, text_len, text, &matches);

  print_line_array(total_matches, matches);
}
