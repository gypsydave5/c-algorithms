#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kmp.h"

int MAX_LEN = 1000000;
int ALPHABET_LEN = 4;
char ALPHABET[] = "ATCG";

void fill(int len, char a[len]) {
  for (int i = 0; i < len; ++i) {
    int index = rand() % ALPHABET_LEN;
    char c = ALPHABET[index];
    a[i] = c;
  }
}

int main() {
  srand(time(NULL));
  printf("!");
  while (1) {
    int pattern_len = rand() % MAX_LEN;
    int text_len = rand() % MAX_LEN;
    char pattern[pattern_len];
    char text[text_len];

    fill(pattern_len, pattern);
    fill(text_len, text);

    int *matches = NULL;
    find_pattern(pattern_len, pattern, text_len, text, &matches);
    printf(".");
  }
}
