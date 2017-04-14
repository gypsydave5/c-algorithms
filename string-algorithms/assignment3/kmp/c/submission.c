#include <stdio.h>
#include <stdlib.h>

void prefix(int len, char text[len], int prefix_array[len]) {
  int border = 0;
  prefix_array[0] = 0;

  for (int i = 1; i < len; ++i) {
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

  *matches = (int *)malloc(result_count * (sizeof(int)));

  int match_pointer = 0;
  for (int i = 0; i < total_len; ++i) {
    if (prefix_array[i] == pattern_len) {
      (*matches)[match_pointer] = (i - (2 * pattern_len));
      match_pointer++;
    }
  }
  return result_count;
}

int read_line(char a[]) {
  unsigned char c;
  int len = 0;

  while ((c = getc(stdin)) != '\n') {
    a[len] = c;
    len++;
  }

  a[len + 1] = '\0';
  return len;
}

void print_line_array(int len, int a[len]) {
  if (len < 1) {
    return;
  }

  for (int i = 0; i < (len - 1); ++i) {
    printf("%d ", a[i]);
  }
  printf("%d\n", a[len - 1]);
}

int main() {
  int max_len = 1000001;
  char text[max_len];
  int text_len;

  char pattern[max_len];
  int pattern_len;

  pattern_len = read_line(pattern);
  text_len = read_line(text);

  int *matches = NULL;
  int total_matches =
      find_pattern(pattern_len, pattern, text_len, text, &matches);

  print_line_array(total_matches, matches);
}
