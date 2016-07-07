#include <stdio.h>
#include "hash-function.h"

int main() {
  char word[16];
  unsigned long long mod, result;
  scanf("%s %lld\n", word, &mod);
  result = hash_function(mod, word);
  printf("%lld\n", result);
}